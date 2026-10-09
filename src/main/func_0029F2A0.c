/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DD620[];
extern int func_0033D580(int);
extern int func_0044FA00(int);

int func_0029F2A0(int a0) {
    func_0033D580(a0);
    *(int*)((char*)a0) = (int)D_004DD620;
    func_0044FA00((a0 + 152));
    func_0044FA00((a0 + 180));
    func_0044FA00((a0 + 208));
    *(int*)((char*)a0 + 132) = 0;
    *(char*)((char*)a0 + 148) = 0;
    *(int*)((char*)a0 + 136) = 0;
    *(int*)((char*)a0 + 140) = 0;
    *(int*)((char*)a0 + 144) = 0;
    *(int*)((char*)a0 + 236) = 0;
    *(int*)((char*)a0 + 244) = 0;
    *(int*)((char*)a0 + 248) = 0;
    *(int*)((char*)a0 + 252) = 0;
    *(int*)((char*)a0 + 256) = 0;
    *(int*)((char*)a0 + 260) = 0;
    *(int*)((char*)a0 + 268) = 0;
    *(int*)((char*)a0 + 272) = 0;
    *(int*)((char*)a0 + 276) = 0;
    *(int*)((char*)a0 + 280) = 4;
    *(int*)((char*)a0 + 284) = -2;
    *(int*)((char*)a0 + 288) = -2;
    return a0;
}
