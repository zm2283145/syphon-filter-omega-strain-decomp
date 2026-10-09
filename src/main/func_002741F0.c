/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048B308[];
extern int func_00139070(int);
extern int func_00222B60(int);

int func_002741F0(int a0) {
    func_00139070(a0);
    func_00139070((a0 + 12));
    func_00222B60((a0 + 24));
    func_00139070((a0 + 36));
    *(int*)((char*)a0 + 48) = 1065353216;
    *(int*)((char*)a0 + 56) = -2;
    *(int*)((char*)a0 + 52) = 0;
    *(int*)((char*)a0 + 60) = 0;
    *(char*)D_0048B308 = 1;
    return a0;
}
