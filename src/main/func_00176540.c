/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int Agent_GetSelected(int, int);
extern void func_0024B4D0(int);
extern void func_00333F10(int, int, int);

void func_00176540(int a0) {
    int tmp0;

    tmp0 = Agent_GetSelected((int)D_004FFB50, -1);
    func_00333F10(tmp0, 8, 1);
    func_0024B4D0((a0 + 80));
}
