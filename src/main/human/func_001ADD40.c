/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001ADD40(char* self) {
    return self + 60;
}

int func_001ADD50(char* self) {
    return *(int*)(self + 0);
}

void* func_001ADD60(char* self) {
    return self + 48;
}

void* func_001ADD70(char* self) {
    return self + 36;
}

int func_001ADD80(char* self) {
    return *(unsigned int*)(self + 48) != 0;
}
