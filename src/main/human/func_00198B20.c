/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00198B20(char* self) {
    return *(int*)(self + 0);
}

int func_00198B30(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (a1 << 5));
}

int func_00198B40(char* self) {
    return *(int*)(self + 4);
}

int func_00198B50(int a0) {
    return (*(int*)(char*)a0 + 8);
}
