/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3480(int, int);
extern int func_001F34D0(int);
extern int func_001F3510(int);
extern int func_0020A910(int, int, int, int);

void func_001F3470(int a0, int a1) {
    func_001F3480(a0, a1);
}

int func_001F3480(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_001F34D0(a0);
    tmp2 = func_0020A910(a0, tmp0, 1, a1);
    return tmp2;
}

int func_001F34D0(int a0) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_001F3510(a0);
    tmp2 = *(int*)((char*)a0 + 4);
    tmp3 = *(int*)(char*)tmp0;
    return (tmp3 + (tmp2 * 36));
}
