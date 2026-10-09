/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_00182260(void* self, int* it);

/* Iterator dereference (returns *it). */
int func_00181E80(void* self, int* it) {
    return it[0];
}

/* Pass a copy of the iterator to func_00182260. */
int func_00181E90(void* self, int* it) {
    int copy[1];

    copy[0] = it[0];
    return func_00182260(self, copy);
}
