#ifndef _KEYS_H_
#define _KEYS_H_

#define NUMPAD_FIRST 0x47
#define NUMPAD_LAST 0x53
#define KEY_ISNUMPAD(x) ((x) >= NUMPAD_FIRST && (x) <= NUMPAD_LAST)

#define SCANCODE_ALTGR 0x38
#define SCANCODE_CONTROL_LEFT 0x1D
#define SCANCODE_CONTROL_RIGTH // TODO: 
#define SCANCODE_ALT_LEFT 0x38
#define SCANCODE_ALT_RIGTH // TODO: 
#define SCANCODE_SHIFT_LEFT 0x2A
#define SCANCODE_SHIFT_RIGTH 0x36
#define SCANCODE_CAPSLOCK 0x3A
#define SCANCODE_NUMLOCK 0x45
#define SCANCODE_SCROLLLOCK 0x46
#define SCANCODE_TAB 0x0F
#define SCANCODE_EXTENDED 0xE0
#define SCANCODE_PRESS_MAX 0x80

#define KEYS_PRESSABLES 4
enum keys_pressables {
	CONTROL = 0,
	SHIFT,
	ALT,
	ALTGR
};

#define KEYS_ONOFF 3
enum keys_onoff {
	CAPSLOCK = 0,
	NUMLOCK,
	SCROLLLOCK
};

#define KEYBOARDS			2
#define KEY_ENTRIES 		91
#define KEY_ALTERNATIVES 	3

static unsigned char keys[KEYBOARDS][KEY_ENTRIES][KEY_ALTERNATIVES] = {
		// SPANISH_KEYBOARD
	{
		{ _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*000*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*001 ESCAPE*/
	    { '1', '!', _KEY_NOTPRINTABLE }, /*002*/
	    { '2', '\"', '@' }, /*003*/
	    { '3', '#', _KEY_NOTPRINTABLE }, /*004*/
	    { '4', '$', _KEY_NOTPRINTABLE }, /*005*/
	    { '5', '%', _KEY_NOTPRINTABLE }, /*006*/
	    { '6', '&', _KEY_NOTPRINTABLE }, /*007*/
	    { '7', '/', _KEY_NOTPRINTABLE }, /*008*/
	    { '8', '(', _KEY_NOTPRINTABLE }, /*009*/
	    { '9', ')', _KEY_NOTPRINTABLE }, /*010*/
	    { '0', '=', _KEY_NOTPRINTABLE }, /*011*/
	    { '\'', '?', _KEY_NOTPRINTABLE }, /*012*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*013*/
	    { '\b', '\b', _KEY_NOTPRINTABLE }, /*014 BACKSPACE*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*015 TAB*/
	    { 'q', 'Q', _KEY_NOTPRINTABLE }, /*016*/
	    { 'w', 'W', _KEY_NOTPRINTABLE }, /*017*/
	    { 'e', 'E', _KEY_NOTPRINTABLE }, /*018*/
	    { 'r', 'R', _KEY_NOTPRINTABLE }, /*019*/
	    { 't', 'T', _KEY_NOTPRINTABLE }, /*020*/
	    { 'y', 'Y', _KEY_NOTPRINTABLE }, /*021*/
	    { 'u', 'U', _KEY_NOTPRINTABLE }, /*022*/
	    { 'i', 'I', _KEY_NOTPRINTABLE }, /*023*/
	    { 'o', 'O', _KEY_NOTPRINTABLE }, /*024*/
	    { 'p', 'P', _KEY_NOTPRINTABLE }, /*025*/
	    { '`', '^', _KEY_NOTPRINTABLE }, /*026*/
	    { '+', '*', _KEY_NOTPRINTABLE }, /*027*/
	    { '\n', '\n', '\n' }, /*028*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*029 CTRL IZQ*/
	    { 'a', 'A', _KEY_NOTPRINTABLE }, /*030*/
	    { 's', 'S', _KEY_NOTPRINTABLE }, /*031*/
	    { 'd', 'D', _KEY_NOTPRINTABLE }, /*032*/
	    { 'f', 'F', _KEY_NOTPRINTABLE }, /*033*/
	    { 'g', 'G', _KEY_NOTPRINTABLE }, /*034*/
	    { 'h', 'H', _KEY_NOTPRINTABLE }, /*035*/
	    { 'j', 'J', _KEY_NOTPRINTABLE }, /*036*/
	    { 'k', 'K', _KEY_NOTPRINTABLE }, /*037*/
	    { 'l', 'L', _KEY_NOTPRINTABLE }, /*038*/
	    { ':', ';', _KEY_NOTPRINTABLE }, /*039*/
	    { '{', '[', _KEY_NOTPRINTABLE }, /*040*/
	    { '\\', '\\', _KEY_NOTPRINTABLE }, /*041*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*042 SHIFT IZQ*/
	    { '}', ']', _KEY_NOTPRINTABLE }, /*043*/
	    { 'z', 'Z', _KEY_NOTPRINTABLE }, /*044*/
	    { 'x', 'X', _KEY_NOTPRINTABLE }, /*045*/
	    { 'c', 'C', _KEY_NOTPRINTABLE }, /*046*/
	    { 'v', 'V', _KEY_NOTPRINTABLE }, /*047*/
	    { 'b', 'B', _KEY_NOTPRINTABLE }, /*048*/
	    { 'n', 'N', _KEY_NOTPRINTABLE }, /*049*/
	    { 'm', 'M', _KEY_NOTPRINTABLE }, /*050*/
	    { ',', ';', _KEY_NOTPRINTABLE }, /*051*/
	    { '.', ':', _KEY_NOTPRINTABLE }, /*052*/
	    { '-', '_', '/' }, /*053*/ /* / */
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*054 SHIFT DER*/
	    { '*', '*', _KEY_NOTPRINTABLE}, /*055 KEY **/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*056 ALT IZQ*//* ALT DER*/
	    { ' ', ' ', _KEY_NOTPRINTABLE }, /*057 SPACE*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*058 CAPSLOCK*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*059 F1*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*060 F2*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*061 F3*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*062 F4*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*063 F5*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*064 F6*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*065 F7*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*066 F8*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*067 F9*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*068 F10*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*069 NUM LOCK*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*070 SCROLL LOCK*/
	    { _KEY_NOTPRINTABLE, '7', _KEY_NOTPRINTABLE }, /*071 KEY 7*/ /* inicio */
	    { _KEY_NOTPRINTABLE, '8', _KEY_NOTPRINTABLE },/*072 KEY 8*//* flecha para arriba */
	    { _KEY_NOTPRINTABLE, '9', _KEY_NOTPRINTABLE }, /*073 KEY 9*/ /* repag */
	    { '-', '-' , _KEY_NOTPRINTABLE}, /*074 KEY -*/
	    { _KEY_NOTPRINTABLE, '4', _KEY_NOTPRINTABLE },/*075 KEY 4*//* flecha para la izq */
	    { _KEY_NOTPRINTABLE, '5', _KEY_NOTPRINTABLE }, /*076 KEY 5*/
	    { _KEY_NOTPRINTABLE, '6', _KEY_NOTPRINTABLE },/*077 KEY 6*//* flecha para la der */
	    { '+', '+', _KEY_NOTPRINTABLE }, /*078 KEY +*/
	    { _KEY_NOTPRINTABLE, '1', _KEY_NOTPRINTABLE }, /*079 KEY 1*/ /* fin */
	    { _KEY_NOTPRINTABLE, '2', _KEY_NOTPRINTABLE }, /*080 KEY 2*/ /* flecha para abajo */
	    { _KEY_NOTPRINTABLE, '3', _KEY_NOTPRINTABLE }, /*081 KEY 3*/ /* avpag */
	    { _KEY_NOTPRINTABLE, '0', _KEY_NOTPRINTABLE }, /*082 KEY 0*/ /* insert */
	    { _KEY_NOTPRINTABLE, '.', _KEY_NOTPRINTABLE }, /*083 KEY .*/ /* supr */
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*084 SYS REQ (AT)*/
	    { '+', '*', _KEY_NOTPRINTABLE }, /*085*/
	    { '<', '>', _KEY_NOTPRINTABLE }, /*086*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*087 F11*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*088 F12*/
	    { '+', '*', _KEY_NOTPRINTABLE }, /*089*/
	    { '+', '*', _KEY_NOTPRINTABLE } /*090*/
	}, 
		// ENGLISH_KEYBOARD
	{
		{ _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*000*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*001 ESCAPE*/
	    { '1', '!', _KEY_NOTPRINTABLE }, /*002*/
	    { '2', '@', _KEY_NOTPRINTABLE }, /*003*/
	    { '3', '#', _KEY_NOTPRINTABLE }, /*004*/
	    { '4', '$', _KEY_NOTPRINTABLE }, /*005*/
	    { '5', '%', _KEY_NOTPRINTABLE }, /*006*/
	    { '6', '^', _KEY_NOTPRINTABLE }, /*007*/
	    { '7', '&', _KEY_NOTPRINTABLE }, /*008*/
	    { '8', '*', _KEY_NOTPRINTABLE }, /*009*/
	    { '9', '(', _KEY_NOTPRINTABLE }, /*010*/
	    { '0', ')', _KEY_NOTPRINTABLE }, /*011*/
	    { '-', '_', _KEY_NOTPRINTABLE }, /*012*/
	    { '=', '+', _KEY_NOTPRINTABLE }, /*013*/
	    { '\b', '\b', _KEY_NOTPRINTABLE }, /*014 BACKSPACE*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*015 TAB*/
	    { 'q', 'Q', _KEY_NOTPRINTABLE }, /*016*/
	    { 'w', 'W', _KEY_NOTPRINTABLE }, /*017*/
	    { 'e', 'E', _KEY_NOTPRINTABLE }, /*018*/
	    { 'r', 'R', _KEY_NOTPRINTABLE }, /*019*/
	    { 't', 'T', _KEY_NOTPRINTABLE }, /*020*/
	    { 'y', 'Y', _KEY_NOTPRINTABLE }, /*021*/
	    { 'u', 'U', _KEY_NOTPRINTABLE }, /*022*/
	    { 'i', 'I', _KEY_NOTPRINTABLE }, /*023*/
	    { 'o', 'O', _KEY_NOTPRINTABLE }, /*024*/
	    { 'p', 'P', _KEY_NOTPRINTABLE }, /*025*/
	    { '[', '{', _KEY_NOTPRINTABLE }, /*026*/
	    { ']', '}', _KEY_NOTPRINTABLE }, /*027*/
	    { '\n', '\n', '\n' }, /*028*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*029 CTRL IZQ*/
	    { 'a', 'A', _KEY_NOTPRINTABLE }, /*030*/
	    { 's', 'S', _KEY_NOTPRINTABLE }, /*031*/
	    { 'd', 'D', _KEY_NOTPRINTABLE }, /*032*/
	    { 'f', 'F', _KEY_NOTPRINTABLE }, /*033*/
	    { 'g', 'G', _KEY_NOTPRINTABLE }, /*034*/
	    { 'h', 'H', _KEY_NOTPRINTABLE }, /*035*/
	    { 'j', 'J', _KEY_NOTPRINTABLE }, /*036*/
	    { 'k', 'K', _KEY_NOTPRINTABLE }, /*037*/
	    { 'l', 'L', _KEY_NOTPRINTABLE }, /*038*/
	    { ';', ':', _KEY_NOTPRINTABLE }, /*039*/
	    { '\'', '\"', _KEY_NOTPRINTABLE }, /*040*/
	    { '`', '~', _KEY_NOTPRINTABLE }, /*041*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*042 SHIFT IZQ*/
	    { '\\', '|', _KEY_NOTPRINTABLE }, /*043*/
	    { 'z', 'Z', _KEY_NOTPRINTABLE }, /*044*/
	    { 'x', 'X', _KEY_NOTPRINTABLE }, /*045*/
	    { 'c', 'C', _KEY_NOTPRINTABLE }, /*046*/
	    { 'v', 'V', _KEY_NOTPRINTABLE }, /*047*/
	    { 'b', 'B', _KEY_NOTPRINTABLE }, /*048*/
	    { 'n', 'N', _KEY_NOTPRINTABLE }, /*049*/
	    { 'm', 'M', _KEY_NOTPRINTABLE }, /*050*/
	    { ',', '<', _KEY_NOTPRINTABLE }, /*051*/
	    { '.', '>', _KEY_NOTPRINTABLE }, /*052*/
	    { '/', '?', '/' }, /*053*/ /* / */
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*054 SHIFT DER*/
	    { '*', '*', _KEY_NOTPRINTABLE}, /*055 KEY **/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*056 ALT IZQ*//* ALT DER*/
	    { ' ', ' ', _KEY_NOTPRINTABLE }, /*057 SPACE*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*058 CAPSLOCK*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*059 F1*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*060 F2*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*061 F3*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*062 F4*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*063 F5*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*064 F6*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*065 F7*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*066 F8*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*067 F9*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*068 F10*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*069 NUM LOCK*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE }, /*070 SCROLL LOCK*/
	    { _KEY_NOTPRINTABLE, '7', _KEY_NOTPRINTABLE }, /*071 KEY 7*/ /* inicio */
	    { _KEY_NOTPRINTABLE, '8', _KEY_NOTPRINTABLE },/*072 KEY 8*//* flecha para arriba */
	    { _KEY_NOTPRINTABLE, '9', _KEY_NOTPRINTABLE }, /*073 KEY 9*/ /* repag */
	    { '-', '-' , _KEY_NOTPRINTABLE}, /*074 KEY -*/
	    { _KEY_NOTPRINTABLE, '4', _KEY_NOTPRINTABLE },/*075 KEY 4*//* flecha para la izq */
	    { _KEY_NOTPRINTABLE, '5', _KEY_NOTPRINTABLE }, /*076 KEY 5*/
	    { _KEY_NOTPRINTABLE, '6', _KEY_NOTPRINTABLE },/*077 KEY 6*//* flecha para la der */
	    { '+', '+', _KEY_NOTPRINTABLE }, /*078 KEY +*/
	    { _KEY_NOTPRINTABLE, '1', _KEY_NOTPRINTABLE }, /*079 KEY 1*/ /* fin */
	    { _KEY_NOTPRINTABLE, '2', _KEY_NOTPRINTABLE }, /*080 KEY 2*/ /* flecha para abajo */
	    { _KEY_NOTPRINTABLE, '3', _KEY_NOTPRINTABLE }, /*081 KEY 3*/ /* avpag */
	    { _KEY_NOTPRINTABLE, '0', _KEY_NOTPRINTABLE }, /*082 KEY 0*/ /* insert */
	    { _KEY_NOTPRINTABLE, '.', _KEY_NOTPRINTABLE }, /*083 KEY .*/ /* supr */
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*084 SYS REQ (AT)*/
	    { '+', '*', _KEY_NOTPRINTABLE }, /*085*/
	    { '\\', '|', _KEY_NOTPRINTABLE }, /*086*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*087 F11*/
	    { _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE, _KEY_NOTPRINTABLE },/*088 F12*/
	    { '+', '*', _KEY_NOTPRINTABLE }, /*089*/
	    { '+', '*', _KEY_NOTPRINTABLE } /*090*/
	}
};

#endif