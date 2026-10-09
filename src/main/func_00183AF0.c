/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00183B60(int, int);

int func_00183AF0(void* self, char* p) {
    return *(int*)(p + 0);
}

unsigned char Triangle_GetSurface(Tri* t) {
    return t->b10 >> 1;
}

int func_00183B10(void* self, char* p) {
    return *(int*)(p + 0);
}

int func_00183B20(void* self, char* p) {
    return *(int*)(p + 0);
}

int func_00183B30(int a0, int a1) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a1;
    *(int*)(char*)loc = v0;
    a1 = (int)loc;
    v0 = func_00183B60(a0, a1);
    goto ret;
ret:
    return v0;
}
