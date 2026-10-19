#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_005839A0;

void StaticInit_NetLevelInfoMsgName(void) {
    D_005839A0 = "NetLevelInfoMsg";
}
