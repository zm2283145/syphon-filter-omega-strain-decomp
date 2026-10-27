#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0051F0A8;

void StaticInit_NetNPCMsgs(void) {
    D_0051F0A8 = "NET_NPCMSGS_REQUEST";
}
