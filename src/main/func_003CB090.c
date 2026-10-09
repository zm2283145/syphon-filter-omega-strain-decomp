/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFDA0[];
extern char D_004DFDE0[];
extern char D_00543650[];
extern int func_00139070(int);

int func_003CB090(int a0, int a1) {
    int tmp0;

    *(int*)((char*)a0) = (int)D_004DFDE0;
    *(int*)((char*)a0 + 4) = 0xbebaafde;
    *(int*)((char*)a0 + 8) = (int)D_00543650;
    tmp0 = *(int*)(char*)a1;
    *(int*)((char*)a0 + 12) = tmp0;
    *(int*)((char*)a0 + 16) = -1;
    *(char*)((char*)a0 + 20) = 1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0) = (int)D_004DFDA0;
    func_00139070((a0 + 32));
    return a0;
}

int func_003CB110(int a0) {
    *(int*)((char*)a0) = (int)D_004DFDE0;
    *(int*)((char*)a0 + 4) = 0xbebaafde;
    *(int*)((char*)a0 + 8) = (int)D_00543650;
    *(int*)((char*)a0 + 12) = -1;
    *(int*)((char*)a0 + 16) = -1;
    *(char*)((char*)a0 + 20) = 1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0) = (int)D_004DFDA0;
    func_00139070((a0 + 32));
    return a0;
}

void func_003CB190(void) {
}
