/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DD730[];
extern char D_004FFC04[];
extern int func_0033D580(int);
extern int func_0044FA00(int);

int func_002A19C0(int a0) {
    int tmp8;
    int tmp9;

    func_0033D580(a0);
    *(int*)((char*)a0) = (int)D_004DD730;
    func_0044FA00((a0 + 136));
    func_0044FA00((a0 + 164));
    func_0044FA00((a0 + 192));
    *(int*)((char*)a0 + 132) = 6;
    *(int*)((char*)a0 + 220) = 0;
    *(int*)((char*)a0 + 224) = 0;
    *(int*)((char*)a0 + 228) = 0;
    *(int*)((char*)a0 + 232) = 0;
    *(int*)((char*)a0 + 236) = 0;
    *(int*)((char*)a0 + 240) = 0;
    *(int*)((char*)a0 + 244) = 0;
    *(char*)((char*)a0 + 248) = 0;
    tmp8 = *(int*)D_004FFC04;
    *(int*)((char*)a0 + 240) = tmp8;
    tmp9 = *(int*)((char*)a0 + 240);
    *(int*)((char*)a0 + 244) = (tmp9 + 320);
    return a0;
}
