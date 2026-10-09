/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9960[];
extern char D_004EE6C0[];
extern int ScalarCollection_Init(int);
extern int Receiver_Construct(int, int);

int func_001716E0(int a0, int a1) {
    Receiver_Construct(a0, (int)D_004EE6C0);
    *(int*)((char*)a0) = (int)D_004D9960;
    ScalarCollection_Init((a0 + 40));
    *(int*)((char*)a0 + 32) = a1;
    *(int*)((char*)a0 + 36) = 0;
    return a0;
}
