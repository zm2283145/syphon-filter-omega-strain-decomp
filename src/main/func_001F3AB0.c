/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3B20(int);
extern int func_001F3B50(int);
extern int func_001F3B80(int);
extern int func_001F3BB0(int);

int func_001F3AB0(int a0, int a1, int a2, float f12) {
    func_001F3B20(a0);
    *(float*)((char*)a0 + 16) = f12;
    *(float*)((char*)a0 + 20) = f12;
    *(int*)((char*)a0 + 24) = -1;
    *(char*)((char*)a0 + 28) = a1;
    *(char*)((char*)a0 + 29) = a2;
    *(int*)((char*)a0 + 32) = -1;
    return a0;
}

int func_001F3B20(int a0) {
    func_001F3B50(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}

int func_001F3B50(int a0) {
    func_001F3B80(a0);
    return a0;
}

int func_001F3B80(int a0) {
    func_001F3BB0(a0);
    return a0;
}
