/*
 * SFOGame/Source/humanIk: 6 files, 001CEA70-001CEE00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CEA70 */
#pragma push /* merge_units */
#include "types.h"
#pragma opt_propagation off
static inline float fmax_EA70(float a, float b) { float r; asm { max.s r, a, b } return r; }
typedef struct { char p0[0xE4]; float a; char p1[0x1B4-0xE8]; float b; char p2[0x2A4-0x1B8]; float c; char p3[0x374-0x2A8]; float d; } XEA70;
float cHandIkTargetList_GetTransitionTimeLeftForBothHands(XEA70* s) {
    float c; float d; float m1; float a; float b; c = s->c; d = s->d; m1 = fmax_EA70(c, d); a = s->a; b = s->b; return fmax_EA70(fmax_EA70(a, b), m1);
}
static inline void merge_flush_func_001CEA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEA70 */

/* merge_units: begin func_001CEA90 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; the unused xx in Plc's copy ctor reproduces retail's dead addiu (it survives only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void cQuatVec_ctor_cQuatVecR(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { cQuatVec_ctor_cQuatVecR(this, &o); void* xx = this; } };
struct Src { V a; V b; signed char c; };
struct Key { unsigned char a; unsigned char b; };
struct Pair { Key key; char pad2[0xE]; Src v[2]; };
struct MNode { MNode* l; MNode* r; int pad[2]; Pair p; };
struct Ent { char pad[0x10]; Src s; char pad2[0x20]; };
struct MIter { MNode* n; };
struct Self { unsigned char type; unsigned char active; signed char b2; signed char b3; signed char b4; signed char b5; };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
extern Ent* D_004F2D80;
extern void* D_004F2D88;
extern float D_0049F720;
void cQuaternion_GetIdentity(V* q);
void cVector_Get0001(V* v);
void cQuatVec_ctor_cQuaternionR_cVectorR(Plc* p, V* q, V* v);
void std_tree_pair_cWeaponSlotPair_value_compare_find(MIter* out, void* t, const Key* k);
#if 0 /* merge_units */
void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(MIter* out, void* t);
#endif /* merge_units */
void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(Iter* out, Tree* t); /* merge_units */
#define std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(a0, a1) (std_map_cWeaponSlotPair_cIkTarget_LeftRight_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
MIter* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(MIter* d, MIter* s);
#endif /* merge_units */
Word* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(Word* dst, Word* src); /* merge_units */
#define cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(a0, a1) ((MIter *)cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

void* cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(void* base, int index);
void cIkTargetWithSplinedTransition_TransitionToNewTarget(void* self, float w, Src* src);
void cDrawAndHolsterWeapon_ActionManager_StartTransitionIfNecessary(Self* s, void* aim);
}
static inline void MkKey(Key* k, int a, int b)
{
    k->a = (unsigned char)a < (unsigned char)b ? a : b;
    k->b = (unsigned char)a > (unsigned char)b ? a : b;
}
static inline int Eq(const MIter& a, const MIter& b) { return a.n == b.n; }
static inline Pair* Deref(const MIter& i) { return &i.n->p; }
static inline Ent* At(Ent* a, unsigned char i) { return &a[i]; }
static inline bool Ne(const MIter& a, const MIter& b) { return !Eq(a, b); }
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        cQuaternion_GetIdentity(&q);
        cVector_Get0001(&v);
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
void cDrawAndHolsterWeapon_ActionManager_StartTransitionIfNecessary(Self* s, void* aim)
{
    if (s->active) {
        Src* src = 0;
        signed char mode = -1;
        switch (s->type) {
        case 0:
            break;
        case 2: {
            MIter it;
            Key k;
            MIter e;
            MIter f;
            MIter t;
            MkKey(&k, s->b2, s->b3);
            std_tree_pair_cWeaponSlotPair_value_compare_find(&f, D_004F2D88, &k);
            it = f;
            std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(&t, D_004F2D88);
            cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(&e, &t);
            if (Ne(it, e)) {
                mode = s->b5;
                src = Deref(it)->v;
            }
            break;
        }
        case 1:
            mode = s->b4;
            src = &At(D_004F2D80, s->b2)->s;
            break;
        case 3:
            mode = s->b5;
            src = &At(D_004F2D80, s->b3)->s;
            break;
        }
        if (src) {
            if (mode == 0 || mode == 2) {
                cIkTargetWithSplinedTransition_TransitionToNewTarget(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(aim, 0), D_0049F720, src);
            } else {
                Src t;
                Plc p = Ident();
                t.a = p.rot;
                t.b = p.pos;
                t.c = 0x13;
                cIkTargetWithSplinedTransition_TransitionToNewTarget(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(aim, 0), D_0049F720, &t);
            }
            if (mode == 1 || mode == 2) {
                Src* s1p = src + 1;
                cIkTargetWithSplinedTransition_TransitionToNewTarget(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(aim, 1), D_0049F720, s1p);
            } else {
                Src t;
                Plc p = Ident();
                t.a = p.rot;
                t.b = p.pos;
                t.c = 0x14;
                cIkTargetWithSplinedTransition_TransitionToNewTarget(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(aim, 1), D_0049F720, &t);
            }
        }
        s->active = 0;
    }
}
#undef std_map_cWeaponSlotPair_cIkTarget_LeftRight_end /* merge_units */
#undef cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor /* merge_units */
static inline void merge_flush_func_001CEA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEA90 */

/* merge_units: begin func_001CEE00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_001CEE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE00 */

/* merge_units: begin func_001CEE20 */
#pragma push /* merge_units */
typedef struct { int* p; } F8It_1CE;
typedef struct { float m[4][4]; } F8Mtx_1CE;
typedef struct { char pad0[0x50]; unsigned char dirty; char pad51[0xF]; F8Mtx_1CE basis; char padA0[0x4]; char kids[4]; } F8Bone_1CE;
#if 0 /* merge_units */
extern void cArray_cXformNodePtr_Begin(F8It_1CE* out, void* v);
#endif /* merge_units */
void cArray_cXformNodePtr_Begin(void*, void*); /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_cXformNodePtr_End(F8It_1CE* out, void* v);
#endif /* merge_units */
void cArray_cXformNodePtr_End(void*, void*); /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int cArray_cXformNodePtr_ConstIterator_opNe(F8It_1CE* a, F8It_1CE* b);
#endif /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(); /* merge_units */


#if 0 /* merge_units */
extern int* cArray_cXformNodePtr_ConstIterator_opMul(F8It_1CE* it);
#endif /* merge_units */
void* cArray_cXformNodePtr_ConstIterator_opMul(void*); /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) ((int *)cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cXformNode_SetNeedsUpdate(int child);
#endif /* merge_units */
void cXformNode_SetNeedsUpdate(); /* merge_units */


#if 0 /* merge_units */
extern F8It_1CE* cArray_cXformNodePtr_ConstIterator_opInc(F8It_1CE* it);
#endif /* merge_units */
Iter * cArray_cXformNodePtr_ConstIterator_opInc(); /* merge_units */


void cXformNode_SetRotationMatrix_ParentRelative(F8Bone_1CE* b, F8Mtx_1CE* m)
{
    b->basis.m[0][0] = m->m[0][0];
    b->basis.m[0][1] = m->m[0][1];
    b->basis.m[0][2] = m->m[0][2];
    b->basis.m[1][0] = m->m[1][0];
    b->basis.m[1][1] = m->m[1][1];
    b->basis.m[1][2] = m->m[1][2];
    b->basis.m[2][0] = m->m[2][0];
    b->basis.m[2][1] = m->m[2][1];
    b->basis.m[2][2] = m->m[2][2];
    b->basis.m[0][3] = m->m[0][3];
    b->basis.m[1][3] = m->m[1][3];
    b->basis.m[2][3] = m->m[2][3];
    if (!b->dirty) {
        F8It_1CE it;
        F8It_1CE end;
        F8It_1CE* pe;
        b->dirty = 1;
        cArray_cXformNodePtr_Begin(&it, b->kids);
        cArray_cXformNodePtr_End(&end, b->kids);
        pe = &end;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&it, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&it));
            cArray_cXformNodePtr_ConstIterator_opInc(&it);
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
static inline void merge_flush_func_001CEE20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE20 */

/* merge_units: begin func_001CEF10 */
#pragma push /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cXformNodePtr_ConstIterator_opInc(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_001CEF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEF10 */

/* merge_units: begin func_001CEF50 */
#pragma push /* merge_units */
typedef struct { void** p; } It_EF50;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x53]; int lA4[3]; } S_EF50;
extern void** std_vector_imp_cXformNodePtr_1_begin(void* v);
extern void** std_vector_imp_cXformNodePtr_1_end(void* v);
extern void std_vector_cXformNodePtr_pointer2iterator(It_EF50* out, void* v, void*** p);
#if 0 /* merge_units */
extern void cArray_cXformNodePtr_Begin(It_EF50* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void cArray_cXformNodePtr_End(It_EF50* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern int cArray_cXformNodePtr_ConstIterator_opNe(It_EF50* a, It_EF50* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((Iter *)(a0), (Iter *)(a1))) /* merge_units */



#if 0 /* merge_units */
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_EF50* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) ((void * *)cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_EF50* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) ((void)cArray_cXformNodePtr_ConstIterator_opInc((Iter *)(a0))) /* merge_units */



void cXformNode_SetNeedsUpdate(S_EF50* o);
static inline int NotEq_EF50(void** a, It_EF50* b) { return !(a == b->p); }
static inline void Mark_EF50(S_EF50* o)
{
    It_EF50 b;
    It_EF50 e;
    if (!o->a50) {
        It_EF50* pe;
        o->a50 = 1;
        cArray_cXformNodePtr_Begin(&b, o->lA4);
        cArray_cXformNodePtr_End(&e, o->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
void cXformNode_SetNeedsUpdate(S_EF50* o)
{
    It_EF50 e;
    It_EF50 tb;
    It_EF50 te;
    void** pb;
    void** pe;
    It_EF50* ep;
    void** it;
    if (!o->a50) {
        o->a50 = 1;
        pb = std_vector_imp_cXformNodePtr_1_begin(o->lA4);
        std_vector_cXformNodePtr_pointer2iterator(&tb, o->lA4, &pb);
        it = tb.p;
        pe = std_vector_imp_cXformNodePtr_1_end(o->lA4);
        std_vector_cXformNodePtr_pointer2iterator(&te, o->lA4, &pe);
        e.p = te.p;
        ep = &e;
        for (; NotEq_EF50(it, ep); it++) {
            Mark_EF50((S_EF50*)*it);
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
static inline void merge_flush_func_001CEF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEF50 */
