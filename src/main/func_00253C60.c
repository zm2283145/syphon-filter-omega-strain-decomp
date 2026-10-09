/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7EB8[];
extern char D_004F7EF8[];
extern char D_004F7F78[];
extern char D_004F7F80[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_00253C80(void);
extern int func_00253DD0(int, int, int, int);
extern int func_002570C0(void);
extern int func_003CC830(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);

int func_00253C60(void) {
    func_00253C80();
    return 0;
}

int func_00253C80(void) {
    return func_002570C0();
}

int func_00253C90(int a0) {
    unsigned char tmp0;
    unsigned char tmp1;
    unsigned char tmp2;
    int tmp3;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(unsigned char*)((char*)a0 + 8);
    tmp2 = *(unsigned char*)((char*)a0 + 12);
    tmp3 = *(int*)(char*)a0;
    func_00253DD0(tmp3, tmp0, tmp1, tmp2);
    return 0;
}

int func_00253CC0(int a0) {
    unsigned char tmp0;
    unsigned char tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(unsigned char*)((char*)a0 + 8);
    tmp2 = *(int*)(char*)a0;
    func_00253DD0(tmp2, tmp0, tmp1, 8);
    return 0;
}

int func_00253CF0(int a0) {
    unsigned char tmp0;
    int tmp1;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    func_00253DD0(tmp1, tmp0, 8, 8);
    return 0;
}

int func_00253D20(int a0) {
    *(char*)((char*)*(int*)(char*)a0 + 752) = ((unsigned int)(0) < (unsigned int)(*(int*)((char*)a0 + 4)));
    return 0;
}

int func_00253D40(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp10;
    int tmp11;
    int tmp12;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F7F80;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = *(int*)D_004F7F80;
    tmp7 = *(int*)D_004F7EB8;
    func_003D9400(tmp6, tmp7);
    tmp10 = *(int*)D_004F7F80;
    tmp11 = *(int*)D_004F7EF8;
    tmp12 = func_003D9400(tmp10, tmp11);
    return tmp12;
}

int func_00253DA0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7F78;
    return tmp0;
}

int func_00253DB0(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
