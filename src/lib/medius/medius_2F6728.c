/*
 * lib/medius: 2 files, 002F6728-002F6758
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F6728 */
#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { void* ptr; int pad; } Arg;
extern int func_002FB3C0(Arg* arg);

/* Returns 2 for NULL, else whether func_002FB3C0 succeeded (non-zero). */
int func_002F6728(void* ptr)
{
    Arg arg;
    int r = 2;
    arg.ptr = ptr;
    if (ptr != 0)
        r = func_002FB3C0(&arg) != 0;
    return r;
}
/* merge_units: end func_002F6728 */

/* merge_units: begin func_002F6758 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_002F6758(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 == 0;
    v0 = 0 + 2;
    if (cond) goto L002F6768;
    *(int*)(char*)a1 = a0;
    v0 = 0;
L002F6768:;
    goto ret;
ret:
    return v0;
}
/* merge_units: end func_002F6758 */
