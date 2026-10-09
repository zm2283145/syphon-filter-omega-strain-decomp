/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003C0F30(int a0, int a1) {
    return *(unsigned short*)((char*)((a1 << 1) + a0) + 4);
}

int func_003C0F40(char* self) {
    return *(int*)(self + 4);
}

void* func_003C0F50(char* self) {
    return self + 8;
}

void* func_003C0F60(char* self) {
    return self + 11;
}
