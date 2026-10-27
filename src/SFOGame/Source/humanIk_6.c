/*
 * SFOGame/Source/humanIk: 2 files, 001CEA70-001CEA90
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
void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(MIter* out, void* t);
MIter* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(MIter* d, MIter* s);
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
static inline void merge_flush_func_001CEA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEA90 */
