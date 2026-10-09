/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002DEA68(int value);

int func_002E74C0(int a0, int a1, int a2, unsigned short* a3) {
    int result = -1;

    if (a3 != 0) {
        func_002DEA68(*a3);
        result = 2;
    }
    return result;
}
