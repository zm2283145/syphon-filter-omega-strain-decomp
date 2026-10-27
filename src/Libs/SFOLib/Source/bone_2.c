/*
 * Libs/SFOLib/Source/bone: 5 files, 003BA0C0-003BA210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BA0C0 */
#pragma push /* merge_units */
typedef struct Deq { unsigned int cap; unsigned int size; unsigned int start; int* data; } Deq;

extern void Libc_Fprintf(int, const char*);
extern void Libc_Abort(void);
extern char* D_00489738;
extern unsigned int D_004BCEE8[2];
extern signed char D_00542C90;

static inline unsigned int MaxSize(void) {
    int size[1];
    int ref;
    if (D_00542C90 == 0) {
        ref = (int)size;
        size[0] = 0x1800000;
        ref = *(int*)ref;
        D_00542C90 = 1;
        (*(int*)D_004BCEE8) = ref - 1;
    }
    return (*(int*)D_004BCEE8);
}

unsigned int _cdeque_deleter_common_int_suggest_new_cap(Deq* self, unsigned int n)
{
    unsigned int m = MaxSize();
    unsigned int c;
    if (m < n) {
        Libc_Fprintf(*(int*)(D_00489738 + 0xC), "cdeque max_size error");
        Libc_Abort();
    }
    c = self->cap ? self->cap - 1 : 1;
    while (n > c) {
        if (c < m / 2) c *= 2; else c = m;
    }
    return c;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA0C0 */

/* merge_units: begin func_003BA1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* 4x4 matrix constructor filling every row with one vector: the explicit do/while walk is the empty V ctor loop over the rows,
   the goto loop reproduces retail's jump-to-test copy loop; lq/sq quad copy as asm. */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));
static inline void QCopy(V* pd, const V* ps) { __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
struct M {
    V r[4];
};
#pragma push
#pragma opt_unroll_loops off
extern "C" M* cArray_FixedSize_cVector_4_ctor_cVectorR(M* d, const V* s)
{
    V* p = d->r;
    V* e = d->r + 4;
    do { p++; } while (p != e);
    {
        int i = 0;
        goto test;
    loop:
        QCopy(&d->r[(unsigned)i], s);
        i++;
    test:
        if (i <= 3) goto loop;
    }
    return d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA1B0 */

/* merge_units: begin func_003BA210 */
#pragma push /* merge_units */
#include "types.h"
#include "ska_types.h"

SkaRelFlag* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(SkaRelFlag* self); /* gsynth: defined below */
typedef struct TmpB0 {
    char b[0xB0];
} TmpB0;

typedef struct ObjB0 {
    char pad[0xB0];
    int unkB0;
    char sub[4];
} ObjB0;

extern void cSkaAnimAnchor_TreeNodeData_ctor_void(TmpB0*);
extern void cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(ObjB0*, TmpB0*);
#if 0 /* merge_units */
extern void cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(void*);
#endif /* merge_units */
#define cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(a0) ((void)cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void((SkaRelFlag *)(a0))) /* merge_units */



/* Constructor: initializes from a default temporary and sets up the sub-object at +0xB4. */
ObjB0* cSkaAnimAnchor_TreeNode_ctor_void(ObjB0* o) {
    TmpB0 tmp;
    cSkaAnimAnchor_TreeNodeData_ctor_void(&tmp);
    cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR(o, &tmp);
    o->unkB0 = 0;
    cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(o->sub);
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA210(void) {}
#undef cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA210 */

/* merge_units: begin func_003BA260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern Rel* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(Rel* r);

/* Construct: zero the three words and set the flag byte. */
SkaRelFlag* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void(SkaRelFlag* self) {
    std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA260 */

/* merge_units: begin func_003BA290 */
#pragma push /* merge_units */
Rel* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA290(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA290 */
