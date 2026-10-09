/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00213DC0(int);
extern int func_00213EE0(int);
extern int func_00214FA0(int);

int func_00211080(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00214FA0(tmp0);
    return (tmp1 & 255);
}

int func_002110A0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00213EE0(tmp0);
    return (tmp1 & 255);
}

int func_002110C0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00213DC0(tmp0);
    return (tmp1 & 255);
}
