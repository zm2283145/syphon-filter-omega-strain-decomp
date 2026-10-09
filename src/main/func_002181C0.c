/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002181C0(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (a1 << 4));
}

int func_002181D0(char* self) {
    return *(int*)(self + 4);
}

int* func_002181E0(PtrVec* v, int i) {
    return v->data + i;
}

int func_002181F0(char* self) {
    return *(int*)(self + 4);
}
