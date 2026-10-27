#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cNetMsg_RegisterMsg(char *, char *, char *);                   
extern char *D_00504050;
extern char D_00504058;
extern int D_00504060;
extern char cNetTaserMsg_NetReceive;

void StaticInit_netTaserMsg(void) {
    D_00504050 = "cNetTaserMsg";
    D_00504060 = cNetMsg_RegisterMsg(&cNetTaserMsg_NetReceive, &D_00504058, "cNetTaserMsg");
}
