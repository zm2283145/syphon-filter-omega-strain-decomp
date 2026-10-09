/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_00138350(void* obj, int flags);

void* func_0040A830(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void func_0040A840(void* self, void* obj) {
    if (obj != 0) {
        func_00138350(obj, -1);
    }
}

void* func_0040A870(void* self) {
    return self;
}
