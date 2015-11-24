#ifndef _LIB_STRINGS_H_
#define _LIB_STRINGS_H_

#define ERROR_NUMBER_NOT_POSITIVE -1

/**
 * Compares 2 null terminated strings
 * @param  s1 a string
 * @param  s2 a string
 * @return    >0 if s1 is bigger, 0 if equal, <0 if smaller
 */
int strcmp(const char * s1, const char * s2);

/**
 * Copys the source string into destination
 * @param dest   a string
 * @param source a string
 */
void strcpy(char * dest, const char * source);

/**
 * Converts a string into a number only if the number is possitive
 * @param  s   the string
 * @param  num the return value for the number
 * @return     the length of the number or <0 if error occurred
 */
int strint(char *s, unsigned int *num);

#endif