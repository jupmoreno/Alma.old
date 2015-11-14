#ifndef _SYS_CALLS_H_
#define _SYS_CALLS_H_

// TODO: Necesarios?
#include <systime.h>
#include <sysio.h>
#include <sysscreen.h>

enum syscalls_call {
	SYSTEM_CALL_READ = 0,
	SYSTEM_CALL_WRITE = 1,
	SYSTEM_CALL_TERMINAL_CLEAR = 2,
	SYSTEM_CALL_TERMINAL_SET = 3,
	SYSTEM_CALL_TERMINAL_COLOR = 4,
	SYSTEM_CALL_TIME_READ = 5,
	SYSTEM_CALL_TIME_WRITE = 6,
	SYSTEM_CALL_SCREENSAVER_ENABLE = 7,
	SYSTEM_CALL_SCREENSAVER_TIME = 8,
	SYSTEM_CALL_SCREENSAVER = 9
};

#endif