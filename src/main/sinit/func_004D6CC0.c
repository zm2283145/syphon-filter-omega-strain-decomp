#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
extern char *g_cEnableMsgClass;
extern int D_0055D4C8;
extern int D_0055D4D0;
extern char ScriptType_cEnableMsg_Init;

void func_004D6CC0(void) {
    g_cEnableMsgClass = "MSGLIB_NET_DISABLE_REQUEST";
    D_0055D4C8 = Script_RegisterType("cEnableMsg", &ScriptType_cEnableMsg_Init, 1, 0);
    D_0055D4D0 = D_0055D4C8;
}
