/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F30A0(int);
extern int func_001F30D0(int);
extern int func_001F3100(int);

void* func_001F3060(void* self) {
    return self;
}

int func_001F3070(int a0) {
    func_001F30A0(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}

int func_001F30A0(int a0) {
    func_001F30D0(a0);
    return a0;
}

int func_001F30D0(int a0) {
    func_001F3100(a0);
    return a0;
}
