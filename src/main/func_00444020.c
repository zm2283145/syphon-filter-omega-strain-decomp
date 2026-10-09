/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Wrap.cc (ends 0x00443F40) and SFOLobby_Account.cc;
 * lobby flag accessors.
 */

#include "types.h"

extern unsigned char D_00584240;
extern char D_00584241;
extern char D_005842C8;
extern char D_005842CC[];
extern int func_002EBC48(void* obj);

int func_00444020(int value) {
    D_005842C8 = value;
    return func_002EBC48(D_005842CC);
}

void func_00444040(int value) {
    D_00584241 = value;
}

void func_00444050(int value) {
    D_00584240 = value;
}

int func_00444060(void) {
    return D_00584240;
}
