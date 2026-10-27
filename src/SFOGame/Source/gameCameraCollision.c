/*
 * SFOGame/Source/gameCameraCollision: 2 files, 0020C8E0-0020C910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020C8E0 */
#pragma push /* merge_units */
#include "types.h"
#pragma optimization_level 1

extern void cSkaSwitchItem_dtor(int, int);

/* Calls cSkaSwitchItem_dtor(b, -1). */
void cAllocator_cSkaSwitchItem_destroy(int a, int b) {
    cSkaSwitchItem_dtor(b, -1);
}
static inline void merge_flush_func_0020C8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020C8E0 */

/* merge_units: begin func_0020C910 */
#pragma push /* merge_units */
#include "o1_tree_dtor.h"
#pragma optimization_level 1
DEFINE_O1_TREE_DTOR(std_vector_deleter_cSkaSwitchItem_dtor, std_vector_deleter_cSkaSwitchItem_clear, std_vector_deleter_cSkaSwitchItem_data, std_vector_deleter_cSkaSwitchItem_alloc_void, std_vector_deleter_cSkaSwitchItem_cap_void, cAllocator_cSkaSwitchItem_deallocate)
#pragma optimization_level reset
static inline void merge_flush_func_0020C910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020C910 */
