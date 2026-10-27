/*
 * Libs/SFOLib/Source/ska: 4 files, 003B47E0-003B4960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B47E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

Word* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_003B47E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B47E0 */

/* merge_units: begin func_003B4800 */
#pragma push /* merge_units */
typedef struct { Q q[3]; } Name48_4800;
typedef struct { Name48_4800 key; int val; } Pair_4800;
typedef struct { char pad[0x24]; Tree tree; char vec[4]; int count; } Self_4800;
typedef struct { int node; char ins; } Res_4800;
extern void std_map_cString16N_3_int_cAllocator_pair_end_void_2(Iter* out, Tree* t);
#if 0 /* merge_units */
extern void cAssocArray_cString16N_3_int_Iterator_ctor(Iter* out, Iter* in);
#endif /* merge_units */
Word * cAssocArray_cString16N_3_int_Iterator_ctor(); /* merge_units */

extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(Iter* out, Tree* t, Name48_4800* key);
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR(Res_4800* out, Tree* t, Pair_4800* v);
#if 0 /* merge_units */
extern int std_vector_cSkaNodePtr_push_back(void* v, int* value);
#endif /* merge_units */
int std_vector_cSkaNodePtr_push_back(); /* merge_units */

extern int D_004BCD60;
static inline void QCopy_4800(void* d0, void* s0) { int n = 3; __int128 t; void* s = s0; void* d = d0;
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
static inline Iter* ItCopy_4800(Iter* d, Iter* s) { d->p = s->p; return d; }
#pragma opt_common_subs off
#pragma opt_propagation off
void cSkaAnimationSet_AddNode(int* out, Self_4800* self, Name48_4800* name, int value)
{
    if (value != 0) {
        Iter c;
        Iter e2;
        Iter f;
        Iter e;
        Iter* pc;
        std_map_cString16N_3_int_cAllocator_pair_end_void_2(&e, &self->tree);
        cAssocArray_cString16N_3_int_Iterator_ctor(&e2, &e);
        std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(&f, &self->tree, name);
        if (ItCopy_4800(&c, &f)->p == e2.p) {
            Res_4800 r;
            Pair_4800 q;
            Pair_4800 p;
            Name48_4800 k;
            int n = self->count;
            QCopy_4800(&k, name);
            QCopy_4800(&p.key, &k);
            p.val = n;
            QCopy_4800(&q, &p);
            q.val = p.val;
            std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR(&r, &self->tree, &q);
            std_vector_cSkaNodePtr_push_back(self->vec, &value);
            *out = self->count - 1;
        } else {
            *out = D_004BCD60;
        }
    } else {
        *out = D_004BCD60;
    }
}
static inline void merge_flush_func_003B4800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4800 */

/* merge_units: begin func_003B4960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int std_vector_pod_int_insert(SkaVec* v, char* pos, int n, int value);

/* Append one pointer at the end of the array. */
int std_vector_cSkaNodePtr_push_back(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return std_vector_pod_int_insert(v, data + (count << 2), 1, value);
}

Word* cAssocArray_cString16N_3_int_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString16N_3_int_cAllocator_pair_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_003B4960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4960 */

/* merge_units: begin func_003B49A0 */
#pragma push /* merge_units */
/* cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR: clone a motion node by kind (clip / timed clip / slider / blend),
 * register it under its name and drop it again if the name was already taken. */
#pragma cplusplus on
#include "alloc_guard.h"

struct VC_003B49A0 { virtual int v0(...); };
struct Node_3B49A0 {
    void* vt;
    unsigned char kind;
    char pad5[0x20 - 5];
    int x20;
    char c24[0x34 - 0x24];
    unsigned char b34, b35;
    char pad36[0x50 - 0x36];
    int x50;
    float f54, f58;
    char pad5C[4];
    __int128 q60;
};
struct V4_3B49A0 {
    float x, y, z, w;
    V4_3B49A0() {}
    /* dead xx: retail computes the destination address twice */
    V4_3B49A0(const V4_3B49A0& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); void* xx = this; }
} __attribute__((aligned(16)));

static inline V4_3B49A0 ZeroV_3B49A0() { V4_3B49A0 r; { V4_3B49A0* p = &r; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(p) : "memory"); } return r; }
struct Owner_3B49A0 { char pad[0x54]; int n54; int n58; };
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#if 0 /* merge_units */
void cSkaAnimationSet_AddNode(int* out, Owner_3B49A0* self, void* name, Node_3B49A0* value);
#endif /* merge_units */
#define cSkaAnimationSet_AddNode(a0, a1, a2, a3) (cSkaAnimationSet_AddNode((a0), (Self_4800 *)(a1), (Name48_4800 *)(a2), (int)(a3))) /* merge_units */

Node_3B49A0* cSkaAnim_ctor_cSkaAnimR_eModifier(Node_3B49A0* self, Node_3B49A0* o, unsigned char mode);
Node_3B49A0* cSkaNode_ctor_cSkaNodeR_cQuaternionR(Node_3B49A0* self, Node_3B49A0* src, V4_3B49A0* offset);
void cArray_cSkaBlendSequenceItem_ctor_cArrayR(void* d, void* s);
void cArray_cSkaSwitchItem_ctor_cArrayR(void* d, void* s);
extern char D_004BCD70[];
extern char D_004DFC10[];
extern char D_004DFBF0[];
extern char D_004DFBB0[];
void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(int* out, Owner_3B49A0* owner, void* name, Node_3B49A0* src);
}

static inline void* AllocL_3B49A0(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BCD70, line);
}
static inline int Max_3B49A0(int a, int b) { return a < b ? b : a; }

extern "C" void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(int* out, Owner_3B49A0* owner, void* name, Node_3B49A0* src)
{
    int res;
    Node_3B49A0* n = 0;
    switch (src->kind) {
    case 0:
        {
            Node_3B49A0* p = (Node_3B49A0*)AllocL_3B49A0(0x50, 0x22C);
            if (p) p = cSkaAnim_ctor_cSkaAnimR_eModifier(p, src, 0);
            n = p;
        }
        break;
    case 1:
        n = (Node_3B49A0*)AllocL_3B49A0(0x70, 0x231);
        if (n) {
            cSkaAnim_ctor_cSkaAnimR_eModifier(n, src, 0);
            n->vt = D_004DFC10;
            n->x50 = src->x50;
            n->f54 = src->f54;
            n->f58 = src->f58;
            { __int128* d = &n->q60; const __int128* q = &src->q60; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(q) : "memory"); }
        }
        owner->n54 = Max_3B49A0(n->x50 + 1, owner->n54);
        break;
    case 2:
        n = (Node_3B49A0*)AllocL_3B49A0(0x40, 0x23B);
        if (n) {
            V4_3B49A0 c(ZeroV_3B49A0());
            cSkaNode_ctor_cSkaNodeR_cQuaternionR(n, src, &c);
            n->vt = D_004DFBF0;
            n->x20 = src->x20;
            cArray_cSkaBlendSequenceItem_ctor_cArrayR(n->c24, src->c24);
            n->b34 = src->b34;
            n->b35 = src->b35;
        }
        owner->n54 = Max_3B49A0(n->x20 + 1, owner->n54);
        break;
    case 3:
        n = (Node_3B49A0*)AllocL_3B49A0(0x40, 0x245);
        if (n) {
            V4_3B49A0 c(ZeroV_3B49A0());
            cSkaNode_ctor_cSkaNodeR_cQuaternionR(n, src, &c);
            n->vt = D_004DFBB0;
            n->x20 = src->x20;
            cArray_cSkaSwitchItem_ctor_cArrayR(n->c24, src->c24);
        }
        owner->n58 = Max_3B49A0(n->x20 + 1, owner->n58);
        break;
    }
    cSkaAnimationSet_AddNode(&res, owner, name, n);
    if (res == D_004BCD60 && n) {
        AllocGuard g;
        ((VC_003B49A0*)n)->v0(-1);
        cMemMan_Deallocate(0, n, D_004BCD70, 0x258);
    }
    *out = res;
}
#undef cSkaAnimationSet_AddNode /* merge_units */
static inline void merge_flush_func_003B49A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B49A0 */
