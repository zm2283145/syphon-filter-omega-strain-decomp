#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_004F82F0;

void func_004D0810(void) {
    D_004F82F0 = "cGameEventMsg";
}
