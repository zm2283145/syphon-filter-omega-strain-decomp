#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *g_ActorActionMsgClass;

void func_004D6C40(void) {
    g_ActorActionMsgClass = "CAS_ACTION";
}
