/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDD40[];
extern int func_0033F480(int);

int func_002AFF20(int a0) {
    func_0033F480(a0);
    *(int*)((char*)a0) = (int)D_004DDD40;
    *(int*)((char*)a0 + 372) = 0;
    *(int*)((char*)a0 + 376) = 0;
    *(int*)((char*)a0 + 380) = 0;
    *(int*)((char*)a0 + 132) = 3;
    *(int*)((char*)a0 + 356) = 0;
    *(int*)((char*)a0 + 360) = 0;
    *(int*)((char*)a0 + 364) = 0;
    *(char*)((char*)a0 + 368) = 0;
    return a0;
}
