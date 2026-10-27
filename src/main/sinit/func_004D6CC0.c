#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
extern char *g_cEnableMsgClass;
extern int D_0055D4C8;
extern int D_0055D4D0;
extern char cEnableMsg_SOBJ_init;

void StaticInit_EnableMsg(void) {
    g_cEnableMsgClass = "MSGLIB_NET_DISABLE_REQUEST";
    D_0055D4C8 = cScriptBase_addClass("cEnableMsg", &cEnableMsg_SOBJ_init, 1, 0);
    D_0055D4D0 = D_0055D4C8;
}
