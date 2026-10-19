#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsgTable_Add(char *, char *, char *);                   
extern char *D_00504050;
extern char D_00504058;
extern int D_00504060;
extern char cNetTaserMsg_NetReceive;

void StaticInit_NetTaserMsgType(void) {
    D_00504050 = "cNetTaserMsg";
    D_00504060 = NetMsgTable_Add(&cNetTaserMsg_NetReceive, &D_00504058, "cNetTaserMsg");
}
