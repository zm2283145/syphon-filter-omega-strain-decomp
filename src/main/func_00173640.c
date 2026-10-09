/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003CE7D0(int);
extern void func_003CE810(int);

void func_00173640(void) {
}

void func_00173650(void) {
}

void* func_00173660(char* self) {
    return self + 112;
}

void func_00173670(int a0) {
    *(char*)((char*)a0 + 44) = 1;
}

void func_00173680(char* self) {
    self[44] = 0;
}

void func_00173690(int a0) {
    *(char*)((char*)a0 + 44) = 1;
    func_003CE810(a0);
}

void func_001736A0(int a0) {
    *(char*)((char*)a0 + 44) = 0;
    func_003CE7D0(a0);
}

int func_001736B0(void) {
    return 1;
}
