/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00379700(char* self) {
    return self + 80;
}

int func_00379710(int a0) {
    return *(unsigned short*)((char*)*(int*)((char*)a0 + 68) + 10);
}

int func_00379720(int a0) {
    return *(unsigned short*)((char*)*(int*)((char*)a0 + 68) + 6);
}

int func_00379730(int a0) {
    return *(unsigned short*)((char*)*(int*)((char*)a0 + 68) + 4);
}

int func_00379740(int a0, int a1) {
    return *(int*)(char*)(*(int*)((char*)a0 + 8) + (a1 << 2));
}

int func_00379760(int a0, int a1, int a2, int a3, int t0) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 4) = a2;
    *(int*)((char*)a0 + 8) = a3;
    *(int*)((char*)a0 + 12) = t0;
    return a0;
}

void func_00379780(void) {
}
