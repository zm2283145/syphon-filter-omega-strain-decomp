/*
 * main/NetObjectMgr: 2 files, 00430A10-00430A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00430A10 */
#pragma push /* merge_units */
#include "types.h"
extern void operator_delete(void* p);
void std_allocator_node_deallocate(int a, void* p) {
    operator_delete(p);
}
#pragma pop /* merge_units */
/* merge_units: end func_00430A10 */

/* merge_units: begin func_00430A20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_00430A20(char* self) {
    return self + 4;
}

void func_00430A30(void) {
}

void* func_00430A40(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00430A20 */
