/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers that pack their arguments into a stack buffer and send an
 * IOP sound command (989snd library interface, just before 989snd.c).
 */

#include "types.h"

/* Sends IOP sound command `cmd` with `size` bytes of arguments and waits. */
extern int func_003A7990(int cmd, int size, int *args);
extern int func_0042B5D0(void);
extern int func_0042B770(void);
extern int snd_SendIOPCommandNoWait(int cmd, int size, int *args, int a3, int t0);

int func_003A6BB0(void) {
    return func_0042B5D0();
}

int func_003A6BC0(void) {
    return func_0042B770();
}

int func_003A6BD0(void) {
    return func_003A7990(91, 0, 0);
}

void func_003A6BE0(int a0, int a1) {
    int args[2];

    args[0] = a0;
    args[1] = a1;
    func_003A7990(90, 8, args);
}

int func_003A6C10(void) {
    return func_003A7990(64, 0, 0);
}

void func_003A6C20(int a0, int a1, int a2, int a3, int t0) {
    int args[8];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = t0;
    func_003A7990(62, 20, args);
}

int func_003A6C60(void) {
    return func_003A7990(60, 0, 0);
}

int func_003A6C70(void) {
    return func_003A7990(63, 0, 0);
}

int func_003A6C80(void) {
    return func_003A7990(61, 0, 0);
}

void func_003A6C90(int a0, int a1, int a2, int a3, int t0, int t1) {
    int args[8];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = t0;
    args[5] = t1;
    func_003A7990(59, 24, args);
}

void Global_SetReverb(int a0, int a1, int a2) {
    int args[4];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    snd_SendIOPCommandNoWait(15, 12, args, 0, 0);
}

void func_003A6D10(int a0, int a1) {
    int args[2];

    args[0] = a0;
    args[1] = a1;
    snd_SendIOPCommandNoWait(14, 8, args, 0, 0);
}
