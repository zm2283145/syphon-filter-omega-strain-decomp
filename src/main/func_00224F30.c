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
