/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0023DAD0(void* self, int flag);

/* True when index is below the count returned by func_0023DAD0(self, 1). */
int func_0023DD70(void* self, int index) {
    int count = func_0023DAD0(self, 1);
    return index < count;
}
