#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0051F058;

void func_004D3580(void) {
    D_0051F058 = "MSGGAME_NET_GENERATORCREATE_REQUEST";
}
