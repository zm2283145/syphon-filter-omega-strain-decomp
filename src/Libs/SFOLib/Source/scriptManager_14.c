/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003DFB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DFB20 */
#pragma push /* merge_units */
#include "types.h"
#pragma bool off
typedef struct { char pad[0x10]; void* event; } SchNode_c7;
typedef struct { SchNode_c7* p; } SchIt_c7;
extern char D_0055A0F0[];
extern void std_tree_pair_int_value_compare_begin_void(SchIt_c7* out, void* map);
extern void std_map_int_SchedCallbackPtr_end(SchIt_c7* out, void* map);
extern SchIt_c7* cAssocArray_int_SchedCallbackPtr_Iterator_ctor(SchIt_c7* dst, SchIt_c7* src);
extern void nCallback_RemoveCallback(void* ev);
extern void std_red_black_tree_1_increment(SchIt_c7* it);
extern void std_tree_pair_int_value_compare_erase_tree_2(void* map, SchIt_c7* it);
static inline int IsZero_c7(int x) { return x == 0; }
static inline int ItNe_c7(SchIt_c7* a, SchIt_c7* b) { return (a->p == b->p) ^ 1; }
void Script_ClearSchedules_3DFB20(void) {
    SchIt_c7 it;
    SchIt_c7 end;
    SchIt_c7 b;
    SchIt_c7 tmp;
    SchIt_c7 e;
    std_tree_pair_int_value_compare_begin_void(&b, D_0055A0F0);
    it.p = b.p;
    while (std_map_int_SchedCallbackPtr_end(&e, D_0055A0F0), cAssocArray_int_SchedCallbackPtr_Iterator_ctor(&end, &e), ItNe_c7(&it, &end)) {
        SchNode_c7* old;
        nCallback_RemoveCallback(it.p->event);
        old = it.p;
        std_red_black_tree_1_increment(&it);
        tmp.p = old;
        std_tree_pair_int_value_compare_erase_tree_2(D_0055A0F0, &tmp);
    }
}
static inline void merge_flush_func_003DFB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DFB20 */
