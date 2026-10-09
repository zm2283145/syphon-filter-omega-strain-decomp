/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern int func_00147630(int);
extern int func_00147990(void);
extern int func_0036E5D0(int);
extern int func_003CC1D0(int);

int func_00147910(int a0) {
    func_003CC1D0(a0);
    func_0036E5D0((a0 + 28));
    *(int*)((char*)a0 + 20) = 0;
    *(char*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0 + 212) = 0;
    *(char*)((char*)a0 + 16) = 0;
    *(int*)((char*)a0 + 184) = 0;
    *(int*)((char*)a0 + 188) = 0;
    *(int*)((char*)a0 + 192) = 0;
    *(int*)((char*)a0 + 196) = 0;
    *(int*)((char*)a0 + 200) = 0;
    *(int*)((char*)a0 + 204) = 0;
    *(int*)((char*)a0 + 208) = 0;
    return a0;
}

int func_00147970(void) {
    func_00147990();
    return 0;
}

int func_00147990(void) {
    int tmp0;

    tmp0 = *(int*)D_004FFD30;
    return func_00147630(tmp0);
}

void func_001479A0(void) {
}
