/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00423540(int a0, int a1) {
    *(int*)((char*)a1) = *(int*)((char*)a0 + 132);
}

void func_00423550(char* self, int value) {
    *(int*)(self + 132) = value;
}

void func_00423560(int a0, int a1, int a2) {
    *(int*)((char*)a1) = *(int*)((char*)a0 + 120);
    *(int*)((char*)a2) = *(int*)((char*)a0 + 124);
}

void func_00423580(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 120) = a1;
    *(int*)((char*)a0 + 124) = a2;
}

void func_00423590(int a0, int a1, int a2) {
    *(int*)((char*)a1) = *(int*)((char*)a0 + 112);
    *(int*)((char*)a2) = *(int*)((char*)a0 + 116);
}

void func_004235B0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 112) = a1;
    *(int*)((char*)a0 + 116) = a2;
}
