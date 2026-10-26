/*
 * lib/libgraph: 2 files, 00104020-00104058
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00104020 */
typedef struct { int w[5]; } S4020;
extern S4020 D_004E1DB8;
S4020* sceDmaGetEnv(S4020* d)
{
    *d = D_004E1DB8;
    return d;
}
/* merge_units: end func_00104020 */

/* merge_units: begin func_00104058 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int sceDmaPutStallAddr(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)268492896;
    *(int*)((char*)268492896) = a0;
    return tmp0;
}
/* merge_units: end func_00104058 */
