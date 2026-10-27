/*
 * Libs/989snd/ee/989snd: 4 files, 003A7990-003A7EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A7990 */
#pragma push /* merge_units */
#include "types.h"
#include "989snd.h"

extern void SyncDCache(void*, void*);
extern void printf(char* fmt, ...);
extern int sceSifCheckStatRpc(void* cd);
extern void FlushCache(int);
extern int sceSifCallRpc(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
extern void snd_FlushSoundCommands(void);
extern void* memcpy(void*, void*, int);

extern char D_0053DBC0[];
extern int* D_0053DBE8;
extern int D_0053DBF0;
extern int D_0053DC40;
extern int D_0053DC44;
extern int D_0053DC48;
extern char D_0053DC80[];
extern char D_0053DC8C[];
extern int D_00542840;
extern int D_00542848;
extern int* D_004934E0[];
extern int D_004934E8[];
extern int* D_004934F8[];
extern char D_004BCB10[];
extern char D_004BCB60[];

static inline int snd_GotReturns(void) {
    FlushCache(0);
    if (!D_0053DBE8) return 1;
    if (sceSifCheckStatRpc(D_0053DBC0)) return 0;
    if (D_0053DBE8[0] == -1 && D_0053DBE8[D_0053DBF0 + 1] == -1) {
        D_0053DBE8 = 0;
        return 1;
    }
    if (!snd_quiet) printf(D_004BCB60);
    return 0;
}

static inline void snd_SendCurrentBatch(void) {
    int* r;
    int n;
    if ((n = *D_004934E0[D_00542840]) == 0 || D_00542848) return;
    r = D_004934F8[D_00542840];
    D_0053DBF0 = n;
    D_0053DBE8 = r;
    r[n + 1] = 0;
    r[0] = 0;
    SyncDCache(r, (char*)r + 3);
    SyncDCache(&r[n + 1], (char*)&r[n + 1] + 3);
    while (sceSifCheckStatRpc(D_0053DBC0)) {
        if (!snd_quiet) printf(snd_rpcCollisionMsg);
        FlushCache(0);
    }
    sceSifCallRpc(D_0053DBC0, 0x4D, 1, D_004934E0[D_00542840], 0x1000 - D_004934E8[D_00542840],
                  D_004934F8[D_00542840], *D_004934E0[D_00542840] * 4 + 8, 0, 0);
    {
        int t = D_00542840 != 1;
        D_00542840 = t;
        *D_004934E0[t] = 0;
    }
    D_004934E8[D_00542840] = 0xFFC;
}

int snd_SendIOPCommandAndWait(int command, int data_size, char* in_data) {
    int x;
    int ret;
    if (command != 0x68) {
        for (x = 0; x < data_size; x++) D_0053DC80[x] = in_data[x];
    } else {
        if (*(unsigned int*)(in_data + 8) + 12 > 0x200) {
            printf(D_004BCB10);
            while (1) {}
        }
        for (x = 0; x < 12; x++) D_0053DC80[x] = in_data[x];
        memcpy(D_0053DC8C, *(void**)(in_data + 12), *(int*)(in_data + 8));
    }
    while (D_0053DBE8) {
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    D_0053DC48 = 0;
    D_0053DBF0 = 1;
    D_0053DBE8 = &D_0053DC40;
    D_0053DC40 = 0;
    SyncDCache(&D_0053DC40, (char*)&D_0053DC40 + 3);
    SyncDCache(&D_0053DC48, (char*)&D_0053DC48 + 3);
    while (sceSifCheckStatRpc(D_0053DBC0)) {
        if (!snd_quiet) printf(snd_rpcCollisionMsg);
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    if (data_size)
        sceSifCallRpc(D_0053DBC0, command, 1, D_0053DC80, data_size, &D_0053DC40, 12, 0, 0);
    else
        sceSifCallRpc(D_0053DBC0, command, 1, 0, 0, &D_0053DC40, 12, 0, 0);
    while (!snd_GotReturns()) {}
    ret = D_0053DC44;
    snd_SendCurrentBatch();
    return ret;
}
static inline void merge_flush_func_003A7990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A7990 */

/* merge_units: begin func_003A7EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


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
static inline void merge_flush_func_003A7EC0(void) {} /* merge_units */
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
static inline void merge_flush_func_003A8000(void) {} /* merge_units */
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
static inline void merge_flush_func_003A8040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8040 */
