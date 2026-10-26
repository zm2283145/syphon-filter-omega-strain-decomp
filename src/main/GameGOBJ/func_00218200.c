#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "cmessage.h"
#pragma inline_depth(8)
/* PathObj_PropagateMovement: pass the path object's new placement on to the
 * attached objects (teleport message or direct set; dead handles are erased)
 * and to the child sources (their transform times the new placement). */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));

/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
static inline void CopyM(void* dd, const void* ss) { void* d = dd; __int128 qa, qb; const void* s = ss; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct M {
    V r0, r1, r2, r3;
    M() {}
    M(const M& o) { CopyM(this, &o); }
};
static inline M MMul(M& a, M& b) { M r; M* rp = &r; M* bp = (M*)&b; M* ap = &a; __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }

struct PSrc {
    VPAD16(a) VPAD4(b)
    virtual void Refresh();
    char pad4[0xC];
    M xform;
    unsigned char dirty;
    M* Xform() { if (dirty) Refresh(); return &xform; }
};
struct PMover {
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetPlacement(M* p);
    VPAD4(d)
    virtual void SetPosition(V* p);
    char p04[0xC - 4]; int id;
};
struct PKid { char pad0[0x50]; PSrc* src; };
struct PHandle { PMover* object; int id; };
struct PHVec { int unk0; int count; PHandle* data; };
struct PathObj {
    char pad0[0x70];
    int nKids;
    PtrVec kidv;
    char pad80[0x84 - 0x80];
    PHVec hv;
};
struct PTeleMsg {
    CMSG_HEADER;
    signed char mode; char pad25[0xB];
    M matrix;
};
extern "C" {
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
void* Mtx_GetIdentity();
void* Mtx_SetRotationTranslation(void* d, void* r, void* t);
V func_0015A400(const V& v);
int* func_00172990(PtrVec* v, int i);
void func_002186A0(PHVec* v);
PHandle* func_002186B0(PHandle* d, PHandle* s);
PHandle* func_002186D0(PHVec* v, int i);
int func_002186E0(PHVec* v);
void PathObj_PropagateMovement(PathObj* self, M m, int msg);
}
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int EqNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
static inline PMover* WGet(PHandle* h) { bool ok = 1; if (!IsNullNV(h->object) && !EqNV(h->object->id, h->id)) ok = 0; unsigned char k = ok; return k ? h->object : 0; }
static inline void SetRT(void* d, void* r, const V& t) { Mtx_SetRotationTranslation(d, r, (void*)&t); }
static inline void SetPose(void* d, void* r, const V& p) { SetRT(d, r, func_0015A400(p)); }
static inline int** KData(PtrVec* v) { return &v->data; }
static inline void* KidAt(PtrVec* v, int i) { return (void*)(*KData(v))[i]; }
static inline void SetPose1(void* d, void* r, const V& p) { SetPose(d, r, p); }
static inline void Erase(PHVec* v, int i)
{
    int n = func_002186E0(v);
    if (i >= 0 && i < n) {
        for (int j = i + 1; j < n; j++)
            func_002186B0(func_002186D0(v, j - 1), func_002186D0(v, j));
        func_002186A0(v);
    }
}

void PathObj_PropagateMovement(PathObj* self, M m, int msg)
{
    int n = self->hv.count;
    int i;
    for (i = 0; i < n; i++) {
        if (WGet(&self->hv.data[i])) {
            if (msg) {
                PTeleMsg t;
                PTeleMsg* tp = &t;
                V* pos = &m.r3;
                Event_Construct(tp, g_TeleportMsgClass);
                tp->vtable = D_004D9360;
                tp->mode = 3;
                void* id = Mtx_GetIdentity();
                SetPose1(&tp->matrix, id, *pos);
                t.kind = 1;
                Event_Send(&t, WGet(&self->hv.data[i]), 1);
                t.vtable = D_004D9360;
                cMessage_dtor(&t, 0);
            } else {
                V* pos = &m.r3;
                WGet(&self->hv.data[i])->SetPosition(pos);
            }
        } else {
            Erase(&self->hv, i);
            n--;
            i--;
        }
    }
    for (i = 0; i < self->nKids; i++) {
        PSrc* s = ((PKid*)*func_00172990(&self->kidv, i))->src;
        M x;
        CopyM(&x, s->Xform());
        M w = MMul(m, x);
        if (msg) {
            PTeleMsg t;
            PTeleMsg* tp = &t;
            Event_Construct(tp, g_TeleportMsgClass);
            tp->vtable = D_004D9360;
            tp->mode = 2;
            CopyM(&tp->matrix, &w);
            t.kind = 1;
            Event_Send(&t, KidAt(&self->kidv, i), 1);
            t.vtable = D_004D9360;
            cMessage_dtor(&t, 0);
        } else {
            ((PMover**)self->kidv.data)[i]->SetPlacement(&w);
        }
    }
}
