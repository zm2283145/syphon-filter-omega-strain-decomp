/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004EE948;
extern int GObj_IdentityA(int);

/* Script binding: args[0] is the message; returns its "who" field (+0x24). */
int Script_cHumanSeenMsg_Who(char** args) {
    return GObj_IdentityA(*(int*)(args[0] + 0x24));
}

void func_0017A060(void) {
}

/* Returns the value of global D_004EE948. */
int cHumanSeenMsg_v03(void) {
    return D_004EE948;
}
