#ifndef _SYS_SCREEN_H_
#define _SYS_SCREEN_H_

#include <sys_video.h>

#define _OUTPUT_ERROR_TERMINAL_INVALID -1
#define _OUTPUT_ERROR_SLEEP_ACTIVE -2
#define _OUTPUT_ERROR_SLEEP_NOT_ACTIVE -3
#define _OUTPUT_ERROR_SLEEP_TIME -4
#define _SYSCALL_ERROR_SCREEN_OPERATION_INVALID -5

enum terminal_color_ops {
	_TERMINAL_COLOR_OPERATION_TEXT = 0,
	_TERMINAL_COLOR_OPERATION_BG,
	_TERMINAL_COLOR_OPERATION_STYLE,
};

#endif
