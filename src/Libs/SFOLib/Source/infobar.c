/*
 * Libs/SFOLib/Source/infobar: 2 files, 003F9E20-003F9E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9E20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(char* self) {
    return self + 4;
}
static inline void merge_flush_func_003F9E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9E20 */

/* merge_units: begin func_003F9E30 */
#pragma push /* merge_units */
extern void cInterfaceElement_Activate(int, int);

void cInfoBar_SetVisible(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 1288);
    cond = a0 == 0;
    if (cond) goto L003F9E50;
    cInterfaceElement_Activate(a0, a1);
L003F9E50:;
    goto ret;
ret:;
}
static inline void merge_flush_func_003F9E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9E30 */
