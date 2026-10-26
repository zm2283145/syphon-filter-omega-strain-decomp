#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; register __int128 q; asm volatile { lq q, 0x0(s)
 sq q, 0x0(d) } return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
};
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
struct Ctl;
struct Tgt;
struct HeldItem {
    void* owner;
    Ctl* ctl;
    char p8[0x34 - 0x8];
    unsigned char b34; char p35[3];
    char p38[0x60 - 0x38];
    M m60;
};
extern "C" {
extern void Event_Construct(void* msg, void* name);
extern void Event_Send(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void* Actor_GetSkeleton(Tgt* t);
extern void Model_GetComponentTransform(M* out, void* skel, signed char code);
extern void Mtx_Transpose3x3(M* m);
extern int Mtx_IsTranslationZero(M* m);
extern V* func_00133EC0(M* m);
extern V* Vec4_Assign(V* d, V* s);
extern void Vec3_Negate(V* v);
extern void Mtx_TransformByTranspose(V* v, M* m);
extern void Mtx_SetTranslation(M* m, V* v);
extern void World_PushObject(void* w, Tgt* t, Ctl* c);
extern void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* h, Tgt* t, int part, V pos);
extern unsigned char g_IsMultiplayer;
extern signed char ActorNodeCodeTable[];
extern char g_Game[];
extern char g_ActorActionMsgClass[];
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern char D_004E01E0[];
extern char D_004E0840[];
extern int D_0048B1D0;
void cAirTaser_BeginShocking_cHumanP_int(HeldItem* h, Tgt* t, int part);
}
static inline void InvertRigid(M* m)
{
    Mtx_Transpose3x3(m);
    if (!Mtx_IsTranslationZero(m)) {
        V t;
        Vec4_Assign(&t, func_00133EC0(m));
        Vec3_Negate(&t);
        Mtx_TransformByTranspose(&t, m);
        Mtx_SetTranslation(m, &t);
    }
}

struct StateMsg {
    void* vt;
    char pad4[0x24 - 0x4];
    int state;
    char sub;
    char pad29[3];
    int stamp;
};
struct TaserMsg {
    void* vt;
    char pad4[0x1C - 0x4];
    int i1C;
    char b20;
    char pad21[3];
    char b24;
    char pad25[3];
    Tgt* tgt;
    int part;
    char pad30[0x10];
    V pos;
};
static inline void StateMsg_Init(StateMsg* p, int st, char sb)
{
    Event_Construct(p, g_ActorActionMsgClass);
    p->vt = D_004E0840;
    p->state = st;
    p->sub = sb;
    p->vt = D_004E01E0;
    p->stamp = D_0048B1D0;
}
static inline void TaserMsg_Init(TaserMsg* p, Tgt* t, int part, V v)
{
    Event_Construct(p, D_00504050);
    p->vt = D_004DCF10;
    p->vt = D_004DCDA0;
    p->b24 = 1;
    p->tgt = t;
    p->part = part;
    p->pos = v;
}
void cAirTaser_BeginShocking_cHumanP_int(HeldItem* h, Tgt* t, int part)
{
    V pos;
    M m;
    TaserMsg tm;
    StateMsg sm;
    if (part > -1) {
        Model_GetComponentTransform(&m, Actor_GetSkeleton(t), ActorNodeCodeTable[(unsigned char)part]);
        InvertRigid(&m);
        pos = h->m60.t;
        Apply(&pos, &m, &pos);
    }
    if (!h->b34) World_PushObject(g_Game, t, h->ctl);
    {
        StateMsg* p = &sm;
        Event_Construct(p, g_ActorActionMsgClass);
        p->vt = D_004E0840;
        p->state = 7;
        p->sub = 2;
        p->vt = D_004E01E0;
        p->stamp = D_0048B1D0;
        Event_Send(p, t, 0);
        sm.vt = D_004E0840;
        cMessage_dtor(p, 0);
    }
    if (g_IsMultiplayer) {
        V v = pos;
        TaserMsg* p = &tm;
        Event_Construct(p, D_00504050);
        p->vt = D_004DCF10;
        p->vt = D_004DCDA0;
        p->b24 = 1;
        p->tgt = t;
        p->part = part;
        p->pos = v;
        tm.b20 = 4;
        tm.i1C = 0x40;
        Event_Send(&tm, h->ctl, 0);
        tm.vt = D_004DCF10;
        cMessage_dtor(p, 0);
    }
    cAirTaser_BeginShocking_cHumanP_int_cVector(h, t, part, pos);
}


