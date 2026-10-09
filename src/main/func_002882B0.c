/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern char D_004FFC04[];
extern int func_001314F0(int, int);
extern int func_00288310(int, int);
extern int func_002C9AF0(int, int);
extern int func_003361B0(int);
extern int func_0041EFA0(int);

int func_002882B0(int a0) {
    int tmp2;
    int tmp6;
    int tmp9;

    func_0041EFA0(a0);
    tmp2 = func_001314F0((int)D_004FFB50, -1);
    func_003361B0(tmp2);
    tmp6 = *(int*)D_004FFC04;
    func_002C9AF0(tmp6, 0);
    tmp9 = func_00288310(a0, 0);
    return tmp9;
}
