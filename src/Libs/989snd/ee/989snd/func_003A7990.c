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



