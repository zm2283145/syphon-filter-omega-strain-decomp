/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00139920(int, int);
extern int func_00183B70(int, int, int);

int func_00183990(int a0) {
    return ((*(int*)((char*)a0 + 8) + (((*(int*)((char*)a0 + 4) << 3) - *(int*)((char*)a0 + 4)) << 4)) + -112);
}

int func_001839B0(int a0, int a1, int a2) {
    return func_00183B70(a0, a1, a2);
}

int func_001839C0(int a0, int a1) {
    return func_00139920(a0, a1);
}

int func_001839D0(char* self) {
    return *(int*)(self + 0);
}

int func_001839E0(char* self) {
    return *(int*)(self + 4);
}
