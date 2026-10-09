/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void ControlHistory_Clear(char* self) {
    *(int*)(self + 8) = 0;
}

void ControlHistory_Shift(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)a0 + 4);
    *(int*)((char*)a0 + 4) = *(int*)((char*)a0 + 8);
}
