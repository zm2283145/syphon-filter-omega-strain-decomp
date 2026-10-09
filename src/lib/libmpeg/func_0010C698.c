/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0010C7D8(int);
extern int func_0010C8C0(int);

int func_0010C698(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    func_0010C7D8((tmp0 + 104));
    return 1;
}

int func_0010C6C0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    func_0010C8C0((tmp0 + 104));
    return 1;
}
