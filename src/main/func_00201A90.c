/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00201AF0(int, int);
extern int func_00201C30(int, int);

int func_00201A90(int a0, int a1) {
    int tmp2;
    unsigned char tmp5;
    unsigned char tmp6;

    func_00201C30(a0, a1);
    tmp2 = *(int*)((char*)a1 + 32);
    *(int*)((char*)a0 + 32) = tmp2;
    func_00201AF0((a0 + 36), (a1 + 36));
    tmp5 = *(unsigned char*)((char*)a1 + 52);
    *(char*)((char*)a0 + 52) = tmp5;
    tmp6 = *(unsigned char*)((char*)a1 + 53);
    *(char*)((char*)a0 + 53) = tmp6;
    return a0;
}
