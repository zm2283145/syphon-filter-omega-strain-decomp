/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0240[];
extern int func_003E99B0(int, int, int);

void func_00243480(char* self, char value) {
    self[16] = value;
}

void func_00243490(char* self, char value) {
    self[91] = value;
}

int func_002434A0(char* self) {
    return *(int*)(self + 116);
}

int func_002434B0(int a0, int a1, int a2) {
    func_003E99B0(a0, a1, a2);
    *(int*)((char*)a0) = (int)D_004E0240;
    return a0;
}
