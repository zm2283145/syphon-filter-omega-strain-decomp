/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00285590(int, int);
extern int func_003CC820(int);

int func_002830F0(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)a0 + 4);
    tmp2 = func_003CC820(tmp1);
    func_00285590(tmp0, tmp2);
    return 0;
}
