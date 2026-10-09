/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Scope_GetParent(char* self) {
    return *(int*)(self + 0);
}

int Object_GetScope(char* self) {
    return *(int*)(self + 28);
}
