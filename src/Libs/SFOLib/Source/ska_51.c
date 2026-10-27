/*
 * Libs/SFOLib/Source/ska: 3 files, 003B4540-003B4640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B4540 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct ClipHdr { int f0; unsigned int n4; int f8; float fC; void* p10; };
struct SkaClip {
    void* vt;
    unsigned char b4;
    V v10;
    int f20;
    ClipHdr* clip;
    unsigned char b28, b29;
    float f2c, f30, f34, f38;
    float f3c;
    int f40;
    unsigned char b44, b45, b46;
};
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimDataR(SkaClip* self, ClipHdr* c)
{
    V t = Unit();
    self->vt = D_004DFC50;
    self->b4 = 0;
    self->v10 = t;
    self->vt = (void*)D_004DFC30;
    self->f20 = 0;
    self->clip = c;
    self->b28 = 0;
    self->b29 = 0;
    self->f2c = 0.0f;
    self->f30 = 1.0f;
    self->f34 = 0.0f;
    self->f38 = 1.0f;
    { ClipHdr* h = self->clip; self->f3c = (float)h->n4 * h->fC; }
    self->f40 = -1;
    self->b44 = 0;
    self->b45 = c->p10 != 0;
    self->b46 = 0;
    return self;
}
static inline void merge_flush_func_003B4540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4540 */

/* merge_units: begin func_003B4630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Reset a handle to {0, -1}. */
void cSkaNode_PlaybackGroupId(SkaHandle* h) {
    h->unk0 = 0;
    h->index = -1;
}
static inline void merge_flush_func_003B4630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4630 */

/* merge_units: begin func_003B4640 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { Q q[2]; } Name32_4640;
typedef struct { int a, b, c; } Val_4640;
typedef struct { Name32_4640 key; Val_4640* val; } Pair_4640;
typedef struct { char pad[0x44]; Tree tree; } Self_4640;
typedef struct { int node; char ins; } Res_4640;
extern "C" void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_end(Iter* out, Tree* t);
extern "C" void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(Iter* out, Iter* in);
extern "C" void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(Iter* out, Tree* t, Name32_4640* key);
extern "C" void std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR_2(Res_4640* out, Tree* t, Pair_4640* v);
extern "C" void* cMemMan_Allocate(int a, int size, char* file, int line);
extern "C" char D_004BCD70;
static inline void QCopy_4640(void* d0, void* s0) { int n = 2; __int128 t; void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline Iter* ItCopy_4640(Iter* d, Iter* s) { d->p = s->p; return d; }
static inline int End_4640(Iter* out, Tree* t) { Iter e; std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_end(&e, t); cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(out, &e); return 0; }
static inline Iter* Sel_4640(Iter* a, int b) { return a; }
static inline Iter* Find_4640(Iter* out, Tree* t, Name32_4640* n) { Iter f; std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(&f, t, n); return ItCopy_4640(out, &f); }
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void cSkaAnimationSet_CreateAnimationBlend(Self_4640* self, Name32_4640* name, Val_4640* src)
{
    Iter c;
    Iter e2;
    if (Sel_4640(Find_4640(&c, &self->tree, name), End_4640(&e2, &self->tree))->p == e2.p) {
        Res_4640 r;
        Pair_4640 q;
        Pair_4640 p;
        Name32_4640 k;
        Val_4640* v;
        {
            AllocGuard g;
            v = (Val_4640*)cMemMan_Allocate(0, 0xC, &D_004BCD70, 0x27D);
        }
        if (v != 0) {
            v->a = src->a;
            v->b = src->b;
            v->c = src->c;
        }
        QCopy_4640(&k, name);
        QCopy_4640(&p.key, &k);
        p.val = v;
        QCopy_4640(&q, &p);
        q.val = p.val;
        std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR_2(&r, &self->tree, &q);
    }
}
static inline void merge_flush_func_003B4640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4640 */
