/*
 * Matched functions (byte-identical with the retail executable).
 * IOP sound command wrappers (989snd library interface).
 */

#include "loose03_types.h"

extern int snd_SendIOPCommandNoWait(int cmd, int size, int* args, int a3, int t0);

int func_003A7310(void) {
    return snd_SendIOPCommandNoWait(52, 0, 0, 0, 0);
}

void func_003A7330(int a0, int a1, int a2) {
    int args[4];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    snd_SendIOPCommandNoWait(98, 12, args, 0, 0);
}
