/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float Vec4_GetZ(char* self) {
    return *(float*)(self + 8);
}

float func_00132260(char* self) {
    return *(float*)(self + 4);
}

float func_00132270(char* self) {
    return *(float*)(self + 0);
}
