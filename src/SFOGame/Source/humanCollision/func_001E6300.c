#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma always_inline on
#pragma inline_depth(10)
#include "vc_copy.h"
/* PlcC copies and the matrix-row copy as GCC-style volatile asm: with GCC asm present the unused xx in PlcC's copy ctor survives as retail's dead addiu (cf. humanIk_6.c) */
static inline void GCopy(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void VCopyRevF2(const void* s, void* d) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V4C { __int128 q; V4C& operator=(const V4C& o) { VCopyF(this, &o); return *this; } };
struct PlcC;
struct NodeC;
struct MtxC { V4C r0; V4C r1; V4C r2; V4C r3; MtxC() {} MtxC(NodeC* n); };
extern "C" PlcC* cQuatVec_ctor_cQuatVecR(PlcC*, const PlcC*);
extern "C" PlcC* cQuatVec_Transform(PlcC*, const PlcC*);
struct PlcC {
    V4C rot; V4C pos;
    PlcC() {}
    PlcC(const PlcC& o) { cQuatVec_ctor_cQuatVecR(this, &o); void* xx = this; }
    PlcC& operator*=(const PlcC& o) { return *cQuatVec_Transform(this, &o); }
    PlcC(const MtxC& m);
    PlcC& operator=(const PlcC& o) { PlcC* d = Me(); GCopy(d, &o); GCopy(&d->pos, &o.pos); return *this; } PlcC* Me() { return this; }
    PlcC& Set(const PlcC& o) { PlcC* d = this; GCopy(d, &o); GCopy(&d->pos, &o.pos); return *this; }
};
struct NodeC {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char p4[0xC]; MtxC mtx; unsigned char dirty;
    MtxC* GetMatrix() { if (dirty) Update(); return &mtx; }
};
typedef struct { char p0[0x50]; NodeC* node; } SupportC;
struct RootC { char p0[0xD0]; float weight; };
typedef struct { char p0[0xB0]; char coll[4]; } OwnerC;
typedef struct {
    char p0[0xC]; OwnerC* owner; char p10[0xE8 - 0x10];
    unsigned char active; char pE9[0x164 - 0xE9];
    SupportC** first; char p168[0x1F0 - 0x168];
    SupportC* sup[3]; char p1FC[4];
    PlcC world[3];
    PlcC local[3];
    unsigned char keep[3];
} ActorC;
extern "C" {
RootC* RootCollection_FindByKey(void*, void*);
void cMatrix_Copy_InvertRotTrans(MtxC*, MtxC*);
PlcC* cSkaAnimAnchor_GetTransform(RootC*);
}
extern char D_004A03C8[];
extern char D_004A03D0[];
extern char D_004A03D8[];


static inline PlcC* MtxToPlc(PlcC* out, MtxC* m) {
    MtxC* mp = m;
    PlcC* op = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mp)
        lqc2 vf2, 0x10(mp)
        lqc2 vf3, 0x20(mp)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(op)
        .set reorder
    }
    VCopyRevF2(&m->r3, &out->pos);
    return out;
}

inline PlcC::PlcC(const MtxC& m) { MtxToPlc(this, (MtxC*)&m); }
inline PlcC operator*(const PlcC& a, const PlcC& b) { PlcC t; return *cQuatVec_ctor_cQuatVecR(&t, &a) *= b; }
inline MtxC::MtxC(NodeC* n) { if (n->dirty) n->Update(); cMatrix_Copy_InvertRotTrans(this, &n->mtx); }
static inline void Capture(NodeC* n, RootC* r, PlcC* world, PlcC* local)
{
    *world = *cSkaAnimAnchor_GetTransform(r) * PlcC(MtxC(n));
    local->Set(PlcC(*n->GetMatrix()));
}

extern "C" void cHumanCollisionRoutine_Transport_EndOfFrameUpdate(ActorC* a)
{
    if (a->active) {
        SupportC* s = *a->first;
        a->sup[0] = 0;
        if (s) {
            NodeC* n = s->node;
            if (n) {
                RootC* r = RootCollection_FindByKey(a->owner->coll, D_004A03C8);
                a->sup[0] = s;
                Capture(n, r, &a->world[0], &a->local[0]);
            }
        }
    }
    a->keep[0] = 0;
    {
        SupportC* s = a->sup[1];
        if (s) {
            RootC* r = RootCollection_FindByKey(a->owner->coll, D_004A03D0);
            if (!(r->weight <= 0.0f) || a->keep[1]) {
                NodeC* n = s->node;
                if (n) Capture(n, r, &a->world[1], &a->local[1]);
            } else {
                a->sup[1] = 0;
            }
            if (!(r->weight <= 0.0f)) a->keep[1] = 0;
        }
    }
    {
        SupportC* s = a->sup[2];
        if (s) {
            RootC* r = RootCollection_FindByKey(a->owner->coll, D_004A03D8);
            if (!(r->weight <= 0.0f) || a->keep[2]) {
                NodeC* n = s->node;
                if (n) Capture(n, r, &a->world[2], &a->local[2]);
            } else {
                a->sup[2] = 0;
            }
            if (!(r->weight <= 0.0f)) a->keep[2] = 0;
        }
    }
}

