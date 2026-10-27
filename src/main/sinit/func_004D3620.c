#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0051F0C0;

void StaticInit_NetPathMsg(void) {
    D_0051F0C0 = "MSGGAME_NET_PATH_REQUEST";
}
