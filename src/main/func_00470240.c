/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00587FF8[];
extern int Loc_GetTextById(int);

int func_00470240(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00587FF8;
    tmp1 = *(int*)((char*)(tmp0 + (a0 * 44)) + 4);
    return Loc_GetTextById(tmp1);
}

int func_00470270(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00587FF8;
    tmp1 = *(int*)(char*)(tmp0 + (a0 * 44));
    return Loc_GetTextById(tmp1);
}
