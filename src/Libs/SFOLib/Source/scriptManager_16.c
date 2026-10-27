/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003DFC40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003DFC40 */
#pragma push /* merge_units */
#pragma bool off
#include "types.h"

typedef struct ResNodeE6 {
    char pad[0x10];
    int* timer;
} ResNodeE6;

typedef struct ResIterE6 { ResNodeE6* node; } ResIterE6;

extern char D_0055A0F0[];
extern void std_tree_pair_int_value_compare_find_intR_2(ResIterE6* out, void* map, int* key);
extern void std_map_int_SchedCallbackPtr_end(ResIterE6* out, void* map);
extern void cAssocArray_int_SchedCallbackPtr_Iterator_ctor(ResIterE6* out, ResIterE6* in);

static inline int IsZeroE6(int x) { return x == 0; }
static inline int IterE6_Ne(ResNodeE6* a, ResNodeE6* b) { return (a == b) ^ 1; }

/* Reschedules a registered script timer to fire after the given seconds. */
void Script_Reschedule_3DFC40(int id, float seconds)
{
    ResIterE6 cend;
    ResIterE6 it;
    ResIterE6 end;
    int key[1];
    ResNodeE6* node;
    key[0] = id;
    std_tree_pair_int_value_compare_find_intR_2(&it, D_0055A0F0, key);
    node = it.node;
    std_map_int_SchedCallbackPtr_end(&end, D_0055A0F0);
    cAssocArray_int_SchedCallbackPtr_Iterator_ctor(&cend, &end);
    if (IterE6_Ne(node, cend.node)) {
        *node->timer = (int)(1000.0f * seconds);
    }
}
static inline void merge_flush_func_003DFC40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003DFC40 */
