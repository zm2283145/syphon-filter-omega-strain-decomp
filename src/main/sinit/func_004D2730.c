#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsgTable_Add(char *, char *, char *);                   
extern char *D_00504068;
extern char D_00504070;
extern int D_00504078;
extern char cNetGrenadeMsg_NetReceive;

void StaticInit_NetGrenadeMsgType(void) {
    D_00504068 = "cNetGrenadeMsg";
    D_00504078 = NetMsgTable_Add(&cNetGrenadeMsg_NetReceive, &D_00504070, "cNetGrenadeMsg");
}
