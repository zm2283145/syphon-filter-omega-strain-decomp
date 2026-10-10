#include "types.h"
typedef struct { char s[16]; } F1Name2D7;
typedef struct F1Data2D7 { int a; int id; signed char c; char pad9[3]; int d; int e; F1Name2D7 name; } F1Data2D7;
typedef struct F1Msg2D7 { void* vt; char base[0x20]; int a; int id; signed char c; char pad2D[3]; int d; int e; F1Name2D7 name; } F1Msg2D7;
typedef struct F1Ent2D7 { void* queue; } F1Ent2D7;
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
extern void Event_Construct(void* msg, void* name);
extern F1Ent2D7* NetMap_Lookup(int id);
extern void MsgQueue_QueueClone(void* msg, void* queue, int a, int b);
extern void cMessage_dtor(void* msg, int flags);
int ObjectiveNet_OnReceive(int a0, int a1, int a2, void* data)
{
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        F1Msg2D7 m;
        F1Ent2D7* e;
        F1Data2D7* d = (F1Data2D7*)data;
        Event_Construct(&m, D_0051F0B0);
        m.vt = D_004DE4F0;
        m.a = d->a;
        m.id = d->id;
        m.c = d->c;
        m.d = d->d;
        m.e = d->e;
        m.name = d->name;
        e = NetMap_Lookup(d->id);
        if (e) MsgQueue_QueueClone(&m, e->queue, 0, 0);
        m.vt = D_004DE4F0;
        cMessage_dtor(&m, 0);
    }
    D_005723C8 = 0;
    return 0x24;
}