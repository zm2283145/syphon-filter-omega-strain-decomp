/*
 * main/particle: 3 files, 003A6AD0-003A6D50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6AD0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int sceSifLoadModule();                       
int sprintf();                      

int LibInit_LoadIrxModule(char *arg0, int arg1, int arg2, int arg3) {
    int spF0[8];
    int spB0[16];
    int sp60[20];
    int temp_v0;
    int var_s0;

    sprintf(spF0, "cdrom0:\\IRX\\%s;1", arg0);
    var_s0 = 0;
loop_1:
    temp_v0 = sceSifLoadModule(spF0, arg1, arg2);
    if (temp_v0 < 0) {
        var_s0 += 1;
        if (var_s0 >= 0x32) {

        } else {
            goto loop_1;
        }
    }
    if ((temp_v0 < 0) && (arg3 != 0)) {
        sprintf(spB0, "\nUnable to Load IRX Module: %s, err: 0x%x\n", spF0, -temp_v0);
    }
    if (var_s0 != 0) {
        sprintf(sp60, "Failed to load module on first try.  %d attempts required!", (char *) var_s0);
    }
    return temp_v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6AD0 */

/* merge_units: begin func_003A6BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers that pack their arguments into a stack buffer and send an
 * IOP sound command (989snd library interface, just before 989snd.c).
 */


/* Sends IOP sound command `cmd` with `size` bytes of arguments and waits. */
extern int snd_SendIOPCommandAndWait(int cmd, int size, int *args);
extern int func_0042B5D0(void);
extern int SFOLibInit_AllowPlayer(void);
extern int snd_SendIOPCommandNoWait(int cmd, int size, int *args, int a3, int t0);

int func_003A6BB0(void) {
    return func_0042B5D0();
}

int func_003A6BC0(void) {
    return SFOLibInit_AllowPlayer();
}

int func_003A6BD0(void) {
    return snd_SendIOPCommandAndWait(91, 0, 0);
}

void func_003A6BE0(int a0, int a1) {
    int args[2];

    args[0] = a0;
    args[1] = a1;
    snd_SendIOPCommandAndWait(90, 8, args);
}

int snd_GetTransStatus(void) {
    return snd_SendIOPCommandAndWait(64, 0, 0);
}

void snd_StartMovieSoundEx(int a0, int a1, int a2, int a3, int t0) {
    int args[8];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = t0;
    snd_SendIOPCommandAndWait(62, 20, args);
}

int snd_CloseMovieSound(void) {
    return snd_SendIOPCommandAndWait(60, 0, 0);
}

int snd_PauseMovieSound(void) {
    return snd_SendIOPCommandAndWait(63, 0, 0);
}

int snd_ResetMovieSound(void) {
    return snd_SendIOPCommandAndWait(61, 0, 0);
}

void snd_InitMovieSoundEx(int a0, int a1, int a2, int a3, int t0, int t1) {
    int args[8];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    args[4] = t0;
    args[5] = t1;
    snd_SendIOPCommandAndWait(59, 24, args);
}

void snd_SetReverbDepth(int a0, int a1, int a2) {
    int args[4];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    snd_SendIOPCommandNoWait(15, 12, args, 0, 0);
}

void snd_SetReverbType(int a0, int a1) {
    int args[2];

    args[0] = a0;
    args[1] = a1;
    snd_SendIOPCommandNoWait(14, 8, args, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6BB0 */

/* merge_units: begin func_003A6D50 */
#pragma push /* merge_units */
extern char D_0053DC00[];
extern char D_0053DC08[];
extern int sceCdCallback(int);

int snd_StreamSafeCdCallback(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0053DC00;
    cond = v0 != 0;
    if (cond) goto L003A6D78;
    v0 = sceCdCallback(a0);
    goto L003A6D88;
L003A6D78:;
    v0 = *(int*)(char*)D_0053DC08;
    *(int*)(char*)D_0053DC08 = a0;
L003A6D88:;
    goto ret;
ret:
    return v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6D50 */
