/*
 * Libs/989snd/ee/989snd: 3 files, 003A8460-003A8A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A8460 */
#pragma push /* merge_units */
#include "types.h"
#include "989snd.h"
/* snd_BankLoad request: {int arg; char name[];} sent with strlen(name) + 5 bytes */
extern int D_0053DE80;
extern char D_0053DE84[];
extern char D_005428C4[]; /* end of snd_rpcResult, for SyncDCache */
#if 0 /* merge_units */
extern void printf(char*);
#endif /* merge_units */
int printf(const char*, ...); /* merge_units */

extern void Libc_Strcpy(char*, char*);
extern void SyncDCache(int*, char*);
extern int sceSifCheckStatRpc(char*);
#if 0 /* merge_units */
extern void snd_FlushSoundCommands(void);
#endif /* merge_units */
unsigned char snd_FlushSoundCommands(); /* merge_units */

extern void FlushCache(int);
extern int strlen(const char*);
extern int sceSifCallRpc(char*, int, int, int*, int, int*, int, int, int);
int snd_BankLoad(char* name, int arg) {
    int r;
    snd_lastError = 0;
    if (snd_loadInProgress) {
        if (!snd_quiet) printf("snd_BankLoad: Load already in progress!\n");
        return 0;
    }
    D_0053DE80 = arg;
    Libc_Strcpy(D_0053DE84, name);
    snd_rpcResult = -1;
    SyncDCache(&snd_rpcResult, D_005428C4);
    while (sceSifCheckStatRpc(snd_bankCd)) {
        if (!snd_quiet) printf(snd_rpcCollisionMsg);
        snd_FlushSoundCommands();
        FlushCache(0);
    }
    if (sceSifCallRpc(snd_bankCd, SND_BANK_RPC_LOAD, 1, &D_0053DE80, strlen(name) + 5, &snd_rpcResult, 4, 0, 0) < 0) {
        if (!snd_quiet) printf("989snd.c: RPC call has failed inside snd_BankLoad\n");
        snd_lastError = SND_ERR_RPC_FAILED;
        return 0;
    }
    while ((r = snd_rpcResult) == -1) FlushCache(0);
    return r;
}
static inline void merge_flush_func_003A8460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8460 */

/* merge_units: begin func_003A85E0 */
#pragma push /* merge_units */
/* snd_FlushSoundCommands: run the callbacks of the command batch the IOP has finished, complete a
 * pending bank load, send the next queued batch, poll the CD stream; returns whether work is pending. */

#if 0 /* merge_units */
extern void SyncDCache(void*, void*);
#endif /* merge_units */
#define SyncDCache(a0, a1) (SyncDCache((int *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void printf(char* fmt, ...);
#endif /* merge_units */

#if 0 /* merge_units */
extern int sceSifCheckStatRpc(void* cd);
#endif /* merge_units */
#define sceSifCheckStatRpc(a0) (sceSifCheckStatRpc((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int sceSifCallRpc(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
#endif /* merge_units */
#define sceSifCallRpc(a0, a1, a2, a3, a4, a5, a6, a7, a8) (sceSifCallRpc((char *)(a0), (a1), (a2), (int *)(a3), (a4), (int *)(a5), (a6), (a7), (a8))) /* merge_units */

extern void InvalidDCache(void*, void*);
extern int sceCdSync(int);

extern char D_0053DBC0[];
extern int* D_0053DBE8;
extern int D_0053DBF0;
typedef void (*SndCb)(int, unsigned long);
typedef struct { SndCb func; int pad; unsigned long data; } SndCbEnt;
extern int D_0053DC00;
extern void (*D_0053DC08)(int);
extern int D_0053DC10;
extern int D_0053DC18;
extern int D_0053DC20;
extern int D_0053DC40;
extern int D_0053DC44;
extern int D_0053DC48;
extern char D_0053DC80[];
extern char D_0053DC8C[];
extern int D_00542840;
extern int D_00542848;
extern int D_00542800;
extern char D_0054283F[];
extern SndCb D_00542880;
extern unsigned long D_00542888;
extern SndCb D_00542980;
extern unsigned long D_00542988;
extern SndCbEnt* D_004934F0[];
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

unsigned char snd_FlushSoundCommands(void) {
    if (D_0053DBE8 && snd_GotReturns()) {
        if (D_0053DC20) {
            if (D_00542980) D_00542980(D_0053DC44, D_00542988);
            D_00542980 = 0;
            D_0053DC20 = 0;
        } else {
            int b = D_00542840 != 1;
            int x;
            for (x = 0; x < *D_004934E0[b]; x++) {
                if (D_004934F0[b][x].func) D_004934F0[b][x].func(D_004934F8[b][x + 1], D_004934F0[b][x].data);
            }
        }
    }
    if (snd_loadInProgress) {
        FlushCache(0);
        if (snd_rpcResult != -1) {
            if (D_00542880) {
                SndCb f = D_00542880;
                unsigned long d;
                D_00542880 = 0;
                d = D_00542888;
                D_00542888 = 0;
                f(snd_rpcResult, d);
            }
            snd_rpcResult = 0;
            snd_loadInProgress = 0;
        }
    }
    if (!D_0053DBE8) snd_SendCurrentBatch();
    if (D_0053DC10) {
        if (!D_0053DC00) {
            sceCdSync(1);
        } else {
            InvalidDCache(&D_00542800, D_0054283F);
            D_0053DC18 = (unsigned char)!D_00542800;
        }
        if (D_0053DC18) {
            D_0053DC10 = 0;
            D_0053DC18 = 0;
            if (D_0053DC08) D_0053DC08(1);
        }
    }
    return D_0053DBE8 || snd_loadInProgress;
}
#undef SyncDCache /* merge_units */
#undef sceSifCheckStatRpc /* merge_units */
#undef sceSifCallRpc /* merge_units */
static inline void merge_flush_func_003A85E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A85E0 */

/* merge_units: begin func_003A8A90 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int* D_004934E0;
#endif /* merge_units */
#define D_004934E0 (*(int **)&D_004934E0) /* merge_units */

extern int* D_004934E4;
#if 0 /* merge_units */
extern int D_004934E8;
#endif /* merge_units */
#define D_004934E8 (*(int*)&D_004934E8) /* merge_units */

extern int D_004934EC;
#if 0 /* merge_units */
extern int* D_004934F0;
#endif /* merge_units */
#define D_004934F0 (*(int **)&D_004934F0) /* merge_units */

extern int* D_004934F4;
#if 0 /* merge_units */
extern int* D_004934F8;
#endif /* merge_units */
#define D_004934F8 (*(int **)&D_004934F8) /* merge_units */

extern int* D_004934FC;
extern char D_004BCCC0[];
extern char D_004BCCE8[];
#if 0 /* merge_units */
extern int D_0053DBC0[];
#endif /* merge_units */
#define D_0053DBC0 ((int*)&D_0053DBC0) /* merge_units */

extern int D_0053DBE4;
extern int D_0053DF80[];
extern int D_0053EF80[];
extern int D_0053FF80[];
extern int D_00540F80[];
extern int D_00541F80[];
extern int D_005423C0[];
#if 0 /* merge_units */
extern int D_00542800[];
#endif /* merge_units */
#define D_00542800 ((int*)&D_00542800) /* merge_units */

extern int D_00542810;
#if 0 /* merge_units */
extern int D_00542850[];
#endif /* merge_units */
#define D_00542850 ((int*)&D_00542850) /* merge_units */

extern int D_00542874;
extern int D_00542878;
#if 0 /* merge_units */
extern int D_00542880;
#endif /* merge_units */
#define D_00542880 (*(int*)&D_00542880) /* merge_units */

#if 0 /* merge_units */
extern long long D_00542888;
#endif /* merge_units */
#define D_00542888 (*(long long*)&D_00542888) /* merge_units */

extern int D_005428C0;
extern int D_00542990;
void sceSifInitRpc(int);
int printf(const char*, ...);
int sceSifBindRpc(void*, unsigned int, int);
void snd_SendIOPCommandAndWait(int, int, void*);

void snd_StartSoundSystemEx(unsigned int flags)
{
    int* args[2];

    D_004934E0 = D_0053DF80;
    D_004934E4 = D_0053EF80;
    D_004934F8 = D_00541F80;
    D_004934FC = D_005423C0;
    D_004934F0 = D_0053FF80;
    D_004934F4 = D_00540F80;
    if ((unsigned long long)flags & 2)
        D_00542990 = 1;
    else
        D_00542990 = 0;
    sceSifInitRpc(0);
    for (;;) {
        if (sceSifBindRpc(D_0053DBC0, 0x123456, 0) < 0) {
            printf(D_004BCCC0, D_004BCCE8, 0xB5);
            for (;;) ;
        }
        if (D_0053DBE4)
            break;
    }
    D_00542878 = 0;
    D_00542880 = 0;
    D_00542888 = 0;
    D_005428C0 = 0;
    for (;;) {
        if (sceSifBindRpc(D_00542850, 0x123457, 0) < 0) {
            printf(D_004BCCC0, D_004BCCE8, 0xCA);
            for (;;) ;
        }
        if (D_00542874)
            break;
    }
    D_00542800[0] = 0;
    D_00542810 = 0;
    D_0053DF80[0] = 0;
    D_0053EF80[0] = 0;
    D_004934E8 = 0xFFC;
    D_004934EC = 0xFFC;
    args[0] = D_00542800;
    args[1] = (int*)flags;
    snd_SendIOPCommandAndWait(0, 8, args);
}
#undef D_004934E0 /* merge_units */
#undef D_004934E8 /* merge_units */
#undef D_004934F0 /* merge_units */
#undef D_004934F8 /* merge_units */
#undef D_0053DBC0 /* merge_units */
#undef D_00542800 /* merge_units */
#undef D_00542850 /* merge_units */
#undef D_00542880 /* merge_units */
#undef D_00542888 /* merge_units */
static inline void merge_flush_func_003A8A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8A90 */
