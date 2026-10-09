/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0016E170(int, int, int);

int func_0015AC70(int a0) {
    *(int*)((char*)a0 + 4) = -2;
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 8) = -1;
    return a0;
}

int func_0015AC90(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

void* func_0015ACA0(void* self) {
    return self;
}

void* func_0015ACB0(void* self) {
    return self;
}

void* func_0015ACC0(void* self) {
    return self;
}

int func_0015ACD0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_0016E170(a0, 0, 0);
    return a0;
}
