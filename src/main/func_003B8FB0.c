/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001004B0(int, int, int, int, int);
extern int func_0018A210(int, int);
extern int func_0018A870(int);

int func_003B8FB0(int a0, int a1) {
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;
    int tmp6;
    int tmp7;
    int tmp8;
    int tmp9;
    int tmp10;
    int tmp11;
    int tmp12;
    int tmp13;
    int tmp14;
    int tmp15;

    func_001004B0(a0, (int)func_0018A870, (int)func_0018A210, 8, 7);
    tmp2 = *(int*)(char*)a1;
    *(int*)((char*)a0) = tmp2;
    tmp3 = *(int*)((char*)a1 + 4);
    *(int*)((char*)a0 + 4) = tmp3;
    tmp4 = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0 + 8) = tmp4;
    tmp5 = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 12) = tmp5;
    tmp6 = *(int*)((char*)a1 + 16);
    *(int*)((char*)a0 + 16) = tmp6;
    tmp7 = *(int*)((char*)a1 + 20);
    *(int*)((char*)a0 + 20) = tmp7;
    tmp8 = *(int*)((char*)a1 + 24);
    *(int*)((char*)a0 + 24) = tmp8;
    tmp9 = *(int*)((char*)a1 + 28);
    *(int*)((char*)a0 + 28) = tmp9;
    tmp10 = *(int*)((char*)a1 + 32);
    *(int*)((char*)a0 + 32) = tmp10;
    tmp11 = *(int*)((char*)a1 + 36);
    *(int*)((char*)a0 + 36) = tmp11;
    tmp12 = *(int*)((char*)a1 + 40);
    *(int*)((char*)a0 + 40) = tmp12;
    tmp13 = *(int*)((char*)a1 + 44);
    *(int*)((char*)a0 + 44) = tmp13;
    tmp14 = *(int*)((char*)a1 + 48);
    *(int*)((char*)a0 + 48) = tmp14;
    tmp15 = *(int*)((char*)a1 + 52);
    *(int*)((char*)a0 + 52) = tmp15;
    return a0;
}
