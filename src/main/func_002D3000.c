/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002D7290(int, int, int, int, int, int, int);

int func_002D3000(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_002D7290(tmp0, 43, 8, 0, 0, 0, 0);
}

int func_002D3020(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_002D7290(tmp0, 32, 8, a1, 0, 0, 0);
}
