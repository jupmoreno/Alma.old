// Modified version of: http://wiki.osdev.org/CMOS#Writing_to_the_CMOS
#include <rtc.h>
#include <cmos.h>

#define BINARY_TO_BCD(x)        ((((x) / 10) << 4) + ((x) % 10))
#define BCD_TO_BINARY(x)       ((x) & 0x0F) + (((x) / 16) * 10)
#define HOUR_REMOVE_PM_INFORMATION(x)    ((x) & 0x7F)
#define HOUR_ADD_PM_INFORMATION(x,pm)     ((x) | (pm))
#define HOUR_TO_24_FORMAT(x)              (((x)+12) % 24)
#define FULL_YEAR(x,y)                    ((x)+(y)*100)
 
uint8_t second;
uint8_t minute;
uint8_t hour;
uint8_t day;
uint8_t month;
uint16_t year;
uint8_t century;
uint8_t centuryChange = FALSE;

/**
 * @return 1 if the RTC is currently updating. 0 otherwise.
 */
static int isUpdating() ; 

/**
 * Validates if the given RTC_time structure contains valid data.
 * @param  t            the RTC_time structure to validate
 * @return              OK if the structure is valid.
 *                      INVALID_TIME otherwise.
 */
static uint64_t validateTime(RTC_time* t);

/**
 * @param  year               the year to be tested. 
 * @return                    1 if the year is leap.
 *                            0 otherwise.
 */
static int isLeap(int year);

static int isUpdating() 
{
      int statusRegisterA;
      statusRegisterA = _read_CMOS(STATUS_REGISTER_A);
      return statusRegisterA & UPDATE_IN_PROGRESS_MASK;
}

static uint64_t validateTime(RTC_time* t)
{
      static int days[][13]= 
      {
            {0,31,28,31,30,31,30,31,31,30,31,30,31},
            {0,31,29,31,30,31,30,31,31,30,31,30,31}
      };
      int leap, maxDays;

      if (  t->second >= 60 || t->minute >= 60 || t-> hour >= 24)
            return INVALID_TIME;

      if (t->day >=32 || t->day == 0|| t->month >= 13 || t->month == 0)
            return INVALID_TIME;

      leap = isLeap(t->year);
      maxDays = days[leap][t->month];
      
      if (t->day > maxDays)
            return INVALID_TIME;
      
      return OK;
}


static int isLeap(int year)
{
      if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))
            return 1;
      return 0;
}


uint64_t readRTC(RTC_time* t) 
{
      uint8_t lastSecond;
      uint8_t lastMinute;
      uint8_t lastHour;
      uint8_t lastDay;
      uint8_t lastMonth;
      uint8_t lastYear;
      uint8_t lastCentury;
      uint8_t registerB;
      uint8_t binaryMode;
      uint8_t hours24Mode;
      uint8_t hourPM;

      // Note: This uses the "read registers until you get the same values
      // twice in a row" technique to avoid getting dodgy/inconsistent
      // values due to RTC updates
      while (isUpdating()); // Makes sure an update isn't in progress

      second = _read_CMOS(SECONDS);
      minute = _read_CMOS(MINUTES);
      hour = _read_CMOS(HOURS);
      day = _read_CMOS(DAY);
      month = _read_CMOS(MONTH);
      year = _read_CMOS(YEAR);
 
      do 
      {
            lastSecond = second;
            lastMinute = minute;
            lastHour = hour;
            lastDay = day;
            lastMonth = month;
            lastYear = year;
            lastCentury = century;
 
            while (isUpdating()); // Makes sure an update isn't in progress

            second = _read_CMOS(SECONDS);
            minute = _read_CMOS(MINUTES);
            hour = _read_CMOS(HOURS);
            day = _read_CMOS(DAY);
            month = _read_CMOS(MONTH);
            year = _read_CMOS(YEAR);
            century = _read_CMOS(CENTURY);
      } while(    (lastSecond != second) || (lastMinute != minute) 
                  || (lastHour != hour) || (lastDay != day) 
                  || (lastMonth != month) || (lastYear != year) 
                  || (lastCentury != century) );
 
      registerB = _read_CMOS(STATUS_REGISTER_B);
      binaryMode = registerB & BINARY_MODE_MASK;

      hourPM = hour & HOUR_PM;
      // Converts BCD to binary values if necessary
      if (!binaryMode) // bcdMode = TRUE
      {
            second = BCD_TO_BINARY(second);
            minute = BCD_TO_BINARY(minute);
            hour = HOUR_REMOVE_PM_INFORMATION(hour);
            hour = BCD_TO_BINARY(hour);
            hour = HOUR_ADD_PM_INFORMATION(hour, hourPM);
            day = BCD_TO_BINARY(day);
            month = BCD_TO_BINARY(month);
            year = BCD_TO_BINARY(year);
            century = BCD_TO_BINARY(century);
      }
 
      // Converts 12 hour clock to 24 hour clock if necessary
      hours24Mode = registerB & HOUR_24_MODE_MASK;
      if (!(hours24Mode) && hourPM) {
            hour = HOUR_REMOVE_PM_INFORMATION(hour);
            hour = HOUR_TO_24_FORMAT(hour);
      }

      // Century adaptation: 
      // there virtual machines were the century updating works fine (qemu)
      // and some others where don't (VirtualBox).
      // This adaptation was made to work OK at VirtualBox.
      if (!centuryChange && year == 99)
      {
            centuryChange = TRUE;
      }
      else if (centuryChange && year == 00)
      {
            centuryChange = FALSE;
            century++;
            uint8_t aux = century;
            if (!binaryMode) // bcdMode = TRUE
            {
                  aux = BINARY_TO_BCD(aux);
            }
            _write_CMOS(CENTURY, aux);
      }

      // Calculates the full (4-digit) year
      year = FULL_YEAR(year,century);

      // Loads the time structure
      t->second = second;
      t->minute = minute;
      t->hour = hour;
      t->day = day;
      t->month = month;
      t->year = year;

      return OK;
}


uint64_t writeRTC(RTC_time* t)
{     
      uint8_t registerB;
      uint8_t binaryMode;
      uint8_t hours24Mode;

      int error = validateTime(t);
      if (error)
            return error;

      century = t->year/100;
      t->year -= (century*100);

      // Century adaptation: 
      // there virtual machines were the century updating works fine (qemu)
      // and some others where don't (VirtualBox).
      // This adaptation was made to work OK at VirtualBox.
      if (!centuryChange && t->year == 99)
      {
            centuryChange = TRUE;
      }
      else
      {
            centuryChange = FALSE;
      }

      registerB = _read_CMOS(STATUS_REGISTER_B);
      hours24Mode = registerB & HOUR_24_MODE_MASK;
      if (!hours24Mode)
      {
            if (t->hour > 12)
            {
                  t->hour -= 12;
            } 
            else if (t->hour == 0)
            {
                  t->hour = 12;
            } 
      }

      binaryMode = registerB & BINARY_MODE_MASK;
      if (!binaryMode) // bcdMode = TRUE
      {
            second = BINARY_TO_BCD(t->second);
            minute = BINARY_TO_BCD(t->minute);
            hour = BINARY_TO_BCD(t->hour);
            day = BINARY_TO_BCD(t->day);
            month = BINARY_TO_BCD(t->month);
            year = BINARY_TO_BCD(t->year);
            century = BINARY_TO_BCD(century);
      } 
      else 
      {
            second = t->second;
            minute = t->minute;
            hour = t->hour;
            day = t->day;
            month = t->month;
            year = t->year;
      }

      _write_CMOS(SECONDS, second);
      _write_CMOS(MINUTES, minute);
      _write_CMOS(HOURS, hour);
      _write_CMOS(DAY, day);
      _write_CMOS(MONTH, month);
      _write_CMOS(YEAR, year);
      _write_CMOS(CENTURY, century);

      return OK;
}
