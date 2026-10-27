/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int WaitDma(unsigned int*);

/* mode 1: return bit 8 of the first word; otherwise call WaitDma and return 0. */
int sceDmaSync_2(unsigned int* a0, int mode) {
    if (mode == 1) {
        return (*a0 >> 8) & 1;
    }
    WaitDma(a0);
    return 0;
}
