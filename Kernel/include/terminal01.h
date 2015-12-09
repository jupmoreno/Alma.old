#ifndef _TERMINAL_H_NEW
#define _TERMINAL_H_NEW // TODO: Change

#include <define.h>
#include <video01.h> // TODO: Va a tener que estar aca hasta que pueda alocar memoria para hacer terminal_new()

typedef struct {
	unsigned int cursor;
	int cursor_shown;
	tSysVideoCursorShape cursor_shape; // TODO: Change tSysVideoCursorShape name
	style_st style;
	screen_st screen;
} terminal_st;

void terminal_init(terminal_st * terminal);
void terminal_show(terminal_st * terminal);
void terminal_hide();

int terminal_printf(terminal_st * terminal, char * fmt, ...);

void terminal_shift(terminal_st * terminal, int lines);
void terminal_delete(terminal_st * terminal);

#endif