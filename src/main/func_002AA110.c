/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDAF0[];
extern int func_0033D580(int);
extern int func_0044FA00(int);

int func_002AA110(int a0) {
    func_0033D580(a0);
    *(int*)((char*)a0) = (int)D_004DDAF0;
    func_0044FA00((a0 + 160));
    *(int*)((char*)a0 + 132) = 5;
    *(int*)((char*)a0 + 136) = 0;
    *(int*)((char*)a0 + 144) = 0;
    *(int*)((char*)a0 + 140) = 0;
    *(int*)((char*)a0 + 148) = 0;
    *(int*)((char*)a0 + 156) = -1;
    *(int*)((char*)a0 + 152) = -1;
    *(char*)((char*)a0 + 120) = 0;
    return a0;
}
