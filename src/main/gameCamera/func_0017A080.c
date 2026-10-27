#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[3]; char m24[0xC]; } Ev_A080;
extern char D_004EE930[];
extern char D_004DA310[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(Ev_A080* e, void* type);
void cNetMsg_GetGOBJ(void* p);
void QueueMessage_cMessageR_cSystemP_int(Ev_A080* e, void* target, int a);
void cMessage_dtor(Ev_A080* e, int f);
void cHumanSeenMsg_NetReceive(void* target)
{
    Ev_A080 e;
    cMessage_ctor_cMessageNameR(&e, D_004EE930);
    e.vt = D_004DA310;
    cNetMsg_GetGOBJ(e.m24);
    e.flag = 1;
    if (target)
        QueueMessage_cMessageR_cSystemP_int(&e, target, 0);
    e.vt = D_004DCF10;
    cMessage_dtor(&e, 0);
}