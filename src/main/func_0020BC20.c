/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0020BC50(int, int, int);
extern int func_0020BC90(int);

int func_0020BC20(int a0, int a1, int a2) {
    func_0020BC50(a0, a1, a2);
    return a0;
}

int func_0020BC50(int a0, int a1, int a2) {
    func_0020BC90(a0);
    *(int*)((char*)a0) = a2;
    return a0;
}
