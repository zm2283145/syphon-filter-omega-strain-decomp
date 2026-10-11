#include "types.h"
typedef struct { void* vtable; char base[0x20]; int id; signed char b; char pad29[3]; } Msg_197380;
typedef struct { char pad[0x4C]; int classKey; } G_197380;
extern int D_0049D010;
extern char D_004EEEE8[];
extern char D_004DA8F0[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_197380* msg, void* name);
extern void cMessage_dtor(Msg_197380* msg, int flags);
extern void func_00282160(int* out);
extern void func_00196480(G_197380* g, int id, int b);
static inline void ReadS8_197380(signed char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
static inline void ReadI_197380(int* out) { int t; func_00282160(&t); *out = t; }
void func_00197380(G_197380* g)
{
    Msg_197380 msg;
    signed char* bp;
    int* ip;
    Event_Construct(&msg, D_004EEEE8);
    msg.vtable = D_004DA8F0;
    {
        int t;
        func_00282160(&t);
        bp = &msg.b;
        ip = &msg.id;
        ReadS8_197380(bp);
        *ip = t;
    }
    if (g && g->classKey == D_0049D010) func_00196480(g, *ip, *bp != 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
