/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float Vec4_GetZ(char* self) {
    return *(float*)(self + 8);
}

float Vec4_GetY(char* self) {
    return *(float*)(self + 4);
}

float Vec4_GetX(char* self) {
    return *(float*)(self + 0);
}
