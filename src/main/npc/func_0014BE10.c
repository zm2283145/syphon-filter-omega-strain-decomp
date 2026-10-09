/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0016E170(int, int, int);

int cNPC_v3F(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 244) = tmp0;
    *(int*)((char*)a0 + 312) = -1;
    func_0016E170((a0 + 68), 7, 100);
    return 1;
}

int cNPC_v3E(int a0, int a1) {
    int tmp2;

    func_0016E170((a0 + 68), 7, 100);
    tmp2 = *(int*)((char*)a1 + 120);
    *(int*)((char*)a0 + 312) = tmp2;
    *(int*)((char*)a0 + 244) = -1;
    return 1;
}
