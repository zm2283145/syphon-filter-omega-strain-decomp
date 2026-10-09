/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Agent_GetSelected(int, int);
extern char D_004FFB50[];
extern void func_00299510(int);
extern int func_003334C0(int, int, int);
extern void func_00356C70(int);

void func_00353800(int a0) {
    int tmp2;
    signed char tmp4;

    func_00299510((a0 + 108));
    tmp2 = Agent_GetSelected((int)D_004FFB50, -1);
    tmp4 = *(signed char*)((char*)a0 + 124);
    func_003334C0(tmp2, tmp4, (a0 + 108));
    func_00356C70(a0);
}
