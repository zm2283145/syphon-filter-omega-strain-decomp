/*
 * Libs/SFOLib/Source/ska: 8 files, 003B43C0-003B47E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B43C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct F2 { float a, b; F2() {} };
struct ClipBase {
    void* vt;
    signed char b4;
    V v10;
    ClipBase() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ClipBase() { vt = D_004DFC50; }
    ClipBase& operator=(const ClipBase& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip : ClipBase {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip() { vt = (void*)D_004DFC30; }
};
static inline void Base(SkaClip* s, signed char b, V v) { s->vt = D_004DFC50; s->b4 = b; s->v10 = v; }
struct Item { void* vt; unsigned char b4; };
struct NMap { char pad[0x34]; int reg; };
extern "C" int cSkaAnimationSet_GetNodeId(NMap* m, void* name);
extern "C" SkaClip** cArray_cSkaNodePtr_opIndex(int* reg, int idx);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_int_eAxisOfMotion(SkaClip* d, void* c, int a, int b);
extern "C" SkaClip* cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_int_eAxisOfMotion(SkaClip* self, void* name, NMap* m, int a, int b)
{
    SkaClip* c;
    Base(self, 0, Unit());
    self->vt = (void*)D_004DFC30;
    self->clip = 0;
    self->r2c.a = 0.0f;
    self->r2c.b = 1.0f;
    c = *cArray_cSkaNodePtr_opIndex(&m->reg, cSkaAnimationSet_GetNodeId(m, name));
    if (!((Item*)c)->b4) {
        SkaClip t;
        cSkaAnim_ctor_cSkaAnimR_int_eAxisOfMotion(&t, c, a, b);
        *self = t;
    }
    return self;
}
static inline void merge_flush_func_003B43C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B43C0 */

/* merge_units: begin func_003B4540 */
#pragma push /* merge_units */
#pragma cplusplus on

struct ClipHdr { int f0; unsigned int n4; int f8; float fC; void* p10; };
struct SkaClip_003B4540 {
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
extern "C" SkaClip_003B4540* cSkaAnim_ctor_cSkaAnimDataR(SkaClip_003B4540* self, ClipHdr* c)
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
typedef struct { Q q[2]; } Name32_4640;
typedef struct { int a, b, c; } Val_4640;
typedef struct { Name32_4640 key; Val_4640* val; } Pair_4640;
typedef struct { char pad[0x44]; Tree tree; } Self_4640;
typedef struct { int node; char ins; } Res_4640;
extern "C" void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_end(Iter* out, Tree* t);
#if 0 /* merge_units */
extern "C" void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(Iter* out, Iter* in);
#endif /* merge_units */
extern "C" Word* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(Word* dst, Word* src); /* merge_units */
#define cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(a0, a1) ((void)cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

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
#undef cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor /* merge_units */
static inline void merge_flush_func_003B4640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4640 */

/* merge_units: begin func_003B47E0 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#if 0 /* merge_units */
void cSkaAnimationSet_AddNode(int* out, Owner_3B49A0* self, void* name, Node_3B49A0* value);
#endif /* merge_units */
#define cSkaAnimationSet_AddNode(a0, a1, a2, a3) (cSkaAnimationSet_AddNode((a0), (Self_4800 *)(a1), (Name48_4800 *)(a2), (int)(a3))) /* merge_units */


Node_3B49A0* cSkaAnim_ctor_cSkaAnimR_eModifier(Node_3B49A0* self, Node_3B49A0* o, unsigned char mode);
Node_3B49A0* cSkaNode_ctor_cSkaNodeR_cQuaternionR(Node_3B49A0* self, Node_3B49A0* src, V4_3B49A0* offset);
void cArray_cSkaBlendSequenceItem_ctor_cArrayR(void* d, void* s);
void cArray_cSkaSwitchItem_ctor_cArrayR(void* d, void* s);
#if 0 /* merge_units */
extern char D_004BCD70[];
#endif /* merge_units */
#define D_004BCD70 ((char*)&D_004BCD70) /* merge_units */

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
#undef cMemMan_Allocate /* merge_units */
#undef cSkaAnimationSet_AddNode /* merge_units */
#undef D_004BCD70 /* merge_units */
static inline void merge_flush_func_003B49A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B49A0 */
