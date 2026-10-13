#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Sub { V4 v; float f40, f44; unsigned char b48; char p49[7]; } Sub;
typedef struct Packet { int kind, id; unsigned char a8, a9; char pad[2]; float x, y, z, w; float f1C, f20; unsigned char b24; } Packet;
typedef struct Msg { void* vt; char p4[0x20]; int a24; unsigned char a28; char p29[7]; Sub sub; char p50[0x10]; } Msg;
extern unsigned char D_005723C8, D_005721D0; extern char D_0055D480[], D_004E0840[], D_004E0120[];
extern "C" {
void cMessage_ctor5(Msg*, void*, Packet*); void** NetMap_Lookup(int); void MsgQueue_QueueClone(Msg*, void*, int, int); void cMessage_dtor(Msg*, int); }
static inline V4* V4_Set(V4* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; return v; }
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded address registers */
static inline void V4_Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Sub_Set(Sub* s, V4* v, float a, float b, bool f, V4* d) { V4_Copy(d, v); s->f40 = a; s->f44 = b; s->b48 = f ? 1 : 0; }
extern "C" int func_003E49B0(int a, int b, int c, Packet* p0) {
    Msg msg; V4 v;
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Packet* p = p0;
        void** obj;
        Msg* m = &msg;
        cMessage_ctor5(m, D_0055D480, p);
        m->vt = D_004E0840;
        m->a24 = p->a8;
        m->a28 = p->a9;
        { bool fl = p->b24 != 0; Sub* ps = &m->sub; Sub_Set(&m->sub, V4_Set(&v, p->x, p->y, p->z, p->w), p->f1C, p->f20, fl, &ps->v); }
        m->vt = D_004E0120;
        obj = NetMap_Lookup(p->id);
        if (obj) MsgQueue_QueueClone(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x28;
}








