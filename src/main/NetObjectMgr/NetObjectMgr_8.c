/*
 * main/NetObjectMgr: 9 files, 004312F0-004313C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004312F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_tree_pair_int_value_compare_node_alloc_void_4(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_6(void) {
}

void* std_tree_pair_int_value_compare_alloc_void_4(void* self) {
    return self;
}

Map* func_00431320(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_3(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_short_value_compare_ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_4(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_5(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_004312F0 */

/* merge_units: begin func_004313C0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_313C0;
extern void func_0042F970(R1Tree_313C0* t, void* n);
extern void operator_delete(void* p);
R1Tree_313C0* std_tree_pair_int_value_compare_dtor_void_2(R1Tree_313C0* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042F970(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004313C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004313C0 */

/* merge_units: begin func_00431420 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431420;
extern void std_tree_pair_int_value_compare_destroy_nodeP_3(R1Tree_00431420* t, void* n);
R1Tree_00431420* std_tree_pair_int_value_compare_dtor_void_3(R1Tree_00431420* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_destroy_nodeP_3(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431420 */

/* merge_units: begin func_00431480 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431480;
extern void std_tree_pair_int_value_compare_destroy_nodeP_4(R1Tree_00431480* t, void* n);
R1Tree_00431480* std_tree_pair_int_value_compare_dtor_void_4(R1Tree_00431480* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_destroy_nodeP_4(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431480 */

/* merge_units: begin func_004314E0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004314E0;
extern void std_tree_pair_int_value_compare_destroy_nodeP_5(R1Tree_004314E0* t, void* n);
R1Tree_004314E0* std_tree_pair_int_value_compare_dtor_void_5(R1Tree_004314E0* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_destroy_nodeP_5(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004314E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004314E0 */

/* merge_units: begin func_00431540 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431540;
typedef struct { R1Tree_00431540 tree; } R1Own_00431540;
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_dtor_void_2(R1Tree_00431540* t, short del);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_dtor_void_2(a0, a1) ((void)std_tree_pair_int_value_compare_dtor_void_2((R1Tree_313C0 *)(a0), (a1))) /* merge_units */


R1Own_00431540* cAssocArray_int_netActivationList_dtor(R1Own_00431540* o, short del)
{
    if (o) {
        R1Tree_00431540* t = &o->tree;
        if (t)
            std_tree_pair_int_value_compare_dtor_void_2(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431540(void) {}
#undef std_tree_pair_int_value_compare_dtor_void_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431540 */

/* merge_units: begin func_004315A0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004315A0;
typedef struct { R1Tree_004315A0 tree; } R1Own_004315A0;
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_dtor_void_3(R1Tree_004315A0* t, short del);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_dtor_void_3(a0, a1) ((void)std_tree_pair_int_value_compare_dtor_void_3((R1Tree_00431420 *)(a0), (a1))) /* merge_units */


R1Own_004315A0* cAssocArray_int_tNetActivateTerrainObjectPtr_dtor(R1Own_004315A0* o, short del)
{
    if (o) {
        R1Tree_004315A0* t = &o->tree;
        if (t)
            std_tree_pair_int_value_compare_dtor_void_3(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004315A0(void) {}
#undef std_tree_pair_int_value_compare_dtor_void_3 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004315A0 */

/* merge_units: begin func_00431600 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00431600;
typedef struct { R1Tree_00431600 tree; } R1Own_00431600;
#if 0 /* merge_units */
extern void std_tree_pair_int_value_compare_dtor_void_4(R1Tree_00431600* t, short del);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_dtor_void_4(a0, a1) ((void)std_tree_pair_int_value_compare_dtor_void_4((R1Tree_00431480 *)(a0), (a1))) /* merge_units */


R1Own_00431600* cAssocArray_int_cMessagePtr_dtor(R1Own_00431600* o, short del)
{
    if (o) {
        R1Tree_00431600* t = &o->tree;
        if (t)
            std_tree_pair_int_value_compare_dtor_void_4(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431600(void) {}
#undef std_tree_pair_int_value_compare_dtor_void_4 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431600 */

/* merge_units: begin func_00431660 */
#pragma push /* merge_units */
typedef struct { void* root; } R1Tree_31660;
typedef struct { R1Tree_31660 tree; } R1Own_31660;
extern void** std_tree_pair_short_value_compare_root(R1Tree_31660* t);
extern void std_tree_pair_short_value_compare_destroy(R1Tree_31660* t, void* n);
static inline void R1TreeDtor_31660(R1Tree_31660* t)
{
    if (*std_tree_pair_short_value_compare_root(t))
        std_tree_pair_short_value_compare_destroy(t, *std_tree_pair_short_value_compare_root(t));
}
R1Own_31660* std_multimap_short_tNetObjectPtr_dtor(R1Own_31660* o, short del)
{
    if (o) {
        R1Tree_31660* t = &o->tree;
        if (t)
            R1TreeDtor_31660(t);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431660 */
