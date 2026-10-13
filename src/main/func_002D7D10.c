#pragma cplusplus on
#include "types.h"
#include "cmessage.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Msg : CMsg { int a24; unsigned char a28; char p29[7]; };
struct Msg2 : Msg { int val; int id; unsigned char m38; char p39[7]; V4 v; float f50; char p54[0xC]; };
struct Info { unsigned char dead; char p1[7]; int val; signed char id; };
struct Obj { char p0[0x44]; Info* info; char p48[4]; void* target; };
extern "C" {
extern char D_0055D480[], D_004E0840[], D_004E0200[];
extern signed char D_004E1D88;
extern V4 D_004E1D90;
}
static inline const V4& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return D_004E1D90;
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void func_002D7D10(Obj* o)
{
    Info* in = o->info;
    if (in) {
        Msg2* m; int id = in->id;
        int val[1]; val[0] = in->dead ? -1 : in->val;
        Msg2 msg;
        m = &msg;
        Event_Construct(m, D_0055D480);
        m->vtable = D_004E0840;
        m->a24 = 0x3B;
        m->a28 = 0xB;
        m->vtable = D_004E0200;
        {
            const V4* z = &Zero();
            m->val = val[0];
            m->id = id;
            m->m38 = 0;
            V4_Copy(&m->v, z);
            m->f50 = 0.0f;
        }
        Event_Send(&msg, o->target, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}


