/*
 * main/GobjMan: 2 files, 003CB910-003CB9C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CB910 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(func_003CB910)
#pragma pop /* merge_units */
/* merge_units: end func_003CB910 */

/* merge_units: begin func_003CB9C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BD1D8[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_003CB9C0(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BD1D8, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB9C0 */
