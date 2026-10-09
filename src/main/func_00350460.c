/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DEEE0[];
extern int guiTextArrayWidget_ctor(int);

int func_00350460(int a0) {
    int a1, s0, v0, v1;

    s0 = a0;
    v0 = guiTextArrayWidget_ctor(a0);
    v1 = 0 + 110;
    v0 = (int)D_004DEEE0;
    a0 = 0 + 15;
    *(int*)(char*)s0 = v0;
    a1 = 0 + 80;
    *(int*)((char*)s0 + 196) = v1;
    v0 = 0 + 45;
    *(int*)((char*)s0 + 200) = v0;
    v1 = 0 + 50;
    *(int*)((char*)s0 + 204) = v0;
    *(int*)((char*)s0 + 208) = a0;
    v0 = 0 + 20;
    *(int*)((char*)s0 + 212) = v1;
    a0 = 0 + 30;
    *(int*)((char*)s0 + 216) = v1;
    *(int*)((char*)s0 + 220) = v0;
    v1 = 0 + 2;
    *(int*)((char*)s0 + 224) = a1;
    v0 = s0;
    *(int*)((char*)s0 + 228) = a0;
    *(int*)((char*)s0 + 232) = a1;
    *(int*)((char*)s0 + 236) = 0;
    *(int*)((char*)s0 + 192) = 0;
    *(char*)((char*)s0 + 88) = v1;
    v1 = *(unsigned short*)((char*)s0 + 20);
    v1 = v1 | 128;
    *(short*)((char*)s0 + 20) = v1;
    goto ret;
ret:
    return v0;
}
