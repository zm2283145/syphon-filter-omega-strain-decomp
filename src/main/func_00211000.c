/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00214BD0(int);

int func_00211000(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    func_00214BD0(tmp0);
    return 0;
}
