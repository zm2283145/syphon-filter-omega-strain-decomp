/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003EE610(int, float);

int func_003E79C0(int a0, float f12) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    func_003EE610(tmp0, (30.0f * f12));
    return 1;
}
