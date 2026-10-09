/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C50A0(int, int);
extern int func_001E0EF0(int);
extern int func_001E0FE0(int, int);

int func_001E0EA0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return (tmp1 + (tmp0 * 96));
}

void func_001E0EC0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001E0ED0(char* self) {
    return *(int*)(self + 8);
}

int func_001E0EE0(int a0) {
    return func_001E0EF0(a0);
}

int func_001E0EF0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    *(int*)((char*)a0 + 4) = (tmp0 + -1);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_001E0FE0((tmp1 + ((tmp0 + -1) << 4)), -1);
}

int func_001E0F10(int a0, int a1) {
    unsigned char tmp2;

    func_001C50A0(a0, a1);
    tmp2 = *(unsigned char*)((char*)a1 + 12);
    *(char*)((char*)a0 + 12) = tmp2;
    return a0;
}

int func_001E0F50(int a0) {
    return ((*(int*)((char*)a0 + 8) + (*(int*)((char*)a0 + 4) << 4)) + -16);
}
