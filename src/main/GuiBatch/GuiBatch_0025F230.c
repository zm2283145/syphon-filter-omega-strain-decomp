/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_0025F270(int*, int, int);

/* Calls func_0025F270(self, a1, 1) when the state is 1 or 2. */
void func_0025F230(int* self, int a1) {
    int state = *self;

    if (state == 1 || state == 2) {
        func_0025F270(self, a1, 1);
    }
}
