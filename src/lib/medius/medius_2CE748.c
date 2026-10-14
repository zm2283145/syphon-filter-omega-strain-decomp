/*
 * lib/medius: 2 files, 002CE748-002CE758
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CE748 */
#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern int D_0051EFA0;

/* Stores a value into a global setting. */
void func_002CE748(int value)
{
    D_0051EFA0 = value;
}
/* merge_units: end func_002CE748 */

/* merge_units: begin func_002CE758 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char D_0051EFA0[];
#endif /* merge_units */
#define D_0051EFA0 ((char*)&D_0051EFA0) /* merge_units */


int func_002CE758(void) {
    int tmp0;

    tmp0 = *(int*)D_0051EFA0;
    return tmp0;
}
#undef D_0051EFA0 /* merge_units */
/* merge_units: end func_002CE758 */
