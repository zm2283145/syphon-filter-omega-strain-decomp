/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00225790(int);
extern int func_00228050(int, int);

int func_00224F30(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    func_00228050(tmp1, ((unsigned int)(0) < (unsigned int)(tmp3)));
    return 0;
}

int func_00224F70(int a0) {
    int a1, v0;

    a0 = *(int*)(char*)a0;
    v0 = func_00225790(a0);
    a0 = v0;
    a1 = 0;
    v0 = func_00228050(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
