/*
 * main/989snd: 5 files, 003A8070-003A8260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "989snd.h"

/* merge_units: begin func_003A8070 */
#pragma push /* merge_units */
#include "types.h"
/* 0x30-byte argument block of command 0x5C (role unknown); `flags` says which fields are valid */
typedef struct { union { int i; long long l; } u; int d; int e; __int128 c; short f1; short f2; char p24[4]; int flags; char p2C[4]; } P3A8070;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, long long y);
int func_003A8070(int a, long long b, __int128 c, int d, int e, short f1, short f2, int x, long long y)
{
    P3A8070 p;
    int* fl = &p.flags;
    *fl = 0;
    if (!a) p.u.l = b; else { p.u.i = a; *fl |= 1; }
    p.c = c;
p.d = d;
p.f1 = f1;
p.f2 = f2;
p.e = e;
    *fl |= 0x3C;
    return snd_SendIOPCommandNoWait(0x5C, 0x30, &p, x, y);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A8070 */

/* merge_units: begin func_003A80F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int, int, int, int, int);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (void *)(a2), (a3), (long long)(a4))) /* merge_units */


/* Command 0xB with one word (role unknown). */
void func_003A80F0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 11;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A80F0 */

/* merge_units: begin func_003A8120 */
#pragma push /* merge_units */
/* Command 0x60: a word plus an optional six-word block (v[0] = -1 when absent). */
typedef struct { int v[6]; } S3A8120;
typedef struct { int a; S3A8120 s; } P3A8120;
#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, int y);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (a2), (a3), (long long)(a4))) /* merge_units */

int func_003A8120(int a, S3A8120* s)
{
    P3A8120 p;
    S3A8120* d = &p.s;
    p.a = a;
    if (s) { d->v[0] = s->v[0]; d->v[1] = s->v[1]; d->v[2] = s->v[2]; d->v[3] = s->v[3]; d->v[4] = s->v[4]; d->v[5] = s->v[5]; } else d->v[0] = -1;
    return snd_SendIOPCommandNoWait(0x60, 0x1C, &p, 0, 0);
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8120 */

/* merge_units: begin func_003A81A0 */
#pragma push /* merge_units */
extern int snd_SendIOPCommandAndWait(int cmd, int size, int data);
#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int, int, int, int, int);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (void *)(a2), (a3), (long long)(a4))) /* merge_units */


/* Reads master volume a0 (blocking); the IOP reply is left in v0 as the
 * real return value (declared void here because that is what matches). */
void snd_GetMasterVolume(int a0) {
    int loc[1];
    int a1, a2, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a0 = 0 + SND_CMD_GET_MASTER_VOLUME;
    v0 = snd_SendIOPCommandAndWait(a0, a1, a2);
    goto ret;
ret:;
}

/* Sets master volume a0 (which) to a1. */
void snd_SetMasterVolume(int a0, int a1) {
    int loc[2];
    int a2, a3, t0, v0;

    a3 = 0;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    t0 = 0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + SND_CMD_SET_MASTER_VOLUME;
    a1 = 0 + 8;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Unloads the bank whose handle snd_BankLoad/snd_BankLoadByLoc returned. */
void snd_UnloadBank(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + SND_CMD_UNLOAD_BANK;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

/* Command 8, no arguments (role unknown). */
int func_003A8240(void) {
    return snd_SendIOPCommandNoWait(8, 0, 0, 0, 0);
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A81A0 */

/* merge_units: begin func_003A8260 */
#pragma push /* merge_units */
extern void SyncDCache(int*, char*);
extern void InvalidDCache(int*, char*);
extern int sceCdSync(int);
extern int snd_FlushSoundCommands(void); /* pushes queued commands to the IOP while waiting */
extern void printf(char* fmt, ...);
extern int sceSifCheckStatRpc(void* sema);
extern void FlushCache(int);
extern int sceSifCallRpc(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
extern int D_0053DC00;
extern int D_0053DC18;
extern int D_00542800;
extern char D_0054283F;
extern char D_005428C4;
extern int D_00542900;
extern int D_00542904;
/*
 * CD-busy check: without D_0053DC00 set this is sceCdSync(w); otherwise it
 * polls the busy word D_00542800 (invalidating the cached copy first) and
 * records the result in D_0053DC18. Same helpers as func_003A7200.
 */
static inline unsigned char Done3A8260(void) { return !D_00542800; }
static inline int Poll3A8260(char* k) {
    int t;
    InvalidDCache(&D_00542800, k);
    t = Done3A8260();
    D_0053DC18 = t;
    return t;
}
static inline int Check3A8260(int w) {
    if (D_0053DC00 == 0) return sceCdSync(w);
    if (Poll3A8260(&D_0054283F) == 1) return 0;
    return 1;
}
#pragma push
#pragma bool off
int snd_BankLoadByLoc(int loc, int size)
{
    snd_lastError = 0;
    if (snd_loadInProgress) {
        if (!snd_quiet) printf("snd_BankLoadByLoc: Load already in progress!\n");
        return 0;
    }
    if (Check3A8260(1) == 1) {
        if (!snd_quiet) printf("snd_BankLoadByLoc: CD BUSY!\n");
        return 0;
    }
    snd_rpcResult = -1;
    SyncDCache(&snd_rpcResult, &D_005428C4);
    D_00542900 = loc;
    D_00542904 = size;
    while (sceSifCheckStatRpc(snd_bankCd)) {
        if (!snd_quiet) printf(snd_rpcCollisionMsg);
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    if (sceSifCallRpc(snd_bankCd, SND_BANK_RPC_LOAD_BY_LOC, 1, &D_00542900, 8, &snd_rpcResult, 4, 0, 0) < 0) {
        if (!snd_quiet) printf("989snd.c: RPC call has failed inside snd_BankLoadByLoc\n");
        snd_lastError = SND_ERR_RPC_FAILED;
        return 0;
    }
    while (snd_rpcResult == -1) FlushCache(0);
    return snd_rpcResult;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003A8260 */
