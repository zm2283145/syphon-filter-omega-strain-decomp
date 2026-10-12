#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
extern char *g_cDisableMsgClass;
extern int D_0055D4A8;
extern int D_0055D4B0;
extern char ScriptType_cDisableMsg_Init;

void func_004D6C60(void) {
    g_cDisableMsgClass = "MSGLIB_NET_DISABLE_REQUEST";
    D_0055D4A8 = Script_RegisterType("cDisableMsg", &ScriptType_cDisableMsg_Init, 1, 0);
    D_0055D4B0 = D_0055D4A8;
}
