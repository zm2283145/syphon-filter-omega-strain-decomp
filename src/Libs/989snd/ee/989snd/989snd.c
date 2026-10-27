/*
 * main/989snd: 3 files, 003A7EC0-003A8040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A7EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "989snd.h"

extern int snd_SendIOPCommandNoWait(int, int, int, int, int);

/*
 * The one-to-four word wrappers below keep the register-level shape of the
 * target (arguments reloaded into a0..t0 by hand, then goto ret) because that
 * is what reproduces the scheduling; read `aN = 0 + K` as "argument N = K".
 */

/* Fades sound `a0` (handle) to volume a1 over a2 ms; a3 = direction/mode. */
void snd_AutoVol(int a0, int a1, int a2, int a3) {
    int loc[4];
    int t0, v0;

    t0 = 0;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + SND_CMD_AUTO_VOL;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 16;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    a3 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Command 0x21 with six words; t2/t3 are the callback and its user data. */
void snd_SetSoundParams_CB(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    int loc[8];
    int v0;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 33;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 24;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    *(int*)((char*)loc + 16) = t0;
    a3 = t2;
    *(int*)((char*)loc + 20) = t1;
    t0 = t3;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Command 0x61 with one word (role unknown). */
void snd_StopAllSoundsInGroup(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 97;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Resumes the sound groups in mask a0 (paused by snd_PauseAllSoundsInGroup). */
void snd_ContinueAllSoundsInGroup(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + SND_CMD_CONTINUE_GROUPS;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Pauses the sound groups in mask a0 (2, or -1 for every group). */
void snd_PauseAllSoundsInGroup(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + SND_CMD_PAUSE_GROUPS;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Command 0x18, no arguments; sent when the game shuts sound down. */
int snd_StopAllSounds(void) {
    return snd_SendIOPCommandNoWait(24, 0, 0, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A7EC0 */

/* merge_units: begin func_003A8000 */
#pragma push /* merge_units */
/* 0x30-byte argument block of command 0x56 (role unknown) */
typedef struct { int a; int c; long long b; __int128 d; int e; char pad[0xC]; } P3A8000;
#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, int y);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (int)(a2), (a3), (a4))) /* merge_units */

int snd_GetSoundUserData_CB(int a, long long b, int c, __int128 d, int e, int x, int y)
{
    P3A8000 p;
    p.a = a;
    p.b = b;
    p.c = c;
    p.d = d;
    p.e = e;
    return snd_SendIOPCommandNoWait(0x56, 0x30, &p, x, y);
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8000 */

/* merge_units: begin func_003A8040 */
#pragma push /* merge_units */
/* Stops the sound with handle a0. */
void snd_StopSound(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + SND_CMD_STOP_SOUND;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A8040 */
