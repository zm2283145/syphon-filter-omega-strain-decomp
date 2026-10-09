/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00139BD0(Rel*, int, int);

/* Zeroes the three words, then initializes from (a1, a2) via func_00139BD0. */
Rel* func_00136020(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    func_00139BD0(r, a1, a2);
    return r;
}

/* Clears bytes +0x60, +0x62 and words +0x80, +0x84. */
char* func_00136060(char* self) {
    self[96] = 0;
    self[98] = 0;
    *(int*)(self + 128) = 0;
    *(int*)(self + 132) = 0;
    return self;
}
