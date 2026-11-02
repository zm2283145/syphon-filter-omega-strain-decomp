/*
 * SFOGame/Source/humanCollision: 8 files, 001E8F60-001E9250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E8F60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Word equality. */
int func_001E8F60(Word* a, Word* b) {
    return a->value == b->value;
}

Iter* func_001E8F80(Iter* it) {
    it->p++;
    return it;
}

void std_vector_cTreeNode_cSkaSystemPtrPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_001E8FC0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001E8FD0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001E8F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8F60 */

/* merge_units: begin func_001E8FE0 */
#pragma push /* merge_units */
/* Returns whether the word at +4 is zero. */
int func_001E8FE0(int* self)
{
    return self[1] == 0;
}
static inline void merge_flush_func_001E8FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8FE0 */

/* merge_units: begin func_001E8FF0 */
#pragma push /* merge_units */
int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001E9010(Iter* it) {
    it->p++;
    return it;
}

int func_001E9030(Word* w) {
    return w->value;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001E9060(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int cTreeNode_cSkaSystemPtr_HasChildren(Node* n) {
    return !(n->count == 0);
}
static inline void merge_flush_func_001E8FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E8FF0 */

/* merge_units: begin func_001E9090 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
typedef struct RNode RNode;
typedef struct { RNode** data; int count; } RVec;
typedef struct { RNode** p; } RIt;
struct RNode { int f0; RNode* parent; RVec children; };
#if 0 /* merge_units */
extern int cTreeNode_cSkaSystemPtr_HasChildren(RNode* n);
#endif /* merge_units */
#define cTreeNode_cSkaSystemPtr_HasChildren(a0) (cTreeNode_cSkaSystemPtr_HasChildren((Node *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(RIt* a, RIt* b);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(a0, a1) (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern RIt* func_001E9010(RIt* it);
#endif /* merge_units */
#define func_001E9010(a0) ((RIt *)func_001E9010((Iter *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern RNode** func_001E9030(RIt* w);
#endif /* merge_units */
#define func_001E9030(a0) ((RNode * *)func_001E9030((Word *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(RIt* out, RVec* v);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(a0, a1) (cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void func_001E9060(RIt* out, RVec* v);
#endif /* merge_units */
#define func_001E9060(a0, a1) (func_001E9060((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern RNode** func_001E9250(RVec* v);
#endif /* merge_units */
int* func_001E9250(PtrVec* v); /* merge_units */
#define func_001E9250(a0) ((RNode * *)func_001E9250((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_001E9270(RIt* out, RVec* self, RIt* src);
#endif /* merge_units */
void func_001E9270(Iter* out, void* self, Iter* src); /* merge_units */
#define func_001E9270(a0, a1, a2) (func_001E9270((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern RNode** func_001E9280(RVec* v);
#endif /* merge_units */
int* func_001E9280(PtrVec* v); /* merge_units */
#define func_001E9280(a0) ((RNode * *)func_001E9280((PtrVec *)(a0))) /* merge_units */

unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t);
}

static inline bool Check(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (cTreeNode_cSkaSystemPtr_HasChildren(n)) {
        bool found = 0;
        RIt it, end;
        func_001E9060(&it, &n->children);
        cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2(&end, &n->children);
        while (cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe(&it, &end)) {
            if (cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(*func_001E9030(&it), t)) { found = 1; break; }
            func_001E9010(&it);
        }
        return found;
    }
    return 0;
}

static inline bool HasKids(RVec* v) { return !(v->count == 0); }
static inline void Begin(RIt* it, RVec* v) { RIt t; t.p = func_001E9280(v); func_001E9270(it, v, &t); }
static inline void End(RIt* it, RVec* v) { RIt t; t.p = func_001E9250(v); func_001E9270(it, v, &t); }
static inline bool NeP(RNode** a, RNode** b) { return !(a == b); }
static inline bool Ne(RIt* a, RIt* b) { return !(a->p == b->p); }

#pragma push
#pragma opt_common_subs off
extern "C" unsigned char cTreeNode_cSkaSystemPtr_IsAttached_SearchDown(RNode* n, RNode* t) {
    if (n == t) return 1;
    if (HasKids(&n->children)) {
        bool found = 0;
        RIt it, end;
        RIt q, e;
        Begin(&it, &n->children);
        q = it;
        End(&end, &n->children);
        e = end;
        while (Ne(&q, &e)) {
            if (Check(*q.p, t)) { found = 1; break; }
            q.p++;
        }
        return found;
    }
    return 0;
}


#pragma pop
#undef cTreeNode_cSkaSystemPtr_HasChildren /* merge_units */
#undef cArray_cTreeNode_cSkaSystemPtrPtr_ConstIterator_opNe /* merge_units */
#undef func_001E9010 /* merge_units */
#undef func_001E9030 /* merge_units */
#undef cArray_cTreeNode_cSkaSystemPtrPtr_End_void_2 /* merge_units */
#undef func_001E9060 /* merge_units */
#undef func_001E9250 /* merge_units */
#undef func_001E9270 /* merge_units */
#undef func_001E9280 /* merge_units */
static inline void merge_flush_func_001E9090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9090 */

/* merge_units: begin func_001E9250 */
#pragma push /* merge_units */
int* func_001E9250(PtrVec* v) {
    return v->data + v->count;
}

void func_001E9270(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_001E9280(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_001E9250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9250 */

/* merge_units: begin func_001E9290 */
#pragma push /* merge_units */
typedef struct { char pad0[2]; unsigned char valid; char pad1[0x6D]; int mask; char pad2[0x2C]; } HgSlot;
typedef struct { char pad0[0x3E0]; HgSlot slots[7]; } HgActor;
int cHumanCollisionRoutine_CanClimbUpFromHang(HgActor* a)
{
    HgSlot* s;
    s = &a->slots[6];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[5];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[3];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    return 0;
}
static inline void merge_flush_func_001E9290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9290 */

/* merge_units: begin func_001E9300 */
#pragma push /* merge_units */
#include "vu0_addeq.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_9300;
typedef struct { char p0[0x40]; V_9300 a; char p50[0x20]; V_9300 b; char p80[0x2F0 - 0x80]; V_9300 c; V_9300 d; } Act_9300;
/* shift both teleport lanes and two positions by dv (VU0 adds) */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cHumanCollisionRoutine_Move(Act_9300* act, V_9300* dv)
{
    V_9300 t;
    {
        /* by-value copy of the offset (VCopyF idiom: lq free, sq unfolded) */
        V_9300* td;
        __int128 q;
        asm { .set reorder; lq q, 0(dv) }
        td = &t;
        asm { sq q, 0(td) }
    }
    VU0_ADDEQ3(V_9300, &act->c, &t);
    VU0_ADDEQ3(V_9300, &act->d, &t);
    VU0_ADDEQ1(V_9300, &act->a, dv);
    VU0_ADDEQ1(V_9300, &act->b, dv);
}
#pragma pop
static inline void merge_flush_func_001E9300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9300 */

/* merge_units: begin func_001E9380 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V { float x, y, z, w; } __attribute__((aligned(16)));
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct VC {
    float x, y, z, w;
    VC() {}
    VC(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    VC(const VC& o) { Q16(this, &o); }
    VC& operator=(const VC& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Mtx { __int128 r[4]; };

static inline float Dot3(VC* a, VC* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline VC XForm(Mtx* m, const VC& v) {
    VC p = v;
    VC* pp = &p;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}
static inline void XF(Mtx* m, VC* pp) {
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
}
static inline float Dot3B(VC* b, VC* a) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
struct Plane {
    VC n;
    Plane() {}
    Plane(float a, float b, float c, float d) { n.x = a; n.y = b; n.z = c; n.w = d; }
    void Set(float a, float b, float c, float d) { n.x = a; n.y = b; n.z = c; n.w = d; }
    Plane& operator=(const Plane& o) { Q16(this, &o); return *this; }
};

struct FP {
    VC pos; VC n; float d; char pad[0xC];
    void Set(const VC& p, const VC& nn, float dd) { Q16(&pos, &p); Q16(&n, &nn); d = dd; } void SetB(const VC& p, const VC& nn, float dd) { VC* a = &pos; Q16(a, &p); VC* b = &n; Q16(b, &nn); d = dd; }
};
struct Owner { char pad[0x50]; VC com; };
struct Ctx { char pad[0xB0]; char anchors[1]; };
struct HCR {
    char p0[8];
    Owner* owner;      /* 08 */
    Ctx* ctx;          /* 0C */
    char p10[0x30];
    FP fp0;            /* 40 */
    FP fp1;            /* 70 */
    char pA0[0xDC - 0xA0];
    unsigned char bDC; /* DC */
    unsigned char bDD; /* DD */
    char pDE[2];
    float zE0;         /* E0 */
    float zE4;         /* E4 */
    unsigned char bE8; /* E8 */
    char pE9[7];
    Plane plane;       /* F0 */
    char p100[0x2C4 - 0x100];
    float f2C4;
    char p2C8[0x2E0 - 0x2C8];
    char pm[0x394 - 0x2E0]; /* 2E0 */
    float f394;
};

extern char D_004A03C8[];
extern "C" {
void* RootCollection_FindByKey(void* list, void* name);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(void* a);
VC* cQuatVec_Rotation(void* t);
VC* cQuatVec_Translation(void* t);
Mtx* cMatrix_ctor_cQuaternionR(Mtx* m, VC* q);
void cMatrix_Set_cMatrixR_cVectorR(Mtx* m, Mtx* r, VC* t);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* a);
VC* cVector_ctor_cVectorR(VC* d, VC* s);
void cPointMass_Teleport(void* pm, VC* v);
void cPointMass_ClearPhysics(void* pm);
void cHumanCollisionRoutine_InitializePosition(HCR* self);
}
void cHumanCollisionRoutine_InitializePosition(HCR* self)
{
    VC com;
    VC floorPos;
    Mtx xf;
    VC comCopy;
    VC n0;
    VC n1;
    VC up;
    VC xl;
    Plane pl;
    Mtx rot;
    VC tmp;
    void* anchor = RootCollection_FindByKey(self->ctx->anchors, D_004A03C8);
    void* t = cSkaAnimAnchor_GetSkeletonTargetTransform(anchor);
    Mtx* r = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(t));
    cMatrix_Set_cMatrixR_cVectorR(&xf, r, cQuatVec_Translation(t));
    { VC* d = &xl; Q16(d, &self->owner->com); }
    { VC* pp = &xl; XF(&xf, pp); VC* c = &com; Q16(c, pp); }
    { VC* src = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(anchor)); VC* fp = &floorPos; Q16(fp, src); }
    comCopy = com;
    { VC* cp = &comCopy; cPointMass_Teleport(self->pm, cVector_ctor_cVectorR(&tmp, cp)); }
    cPointMass_ClearPhysics(self->pm);
    n0.Set(0.0f, 0.0f, 1.0f, 0.0f);
    self->fp0.SetB(floorPos, n0, 0.0f);
    n1.Set(0.0f, 0.0f, 1.0f, 0.0f);
    self->fp1.Set(floorPos, n1, 0.0f);
    self->bDC = 0;
    self->bDD = 1;
    self->bE8 = 0;
    self->zE0 = floorPos.z;
    self->zE4 = -3.4028235e38f;
    up.Set(0.0f, 0.0f, 1.0f, 0.0f);
    pl.Set(up.x, up.y, up.z, -Dot3B(&floorPos, &up));
    self->plane = pl;
    self->f2C4 = 0.0f;
    self->f394 = 0.0f;
}
static inline void merge_flush_func_001E9380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9380 */
