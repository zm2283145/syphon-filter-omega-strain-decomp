/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_003CA4D0(void* obj, int flags);

void* func_003CAA00(char* self) {
    return self + 4;
}

/* Destroys the object embedded 4 bytes into obj (flags -1) when obj is non-null. */
void func_003CAA10(void* self, char* obj) {
    if (obj != 0) {
        func_003CA4D0(obj + 4, -1);
    }
}

void* func_003CAA40(void* self) {
    return self;
}
