#include "types.h"

/* snd_FlushSoundCommands: run the callbacks of the command batch the IOP has finished, complete a
 * pending bank load, send the next queued batch, poll the CD stream; returns whether work is pending. */
#include "989snd.h"

extern void SyncDCache(void*, void*);
extern void printf(char* fmt, ...);
extern int sceSifCheckStatRpc(void* cd);
extern void FlushCache(int);
extern int sceSifCallRpc(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
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
