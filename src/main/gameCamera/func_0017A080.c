#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[3]; char m24[0xC]; } Ev_A080;
extern char D_004EE930[];
extern char D_004DA310[];
extern char D_004DCF10[];
void Event_Construct(Ev_A080* e, void* type);
void NetStream_ReadObject(void* p);
void Event_Send(Ev_A080* e, void* target, int a);
void cMessage_dtor(Ev_A080* e, int f);
void cHumanSeenMsg_NetReceive(void* target)
{
    Ev_A080 e;
    Event_Construct(&e, D_004EE930);
    e.vt = D_004DA310;
    NetStream_ReadObject(e.m24);
    e.flag = 1;
    if (target)
        Event_Send(&e, target, 0);
    e.vt = D_004DCF10;
    cMessage_dtor(&e, 0);
}