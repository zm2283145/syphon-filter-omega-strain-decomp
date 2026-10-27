/*
 * Libs/989snd/ee/989snd: 1 file, 003A8460
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
extern void printf(char*);
extern void Libc_Strcpy(char*, char*);
extern void SyncDCache(int*, char*);
extern int sceSifCheckStatRpc(char*);
extern void snd_FlushSoundCommands(void);
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
