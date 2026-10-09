/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00571700[];
extern char D_00571708[];
extern int GObj_IdentityA(int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int func_00408060(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 44);
}

int func_00408070(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 45);
}

int func_00408080(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 40);
    return GObj_IdentityA(tmp1);
}

int func_00408090(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 36);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void func_004080B0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_00571708;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_004080E0(void) {
    return (int)D_00571700;
}

int func_004080F0(void) {
    int tmp0;

    tmp0 = *(int*)D_00571700;
    return tmp0;
}
