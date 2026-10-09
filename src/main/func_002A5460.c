/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506550[];
extern int func_002A2590(int);

int func_002A5460(void) {
    int tmp0;

    tmp0 = *(int*)D_00506550;
    return func_002A2590(tmp0);
}
