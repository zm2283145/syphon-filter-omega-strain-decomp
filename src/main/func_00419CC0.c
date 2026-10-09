/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_00138350(void* obj, int flags);

void* func_00419CC0(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void func_00419CD0(void* self, void* obj) {
    if (obj != 0) {
        func_00138350(obj, -1);
    }
}

void* func_00419D00(void* self) {
    return self;
}
