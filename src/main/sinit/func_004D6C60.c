#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
extern char *g_cDisableMsgClass;
extern int D_0055D4A8;
extern int D_0055D4B0;
extern char cDisableMsg_SOBJ_init;

void StaticInit_DisableMsg(void) {
    g_cDisableMsgClass = "MSGLIB_NET_DISABLE_REQUEST";
    D_0055D4A8 = cScriptBase_addClass("cDisableMsg", &cDisableMsg_SOBJ_init, 1, 0);
    D_0055D4B0 = D_0055D4A8;
}
