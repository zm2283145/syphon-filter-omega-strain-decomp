/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00533890[];
extern char D_00533C90[];

void func_0036CA70(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00533C90;
    *(int*)((char*)((int)D_00533890 + (tmp0 << 2))) = a0;
    tmp1 = *(int*)D_00533C90;
    *(int*)D_00533C90 = (tmp1 + 1);
}

int func_0036CAB0(char* self) {
    return *(int*)(self + 344);
}
