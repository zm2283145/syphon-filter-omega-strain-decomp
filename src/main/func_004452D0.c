/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies just before SFOLobby_Account.cc (starts 0x004452F0).
 */

#include "types.h"

extern int D_004976D8;

int func_004452D0(void) {
    return D_004976D8;
}

void func_004452E0(int value) {
    D_004976D8 = value;
}
