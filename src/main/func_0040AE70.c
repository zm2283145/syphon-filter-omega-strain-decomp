/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_00138350(void* obj, int flags);

void* func_0040AE70(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void func_0040AE80(void* self, void* obj) {
    if (obj != 0) {
        func_00138350(obj, -1);
    }
}

void* func_0040AEB0(void* self) {
    return self;
}
