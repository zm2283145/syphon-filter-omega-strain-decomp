#pragma cplusplus on
#pragma opt_propagation off
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"

typedef struct { __int128 r[4]; } Mtx;

extern "C" {
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
void AnimChannel_SetDirect(void* ch, int mode, float value);
}

typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad25[0xB]; Mtx m; } Msg;
struct Anim { char pad[0x10]; char ch[0x10]; };

extern "C" void Event_Construct(Msg* msg, void* name);
extern "C" void Event_Send(Msg* msg, void* target, int flags);
extern "C" void cMessage_dtor(Msg* msg, int flags);
static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void Ev(char* t, Mtx* mt)
{
    Msg e;
    Msg* pe = &e;
    Event_Construct(pe, g_TeleportMsgClass);
    pe->vtable = D_004D9360;
    pe->kind = 2;
    Q4(&pe->m, mt);
    Event_Send(&e, t, 1);
    e.vtable = D_004D9360;
    cMessage_dtor(&e, 0);
}
extern "C" void Actor_RequestTeleport(char* self, Mtx* m)
{
    Anim* an = (Anim*)(self + 0x2EC0);
    AnimChannel_SetDirect(an->ch, 4, 0.0f);
    Ev(self, m);

}


