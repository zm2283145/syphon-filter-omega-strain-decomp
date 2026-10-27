#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *g_ActorActionMsgClass;

void StaticInit_charActionMsg(void) {
    g_ActorActionMsgClass = "CAS_ACTION";
}
