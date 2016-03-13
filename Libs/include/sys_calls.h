#ifndef _SYS_CALLS_H_
#define _SYS_CALLS_H_

enum syscall_triggers {
	_SYSCALL_READ = 0,
	_SYSCALL_WRITE,
	_SYSCALL_TIME,
	_SYSCALL_TERMINAL_SELECT,
	_SYSCALL_TERMINAL_COLOR,
	_SYSCALL_TERMINAL_CURSOR
};

#endif