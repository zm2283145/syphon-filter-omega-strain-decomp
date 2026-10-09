/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00238970(int);

int func_00238940(int a0) {
    func_00238970(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
