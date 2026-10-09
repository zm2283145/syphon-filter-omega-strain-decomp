/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0010B558(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    *(int*)((char*)tmp0 + 240) = a1;
    return 1;
}

int func_0010B568(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)((char*)tmp0 + 228);
    return tmp1;
}

int func_0010B578(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)((char*)tmp0 + 232);
    return tmp1;
}

int func_0010B588(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    return (tmp0 + 204);
}

int func_0010B598(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    return (tmp0 + 204);
}

int func_0010B5A8(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)((char*)tmp0 + 256);
    *(int*)((char*)tmp0 + 256) = a1;
    return tmp1;
}
