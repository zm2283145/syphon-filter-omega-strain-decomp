#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_00572188;

void StaticInit_ActivateMsg(void) {
    D_00572188 = "MSGLIB_NET_ACTIVATE_REQUEST";
}
