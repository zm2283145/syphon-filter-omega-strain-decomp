#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0052ACF8;

void StaticInit_NetRemoveHudObjectiveMsg(void) {
    D_0052ACF8 = "NetRemoveHudObjectiveMsg";
}
