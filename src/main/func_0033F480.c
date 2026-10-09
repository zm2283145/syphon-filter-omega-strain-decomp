/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DE8A0[];
extern int func_0033D580(int);
extern int func_0044FA00(int);

int func_0033F480(int a0) {
    func_0033D580(a0);
    *(int*)((char*)a0) = (int)D_004DE8A0;
    func_0044FA00((a0 + 172));
    func_0044FA00((a0 + 200));
    func_0044FA00((a0 + 228));
    *(int*)((char*)a0 + 260) = 0;
    *(int*)((char*)a0 + 264) = 0;
    *(int*)((char*)a0 + 268) = 0;
    *(int*)((char*)a0 + 136) = 0;
    *(int*)((char*)a0 + 140) = 0;
    *(int*)((char*)a0 + 152) = 0;
    *(int*)((char*)a0 + 156) = 0;
    *(int*)((char*)a0 + 160) = 0;
    *(int*)((char*)a0 + 164) = 0;
    *(char*)((char*)a0 + 148) = 1;
    *(int*)((char*)a0 + 168) = 0;
    *(int*)((char*)a0 + 256) = -1;
    return a0;
}
