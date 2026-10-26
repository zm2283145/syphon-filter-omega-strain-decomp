/*
 * main/NetObj: 3 files, 003FC6A0-003FC7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FC6A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc_6)
#pragma pop /* merge_units */
/* merge_units: end func_003FC6A0 */

/* merge_units: begin func_003FC750 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BE3A0[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_7(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BE3A0, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FC750 */

/* merge_units: begin func_003FC7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_003FC7F0(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_2(void) {
}

void* func_003FC810(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FC7F0 */
