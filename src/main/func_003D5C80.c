/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001004B0(int, int, int, int, int);
extern int func_003D5AA0(int, int);
extern int func_003D5CD0(int);

int func_003D5C80(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    func_001004B0((a0 + 16), (int)func_003D5CD0, (int)func_003D5AA0, 48, 6);
    return a0;
}
