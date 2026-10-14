/*
 * lib/medius: 2 files, 002CEBB0-002CEBD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CEBB0 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int D_0048C40C = 0xFFFFFF;
extern char D_0048C41C[];

int func_002CEBB0(void) {
    int tmp0;

    tmp0 = *(int*)D_0048C41C;
    return tmp0;
}

int func_002CEBC0(void) {
    int tmp0;

    tmp0 = *(int*)((char*)&D_0048C40C);
    return tmp0;
}
/* merge_units: end func_002CEBB0 */

/* merge_units: begin func_002CEBD0 */
/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern int D_0048C40C;

/* Stores a value into a global setting. */
void func_002CEBD0(int value)
{
    D_0048C40C = value;
}
/* merge_units: end func_002CEBD0 */
