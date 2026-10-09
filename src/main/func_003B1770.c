/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void** PtrStack_Top(PtrStack* s) {
    return &s->items[s->count - 1];
}

int func_003B1790(char* self) {
    return *(int*)(self + 0);
}

float func_003B17A0(char* self) {
    return *(float*)(self + 8);
}

int func_003B17B0(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (((a1 << 4) - a1) << 2));
}
