/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005721B0[];
extern char D_005724B8[];
extern int func_002EBC48(int);

int func_0042B850(int a0) {
    *(char*)D_005721B0 = 0;
    func_002EBC48((int)D_005724B8);
    return a0;
}
