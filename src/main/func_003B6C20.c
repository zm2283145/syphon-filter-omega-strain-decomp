/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C5370(int, int);
extern int func_003B6C70(int, int);
extern int func_003B6CB0(int, int);

int func_003B6C20(int a0, int a1) {
    int tmp2;

    func_003B6CB0(a0, a1);
    tmp2 = *(int*)((char*)a1 + 176);
    *(int*)((char*)a0 + 176) = tmp2;
    func_003B6C70((a0 + 180), (a1 + 180));
    return a0;
}

int func_003B6C70(int a0, int a1) {
    unsigned char tmp2;

    func_001C5370(a0, a1);
    tmp2 = *(unsigned char*)((char*)a1 + 12);
    *(char*)((char*)a0 + 12) = tmp2;
    return a0;
}
