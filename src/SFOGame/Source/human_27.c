/*
 * SFOGame/Source/human: 2 files, 0018A660-0018A670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0018A660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* cArray_cSkaNodePtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0018A660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A660 */

/* merge_units: begin func_0018A670 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int value; } Node_18A670;
typedef struct { Node_18A670* n; } It_18A670;
typedef struct { char pad[0x24]; int tree; } Map_18A670;
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(It_18A670* out, int* tree, int key);
extern void std_map_cString16N_3_int_cAllocator_pair_end_void(It_18A670* out, int* tree);
extern void cAssocArray_cString16N_3_int_ConstIterator_ctor(It_18A670* out, It_18A670* in);
int cSkaAnimationSet_GetNodeId(Map_18A670* m, int key)
{
    It_18A670 c;
    It_18A670 f;
    It_18A670 e;
    Node_18A670* n;
    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(&f, &m->tree, key);
    n = f.n;
    std_map_cString16N_3_int_cAllocator_pair_end_void(&e, &m->tree);
    cAssocArray_cString16N_3_int_ConstIterator_ctor(&c, &e);
    if (n == c.n) return 0;
    return n->value;
}
static inline void merge_flush_func_0018A670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A670 */
