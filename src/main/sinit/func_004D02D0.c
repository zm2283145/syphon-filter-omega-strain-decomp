#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_004F80B8;

void func_004D02D0(void) {
    D_004F80B8 = "MSGGAME_SWITCH_BODIES_REQUEST";
}
