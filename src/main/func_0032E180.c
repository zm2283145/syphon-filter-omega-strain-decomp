/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int func_001314F0(int, int);
extern int func_00333B90(int, int, int);

int func_0032E180(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = func_001314F0((int)D_004FFB50, -1);
    tmp2 = func_00333B90(tmp0, a0, 1);
    return tmp2;
}
