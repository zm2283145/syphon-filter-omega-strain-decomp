/*
 * lib/libezctl: 5 files, 00353070-003532F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00353070 */
#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCtl_rpcBound;
extern char ezNetCtl_rpcBuf[];
extern SifRpcClientData ezNetCtl_cd;
extern char ezNetCtl_logPrefix[];
extern char ezNetCtl_srcFile[];
extern char ezNetCtl_msgNotRunning[];
extern int scePrintf(const char *, ...);
extern int sceSifCallRpc(SifRpcClientData *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endFunc, void *endParam);
extern void String_Copy(char *, char *);
int ezNetCtlPreloadModemCnf(char *name)
{
    char *res = ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgNotRunning);
        return -1;
    }
    String_Copy(res + 0x10, name);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_PRELOAD_MODEM_CNF, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
    scePrintf("ezNetCtlPreloadModemCnf returned %d\n", *(int *)res);
    return *(int *)res;
}
/* merge_units: end func_00353070 */

/* merge_units: begin func_00353130 */
extern char ezNetCtl_logPrefix[], ezNetCtl_srcFile[], ezNetCtl_msgNotRunning[];
/* RPC function 5, no arguments; returns the reply word (role unknown). */
int func_00353130(void)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgNotRunning);
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_5, 0, res, 4, res, 4, 0, 0);
    return *res;
}
/* merge_units: end func_00353130 */

/* merge_units: begin func_003531B8 */
/* RPC function 6, no arguments; returns the reply word (role unknown;
 * used by SFOLobby_Config). */
int func_003531B8(void)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgNotRunning);
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_6, 0, res, 4, res, 4, 0, 0);
    return *res;
}
/* merge_units: end func_003531B8 */

/* merge_units: begin func_00353240 */
/* Fills the 0x110-byte status block `buf`; its first word is the result. */
int ezNetCtlGetStatus(int *buf)
{
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgNotRunning);
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_GET_STATUS, 0, buf, 0x110, buf, 0x110, 0, 0);
    if (*buf) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf("ezNetCtlGetStatus returned %d\n", *buf);
    }
    return *buf;
}
/* merge_units: end func_00353240 */

/* merge_units: begin func_003532F8 */
extern int sceSifSetDma(void *, int);
extern int sceSifDmaStat(int);
/* Copies `size` bytes from EE `src` to IOP `dst` with one SIF DMA transfer
 * (size rounded up to 16); waits for completion unless `async`. */
int ezNetCtl_SifDmaSend(int src, int dst, int size, int async)
{
    struct { int data, addr, size, mode; } p; /* sceSifDmaData */
    int r;
    p.data = src;
    p.addr = dst;
    p.size = (size + 0xF) & ~0xF;
    p.mode = 0;
    if (size & 0xF) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf("SIF DMA transfer size %d padded to %d\n", size, p.size);
    }
    do {
        r = sceSifSetDma(&p, 1);
    } while (r == 0);
    if (!async)
        while (sceSifDmaStat(r) >= 0)
            ;
    return r;
}
/* merge_units: end func_003532F8 */
