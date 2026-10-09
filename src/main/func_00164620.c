/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D96C0[];
extern char D_004ED9B0[];
extern int ScalarCollection_Init(int);
extern int func_003CB4B0(int, int);

int func_00164620(int a0) {
    func_003CB4B0(a0, (int)D_004ED9B0);
    *(int*)((char*)a0) = (int)D_004D96C0;
    ScalarCollection_Init((a0 + 32));
    ScalarCollection_Init((a0 + 44));
    return a0;
}
