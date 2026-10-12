#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_00572198;

void func_004D73B0(void) {
    D_00572198 = "MSGLIB_NET_DEACTIVATE_REQUEST";
}
