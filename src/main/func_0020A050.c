/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* func_00209F60(void*);

char* func_0020A050(void* self) {
    return func_00209F60(self) + 8;
}

void* func_0020A070(void* self) {
    return self;
}
