/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00535D20[];
extern int func_00373670(int);
extern int func_0041E470(int);

int func_002A2EC0(int a0) {
    int tmp2;

    func_00373670((int)D_00535D20);
    tmp2 = func_0041E470(a0);
    return tmp2;
}
