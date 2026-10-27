/*
 * main/scriptManager: 12 files, 003E2A40-003E3140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E2A40 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cGroupPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003E2A40 */

/* merge_units: begin func_003E2B30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_StringPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003E2B30 */

/* merge_units: begin func_003E2C20 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_SymbolTablePtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003E2C20 */

/* merge_units: begin func_003E2CA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int m0; int m4; int m8; } T2CA0;
extern void std_list_deleter_PopVar_erase(int* out, T2CA0* self, int* first, int* last);
extern void operator_delete(void* p);
T2CA0* std_list_PopVar_dtor(T2CA0* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                int r;
                int first;
                int last;
                last = (int)&self->m4;
                first = self->m8;
                std_list_deleter_PopVar_erase(&r, self, &first, &last);
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E2CA0 */

/* merge_units: begin func_003E2D20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern char D_004938D0;
extern char D_00559F18;
extern int std_vector_pod_int_reserve(int, int);

int std_vector_cGroupPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cGroupPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_StringPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_StringPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Byte flag setters. */
void cScriptInterpreter_SetGenerateSyms(int value) {
    D_00559F18 = value;
}

void cScriptInterpreter_SetEnabled(int value) {
    D_004938D0 = value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E2D20 */

/* merge_units: begin func_003E2DA0 */
#pragma push /* merge_units */
#include "int_map_subscript.h"
/* map<int, int>::operator[] */
typedef struct { int key; int a; } P2DA0;
DEFINE_INT_MAP_SUBSCRIPT(func_003E2DA0, P2DA0, std_tree_pair_int_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR_2, v.a = 0)
#pragma pop /* merge_units */
/* merge_units: end func_003E2DA0 */

/* merge_units: begin func_003E2E60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "int_tree_find.h"

/* Find an int key in a tree; end() when absent. */
DEFINE_INT_TREE_FIND(std_tree_pair_int_value_compare_cAllocator_pair_find_intR)
#pragma pop /* merge_units */
/* merge_units: end func_003E2E60 */

/* merge_units: begin func_003E2EE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find an int key in a tree; end() when absent. */
DEFINE_INT_TREE_FIND(std_tree_pair_int_value_compare_find_intR_2)
#pragma pop /* merge_units */
/* merge_units: end func_003E2EE0 */

/* merge_units: begin func_003E2F60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"
DEFINE_RESIZE_ELEMENT(Elem12_2F60, 12)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_EnumField_resize, Elem12_2F60, std_vector_imp_EnumField_insert, std_vector_imp_EnumField_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_003E2F60 */

/* merge_units: begin func_003E2FF0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem4_2FF0, 4)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cObjectId_resize, Elem4_2FF0, std_vector_imp_cObjectId_insert, std_vector_imp_cObjectId_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_003E2FF0 */

/* merge_units: begin func_003E3060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_node_free.h"
extern "C" { char D_004BDC08[] = "allocator.hh"; }
DEFINE_TREE_NODE_FREE(std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_2, D_004BDC08)
#pragma pop /* merge_units */
/* merge_units: end func_003E3060 */

/* merge_units: begin func_003E3140 */
#pragma push /* merge_units */
Map* std_tree_pair_int_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR_2(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3140 */
