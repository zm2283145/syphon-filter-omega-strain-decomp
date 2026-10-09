/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00103BE8(unsigned int*);

/* mode 1: return bit 8 of the first word; otherwise call func_00103BE8 and return 0. */
int func_00104310(unsigned int* a0, int mode) {
    if (mode == 1) {
        return (*a0 >> 8) & 1;
    }
    func_00103BE8(a0);
    return 0;
}
