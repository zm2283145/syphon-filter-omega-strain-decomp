/*
 * SFOGame/Source/tremor: 1 file, 002728F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002728F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_list_deleter_voidPtr_insert(int, int, int, int);

int std_list_cTremorObjPtr_push_back(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = std_list_deleter_voidPtr_insert(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_002728F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002728F0 */
