/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFBF0[];
extern int func_001F31C0(int, int, int);
extern int func_001F3B20(int);
extern void func_001F3F80(int, int);

int func_001F3EF0(int a0, int a1, int a2, int a3, int t0, int t1) {
    func_001F31C0(a0, 2, t1);
    *(int*)((char*)a0) = (int)D_004DFBF0;
    *(int*)((char*)a0 + 32) = a1;
    func_001F3B20((a0 + 36));
    *(char*)((char*)a0 + 52) = a3;
    *(char*)((char*)a0 + 53) = t0;
    func_001F3F80(a2, (a0 + 36));
    return a0;
}
