/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Equip_Init(int);

void Equip_SwapSlots(int a0, int a1, int a2) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)((a1 << 2) + a0) + 9232);
    tmp1 = *(int*)((char*)((a2 << 2) + a0) + 9232);
    *(int*)((char*)((a1 << 2) + a0) + 9232) = tmp1;
    *(int*)((char*)((a2 << 2) + a0) + 9232) = tmp0;
    Equip_Init(a0);
}

void func_0038C7C0(int a0, int a1) {
    *(int*)((char*)((a1 << 2) + a0) + 9232) = 0;
    Equip_Init(a0);
}
