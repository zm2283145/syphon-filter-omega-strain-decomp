/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC820(int);

int func_0015B430(int a0) {
    int tmp0;
    int tmp3;

    tmp0 = *(int*)((char*)a0 + 4);
    func_003CC820(tmp0);
    tmp3 = *(int*)(char*)a0;
    func_003CC820(tmp3);
    return 0;
}
