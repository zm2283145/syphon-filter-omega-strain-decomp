#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_00582680;

void func_004D7480(void) {
    D_00582680 = "MSGGAME_NET_ACTIVATEANDCONTROL_REQUEST";
}
