/*
 * SFOGame/Source/humanCollision: 5 files, 001EA140-001EA4F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EA140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rec* cVector_WSet0(Rec* r) {
    r->v = 0;
    return r;
}
static inline void merge_flush_func_001EA140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EA140 */

/* merge_units: begin func_001EA150 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
static inline V4* NormXYZ_(V4* v, float* len) {
    int t;
    asm {
        lqc2 vf1, 0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(v)
        qmfc2.ni t, vf4
    }
    *(int*)len = t;
    return v;
}
extern "C" void cVector_GetNormalized_floatR(V4* out, V4* in, float* len);
void cVector_GetNormalized_floatR(V4* out, V4* in, float* len)
{
    V4 t;
    V4* p = &t;
    { V4* d = &t; __int128 q; asm volatile { lq q, 0(in); sq q, 0(d) } }
    __int128 tt = 0; /* dead: retail's paddub zero */
    NormXYZ_(p, len);
    { __int128 q; asm volatile { lq q, 0(p); sq q, 0(out) } }
}
static inline void merge_flush_func_001EA150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EA150 */

/* merge_units: begin func_001EA1B0 */
#pragma push /* merge_units */
typedef struct { int head; int bits[1]; } B1EA1B0;
#pragma optimization_level 3
B1EA1B0* Physical_CopyModeRecord(B1EA1B0* d, const B1EA1B0* s)
{
    int i;
    d->head = s->head;
    for (i = 0; i < 13; i++) {
        int w = i / 32;
        int b = i & 31;
        if ((s->bits[w] >> b) & 1)
            d->bits[w] |= 1 << b;
        else
            d->bits[w] &= ~(1 << b);
    }
    return d;
}
static inline void merge_flush_func_001EA1B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EA1B0 */

/* merge_units: begin func_001EA240 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cHumanCollisionRoutine_ConstructTestObjectForFirstPassCull: world-space box swept by the actor's collision
 * cylinder this frame: radius (2, or 3 while carrying), height (8, larger
 * when crouched/prone per the posture flags, 14 for type 9) and floor depth,
 * grown by 1 unit, unioned with its copy moved by the frame's motion, then
 * placed at the root's world position. */
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V lo, hi; Box() {} Box& operator=(const Box& o) { const Box* s = &o; Box* d = this; __int128 a, b; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); sq %1, 0x10(%3)" : "=&r"(a), "=r"(b) : "r"(s), "r"(d) : "memory"); return *this; } };
struct Owner { char pad[0xB0]; char coll[4]; };
/* 9 per-posture state slots of 160 bytes; [1] deep, [3] prone, [4] swim */
struct Slot { unsigned char on; char pad[159]; };
struct Phys {
    char pad0[0xC]; Owner* owner; char pad10[0x20 - 0x10]; int type; char pad24[0x2F0 - 0x24];
    V pos; V prev; char pad310[0x3D3 - 0x310]; unsigned char crouch;
    char pad3D4[0x3E0 - 0x3D4]; Slot st[9];
};
extern "C" {
extern char D_004A03C8[];
extern float D_004A0358;
extern float D_004A0400;
extern float D_004A0408;
void* RootCollection_FindByKey(void* coll, void* key);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V* cQuatVec_Translation(void* p);
void cBox_ctor_cBoxR(Box* d, Box* s);
void cBox_opAddAssign(Box* a, Box* b);
void cHumanCollisionRoutine_ConstructTestObjectForFirstPassCull(Phys* self, Box* out);
}
static inline void AddXYZ(V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory"); }
static inline void SubV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void UnionInto(Box* o, Box* a, Box* b) { Box r; cBox_ctor_cBoxR(&r, a); cBox_opAddAssign(&r, b); cBox_ctor_cBoxR(o, &r); }
static inline V operator-(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }

void cHumanCollisionRoutine_ConstructTestObjectForFirstPassCull(Phys* self, Box* out)
{
    float pad = 1.0f; float height = 8.0f; float floor = -3.5f; float radius = 2.0f;
    int i;
    if (self->st[4].on)
        height = D_004A0408;
    else if (self->st[3].on)
        height = D_004A0400;
    else if (self->crouch)
        height += D_004A0358;
    if (self->st[1].on)
        floor = -8.0f;
    if (self->type == 9) {
        height = 14.0f;
        floor = -8.0f;
    }
    for (i = 0; i < 9; i++) {
        if (self->st[i].on) {
            radius = 3.0f;
            break;
        }
    }
    {
        V pos = *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(self->owner->coll, D_004A03C8)));
        V d = self->pos - self->prev;
        V lo, hi;
        lo.x = -radius - pad; lo.y = -radius - pad; lo.z = floor - pad; lo.w = 1.0f;
        hi.x = radius + pad; hi.y = radius + pad; hi.z = height + pad; hi.w = 1.0f;
        Box b0; b0.lo = lo; b0.hi = hi;
        Box b1; b1.lo = b0.lo; b1.hi = b0.hi;
        Box o2;
        AddXYZ(&b1.lo, &d);
        AddXYZ(&b1.hi, &d);
        UnionInto(&o2, &b0, &b1);
        { Box* p = &o2; *out = o2; } /* p: retail keeps a dead sp+112 address here */
        AddXYZ(&out->lo, &pos);
        AddXYZ(&out->hi, &pos);
    }
}
static inline void merge_flush_func_001EA240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EA240 */

/* merge_units: begin func_001EA4F0 */
#pragma push /* merge_units */
/*
 * cHumanCollisionRoutine_InitLedgeSearchWorkSpace: builds the nine collision preset descriptors on the
 * stack (candidate masks, height/distance/cosine ranges) and appends them to
 * g_HumanColPresetMgr; the last append is expanded in place.
 */
#include "humanCollision_types.h"

/* Preset descriptor built on the stack and appended to the manager. */
typedef struct HumanColDesc {
    signed char selector;           /* 0x00 */
    signed char kind;               /* 0x01 */
    char pad02[2];
    int masks[4];                   /* 0x04 */
    HumanColPresetCfg cfg;          /* 0x14 */
    unsigned char descFlag;         /* 0x30 */
} HumanColDesc;

extern float Libc_Cosf(float);
extern int* cBitArray_19_ctor_cBitArrayR(int* dst, int* src);
extern int* cBitArray_5_ctor_cBitArrayR(int* dst, int* src);
extern HumanColPresetCfg* cHumanCollisionRoutine_cLedgeSearchLimits_ctor(HumanColPresetCfg* dst, HumanColPresetCfg* src);
extern HumanColPresetMgr* cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(HumanColPresetMgr* mgr, HumanColDesc* desc);
extern HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc(HumanColPreset* p, int selector, int* mask0, int* mask1,
                                                int* mask2, int* mask3, HumanColPresetCfg* cfg, int enabled);
extern void cArray_FixedCapacity_cIntermediateLedgeSearchInfo_9_PushBackActual(HumanColPresetMgr* mgr, HumanColPreset* p);
extern HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor(HumanColPreset* self, short flag);
extern HumanColPresetMgr* g_HumanColPresetMgr;

static inline void Range_Set(float* r, float lo, float hi) {
    r[0] = lo;
    r[1] = hi;
}

#define Cfg_Init(c, a, b, d, e, angLo, angHi, en) \
    ((c)->range0Min = (a), (c)->range0Max = (b), (c)->range1Min = (d), (c)->range1Max = (e), \
     Range_Set(&(c)->range2Min, Libc_Cosf(angLo), Libc_Cosf(angHi)), (c)->enabled = (en))

static inline void Desc_Tail(HumanColDesc* d, int* m2, int* m3, HumanColPresetCfg* cfg, int flag) {
    cBitArray_5_ctor_cBitArrayR(&d->masks[2], m2);
    cBitArray_5_ctor_cBitArrayR(&d->masks[3], m3);
    cHumanCollisionRoutine_cLedgeSearchLimits_ctor(&d->cfg, cfg);
    d->descFlag = flag;
}

static inline void Desc_Head(HumanColDesc* d, int kind, int sel, int* m0, int* m1) {
    d->selector = sel;
    d->kind = kind;
    cBitArray_19_ctor_cBitArrayR(&d->masks[0], m0);
    cBitArray_19_ctor_cBitArrayR(&d->masks[1], m1);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cHumanCollisionRoutine_InitLedgeSearchWorkSpace(void) {
    int a0, a1, a2, a3;
    int b0, b1, b2, b3;
    int c0, c1, c2, c3;
    int d0, d1, d2, d3;
    int e0, e1, e2, e3;
    int f0, f1, f2, f3;
    int g0, g1, g2, g3;
    int h0, h1, h2, h3;
    int i0, i1, i2, i3;
    HumanColPresetCfg ca;
    HumanColDesc da;
    HumanColPresetCfg cb;
    HumanColDesc db;
    HumanColPresetCfg cc;
    HumanColDesc dc;
    HumanColPresetCfg cd;
    HumanColDesc dd;
    HumanColPresetCfg ce;
    HumanColDesc de;
    HumanColPresetCfg cf;
    HumanColDesc df;
    HumanColPresetCfg cg;
    HumanColDesc dg;
    HumanColPresetCfg ch;
    HumanColDesc dh;
    HumanColPresetCfg ci;
    HumanColDesc di;
    HumanColPreset tmp;
    HumanColPresetMgr* mgr;
    int one;
    float q;
    float r;
    HumanColDesc* p;

    a0 = 0; a1 = 0; a2 = 0; a3 = 0;
    Cfg_Init(&ca, -1.5f, 0.5f, -0.0f, 9.0f, 1.0471976f, 0.0f, 1);
    a3 |= 1; a1 |= 0x1000; a3 |= 8;
    p = &da;
    Desc_Head(&da, 0, 0, &a0, &a1);
    Desc_Tail(p, &a2, &a3, &ca, 0);

    b0 = 0; b1 = 0; b2 = 0; b3 = 0;
    Cfg_Init(&cb, -1.5f, 0.5f, -0.25f, 9.0f, 1.4835298f, 0.0f, one = 1);
    b3 |= 1; b1 |= 0x1000; b3 |= 8;
    p = &db;
    Desc_Head(&db, one, one, &b0, &b1);
    Desc_Tail(p, &b2, &b3, &cb, 0);

    c0 = 0; c1 = 0; c2 = 0; c3 = 0;
    Cfg_Init(&cc, 1.5f, 7.0f, -0.0f, 16.0f, 1.7453293f, 0.0f, 0);
    c3 |= 1; c1 |= 0x1000; c0 |= 0x10; c3 |= 8;
    p = &dc;
    Desc_Head(&dc, 3, 2, &c0, &c1);
    Desc_Tail(p, &c2, &c3, &cc, 0);

    d0 = 0; d1 = 0; d2 = 0; d3 = 0;
    Cfg_Init(&cd, 7.0f, 0.25f + D_004A0400, -0.0f, 16.0f, 3.1503193378448486f, 0.0f, 0);
    d3 |= 1; d1 |= 0x1000; d3 |= 8;
    p = &dd;
    Desc_Head(&dd, 5, 3, &d0, &d1);
    Desc_Tail(p, &d2, &d3, &cd, 0);

    e0 = 0; e1 = 0; e2 = 0; e3 = 0;
    q = 0.25f;
    Cfg_Init(&ce, q + D_004A0400, q + D_004A0408, -0.0f, 16.0f, 3.1503193378448486f, 0.0f, 0);
    e3 |= 1; e1 |= 0x1000; e3 |= 8;
    p = &de;
    Desc_Head(&de, 6, 4, &e0, &e1);
    Desc_Tail(p, &e2, &e3, &ce, 0);

    f0 = 0; f1 = 0; f2 = 0; f3 = 0;
    Cfg_Init(&cf, 2.5f, 5.0f, -0.0f, 25.0f, 1.4835298f, 0.0f, 0);
    f3 |= 1; f1 |= 0x1000; f3 |= 4; f3 |= 8;
    p = &df;
    Desc_Head(&df, 7, 5, &f0, &f1);
    Desc_Tail(p, &f2, &f3, &cf, 1);

    g0 = 0; g1 = 0; g2 = 0; g3 = 0;
    Cfg_Init(&cg, 5.5f, r = 9.0f, -2.25f, r, 1.0471976f, 0.0f, 0);
    g1 |= 0x1000;
    p = &dg;
    Desc_Head(&dg, 8, 6, &g0, &g1);
    Desc_Tail(p, &g2, &g3, &cg, 0);

    h0 = 0; h1 = 0; h2 = 0; h3 = 0;
    Cfg_Init(&ch, -3.4028235e38f, 0.5f, -0.0f, 25.0f, 3.1503193378448486f, 0.0f, 1);
    h3 |= 1; h3 |= 8; h1 |= 0x40000; h0 |= 0x1000;
    p = &dh;
    Desc_Head(&dh, 12, 7, &h0, &h1);
    Desc_Tail(p, &h2, &h3, &ch, 0);

    i0 = 0; i1 = 0; i2 = 0; i3 = 0;
    Cfg_Init(&ci, 1.5f, 8.5f, -0.0f, 25.0f, 3.1503193378448486f, 0.0f, 0);
    i3 |= 1; i1 |= 0x40000; i0 |= 0x1000; i3 |= 8;
    p = &di;
    Desc_Head(&di, 12, 8, &i0, &i1);
    Desc_Tail(p, &i2, &i3, &ci, 0);

    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(g_HumanColPresetMgr, &da);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &db);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dc);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dd);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &de);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &df);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dg);
    mgr = cHumanCollisionRoutine_cIntermediateLedgeSearchInfoList_opShl(mgr, &dh);
    cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc(&tmp, di.kind, &di.masks[0], &di.masks[1], &di.masks[2], &di.masks[3], &di.cfg, di.descFlag);
    cArray_FixedCapacity_cIntermediateLedgeSearchInfo_9_PushBackActual(mgr, &tmp);
    cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor(&tmp, -1);
}
#pragma pop
static inline void merge_flush_func_001EA4F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EA4F0 */
