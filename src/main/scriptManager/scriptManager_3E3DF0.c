/*
 * main/scriptManager: 4 files, 003E3DF0-003E3FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E3DF0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tree_insert_v8.h"

extern "C" { char D_004BDBC8[] = "allocator.hh"; }
DEFINE_TREE_INSERT_V8(std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_2, TIValueII, D_004BDA80, D_004BDBC8, 0x5C, std_red_black_tree_1_balance_insert)
#pragma pop /* merge_units */
/* merge_units: end func_003E3DF0 */

/* merge_units: begin func_003E3F60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3F60 */

/* merge_units: begin func_003E3F80 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T3F80;
extern void std_tree_pair_int_value_compare_destroy_nodeP(T3F80* t, void* n);
extern void operator_delete(void* p);
T3F80* cAssocArray_int_SchedCallbackPtr_dtor(T3F80* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_int_value_compare_destroy_nodeP(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3F80 */

/* merge_units: begin func_003E3FF0 */
#pragma push /* merge_units */
extern void std_vector_cGroupPtr_dtor(void* self, short del);
extern void std_vector_StringPtr_dtor(void* self, short del);
extern void std_list_SymbolTablePtr_dtor(void* self, short del);
extern void std_list_PopVar_dtor(void* self, short del);
void* cScriptInterpreter_dtor(void* self, short del)
{
    if (self) {
        void* a = (char*)self + 0x4E4C;
        void* b;
        void* c;
        if (a)
            std_vector_cGroupPtr_dtor(a, -1);
        b = (char*)self + 0x18;
        if (b)
            std_vector_StringPtr_dtor(b, -1);
        c = (char*)self + 0xC;
        if (c)
            std_list_SymbolTablePtr_dtor(c, 0);
        if (self)
            std_list_PopVar_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3FF0 */
