#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)
/* cDecalMan_AddProjectedDecal: cast 32 line-of-sight rays from a hit position along the manager's
   spray directions, collect the distinct models they strike (and the mean hit point), then
   place a blood decal record on each struck model. */
/* quadword copy (lq/sq): a 128-bit move C cannot express */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void ScaleV(V* r, const V* v, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(v), "f"(k) : "memory"); }
static inline V Scale(const V& v, float k) { V r; ScaleV(&r, &v, k); return r; }
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void Normalize(V* v) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory"); }

struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Info_7C0 { int first; };
struct Owner_7C0 { char pad0[0x68]; Info_7C0* info; };
struct Obj_7C0 {
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual Owner_7C0* ModelOwner();
    char pad4[0x45];
    signed char kind;       /* 0x49 */
    unsigned char Kind() const { unsigned char k = kind; return k; }
    char pad4A[0x1A];
    Owner_7C0* owner;       /* 0x64 */
};
struct HitSub { VP v[3]; V pos; unsigned char b40; char pad41; unsigned char b42; char pad43[0x1D]; int i60; Obj_7C0** obj; char pad68[0x18];
    /* empty walk over v[] mirrors the retail V[3] array-ctor loop on the materialized sub-object pointer */
    HitSub* Init() { HitSub* t = this; VP* q = t->v; do { q++; } while (q != t->v + 3); t->b40 = 0; t->b42 = 0; t->i60 = 0; t->obj = 0; return t; } };
struct HitInfo { unsigned char hit; char pad1[0x1F]; HitSub s; HitInfo* Init() { HitInfo* t = this; t->s.Init(); return t; } } __attribute__((aligned(16)));
struct Rec_7C0 { char pad0[0x5C]; float f5C; };
struct DecalMgr_7C0 {
    int pad0;
    Rec_7C0** recs;         /* 0x4 */
    int pad8;
    int cap;                /* 0xC */
    int pad10;
    int count;              /* 0x14 */
    int pad18;
    unsigned int head;      /* 0x1C */
    int pad20;
    unsigned int base;      /* 0x24 */
    char pad28[8];
    V dirs[32];             /* 0x30 */
};
struct Svc_7C0 { VPAD1(a) virtual void Post(void*); };

extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc_7C0* cSystemContainer_GetSystem(void*, void*);
Rec_7C0* DecalMgr_AddBloodRecord(Rec_7C0* r, int flags, V* pos, V* dir, float f, float g, Obj_7C0* parent);
void cDecalMan_AddProjectedDecal(DecalMgr_7C0* self, V* pos, int seed, V* normal, float size);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V pos; V dir; Obj_7C0* src; Obj_7C0* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V& p, V d, Obj_7C0* s, Obj_7C0* t) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; a24 = 0; a28 = 0; info = i; V* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; n = 4; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgRay() { vtable = D_004D9180; }
} __attribute__((aligned(16)));

static inline int HasInfo(Owner_7C0* p) { return p->info->first ? 1 : 0; }

void cDecalMan_AddProjectedDecal(DecalMgr_7C0* self, V* pos, int seed, V* normal, float size)
{
    Obj_7C0* list[32];
    V sum;
    HitInfo info;
    int hits = 0;
    int n = 0;
    int i;
    int i2;
    float k = 2.0f * size;
    sum.x = 0.0f;
    sum.y = 0.0f;
    sum.z = 0.0f;
    sum.w = 0.0f;
    for (i = 0; i < 32; i++) {
        Svc_7C0* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        info.Init();
        MsgRay m(&info, *pos, Scale(self->dirs[i], k), 0, 0);
        svc->Post(&m);
        if (info.hit) {
            Obj_7C0* o = *info.s.obj;
            bool found = 0;
            if (o->Kind() == 1) {
                found = 1;
            } else if (o->Kind() == 15) {
                if (o->owner && HasInfo(o->owner)) {
                    o = (Obj_7C0*)o->owner;
                    found = 1;
                }
            } else if (o->Kind() == 16) {
                if (o->ModelOwner() && HasInfo(o->ModelOwner())) {
                    o = (Obj_7C0*)o->ModelOwner();
                    found = 1;
                }
            }
            if (found) {
                int j;
                { HitSub* hs = &info.s; V* pp = &hs->pos; AddV(&sum, &sum, pp); }
                for (j = 0; j < n; j++)
                    if (list[j] == o)
                        break;
                if (j == n)
                    list[n++] = o;
                hits++;
            }
        }
    }
    if (!normal) {
        sum.x = sum.x / (float)hits;
        sum.y = sum.y / (float)hits;
        sum.z = sum.z / (float)hits;
        sum.w = 0.0f;
        Normalize(&sum);
    } else {
        sum = *normal;
    }
    for (i2 = 0; i2 < n; i2++) {
        Obj_7C0* o = list[i2];
        if (o) {
            unsigned int h = self->head++;
            unsigned int slot = (h + self->base) % self->cap;
            if (self->head == self->cap)
                self->head = 0;
            if (self->count < self->cap) {
                self->count++;
            } else {
                Rec_7C0* old = self->recs[slot];
                if (old->f5C != -2.0f)
                    old->f5C = 0;
            }
            {
                Rec_7C0* r = self->recs[h];
                if (r)
                    DecalMgr_AddBloodRecord(r, 10, pos, &sum, size, (float)seed, o);
            }
        }
    }
}
