/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004D9810[];
extern char D_004D9870[];
extern char D_004EE5C0[];
extern char D_004EE5C8[];
extern int Event_Construct(int, int);
extern int Receiver_Construct(int, int);

int func_0016B340(int a0) {
    Receiver_Construct(a0, (int)D_004EE5C0);
    *(int*)((char*)a0) = (int)D_004D9810;
    return a0;
}

int func_0016B380(int a0, int a1, int a2, int a3) {
    int tmp2;
    int tmp3;

    Event_Construct(a0, (int)D_004EE5C8);
    *(int*)((char*)a0) = (int)D_004D92A0;
    *(char*)((char*)a0 + 36) = 0;
    *(char*)((char*)a0 + 37) = a3;
    *(int*)((char*)a0 + 40) = 0;
    *(int*)((char*)a0 + 44) = 0;
    *(int*)((char*)a0) = (int)D_004D92C0;
    tmp2 = *(int*)(char*)a1;
    *(int*)((char*)a0 + 48) = tmp2;
    *(int*)((char*)a0) = (int)D_004D9870;
    tmp3 = *(int*)(char*)a2;
    *(int*)((char*)a0 + 52) = tmp3;
    *(char*)((char*)a0 + 36) = 2;
    return a0;
}
