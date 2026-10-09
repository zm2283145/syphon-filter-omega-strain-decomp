/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0016C1E0(int, int, int);
extern int func_003CE850(int, int);

int func_0014AFC0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 428);
    return func_0016C1E0(tmp0, a1, 1);
}

int func_0014AFD0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_003CE850(tmp0, 0);
}
