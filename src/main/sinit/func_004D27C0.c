#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsgTable_Add(char *, char *, char *);                   
extern char *D_005061B0;
extern char D_005061B8;
extern int D_005061C0;
extern char cNetBackpackMsg_NetReceive;

void StaticInit_NetBackpackMsgType(void) {
    D_005061B0 = "cNetBackpackMsg";
    D_005061C0 = NetMsgTable_Add(&cNetBackpackMsg_NetReceive, &D_005061B8, "cNetBackpackMsg");
}
