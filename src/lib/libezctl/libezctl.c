/*
 * libezctl.c: EE client of the SCE ezNetCtl sample IOP module
 * (eznetctl_inet.irx), which applies a network configuration and brings the
 * interface up (see ezNet.h).
 * Compiler: EE-GCC 2.96 -O2 -G0.
 */
#include "ezNet.h"

extern int ezNetCtl_modId;
extern int ezNetCtl_rpcBound;
extern SifRpcClientData ezNetCtl_cd;
extern char ezNetCtl_rpcBuf[];

extern int sceSifSetDma(void *, int);
extern int sceSifDmaStat(int);

#define EZNETCTL_LOG_HEADER() scePrintf("%s> ", "libezctl.c")

int dmaIOP(int src, int dst, int size, int async);

/* Finds eznetctl_inet.irx and binds its RPC server (retries until bound). */
int ezNetCtlInit(void)
{
    int r, i;
    if ((ezNetCtl_modId = sceSifSearchModuleByName("eznetctl_inet")) < 0) {
        EZNETCTL_LOG_HEADER();
        scePrintf("%s module not found\n", "eznetctl_inet");
    }
    for (;;) {
        r = sceSifBindRpc(&ezNetCtl_cd, EZNETCTL_RPC_ID, 0);
        i = 0x10000;
        if (r < 0) {
            EZNETCTL_LOG_HEADER();
            scePrintf("could not bind to RPC service\n");
        }
        if (ezNetCtl_cd.server) break;
        while (--i != -1)
            ;
    }
    ezNetCtl_rpcBound = 1;
    return r;
}

/* Stops and unloads eznetctl_inet.irx. */
int ezNetCtlExit(void)
{
    int stat;
    if (ezNetCtl_rpcBound == 1) {
        if (sceSifStopModule(ezNetCtl_modId, 0, 0, &stat) >= 0) {
            stat = sceSifUnloadModule(ezNetCtl_modId);
            if (stat >= 0) {
                ezNetCtl_rpcBound = 0;
                stat = 0;
            }
        }
    }
    return stat;
}

/* Sends the EE properties block at `props` (EZNET_RPC_BUF_SIZE bytes): asks
 * the IOP module where to put it, DMAs it there and applies it. */
int ezNetCtlSetProperties(int props)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    int r;
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    if (4 > EZNET_RPC_BUF_SIZE) { /* inlined RPC size check, constant-false here: only its message remains */
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC data size 0x%x exceeds buffer size 0x%x\n", 4, EZNET_RPC_BUF_SIZE);
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_GET_PROPERTIES_ADDRESS, 0, res, 4, res, 4, 0, 0);
    if (*res == 0) {
        EZNETCTL_LOG_HEADER();
        scePrintf("eCtlGetPropertiesAddress returned NULL\n");
        *res = -2;
        return -2;
    }
    dmaIOP(props, *res, EZNET_RPC_BUF_SIZE, 0);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_SET_PROPERTIES, 0, res, 4, res, 4, 0, 0);
    r = *res;
    EZNETCTL_LOG_HEADER();
    scePrintf("ezNetCtlSetProperties returned %d\n", r);
    return r;
}

/* Selects entry `usrName` of configuration file `fname` for the interface. */
int ezNetCtlSetCombination(char *fname, char *usrName)
{
    char *res = ezNetCtl_rpcBuf;
    int r;
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    Libc_Strcpy(res + 0x10, fname);
    Libc_Strcpy(res + 0x110, usrName);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_SET_COMBINATION, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    r = *(int *)res;
    EZNETCTL_LOG_HEADER();
    scePrintf("ezNetCtlSetCombination returned %d\n", r);
    return r;
}

int ezNetCtlPreloadModemCnf(char *name)
{
    char *res = ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    Libc_Strcpy(res + 0x10, name);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_PRELOAD_MODEM_CNF, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    EZNETCTL_LOG_HEADER();
    scePrintf("ezNetCtlPreloadModemCnf returned %d\n", *(int *)res);
    return *(int *)res;
}

/* RPC function 5, no arguments; returns the reply word (role unknown). */
int ezNetCtlUpInterface(void)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_5, 0, res, 4, res, 4, 0, 0);
    return *res;
}

/* RPC function 6, no arguments; returns the reply word (role unknown;
 * used by SFOLobby_Config). */
int ezNetCtlDownInterface(void)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_6, 0, res, 4, res, 4, 0, 0);
    return *res;
}

/* Fills the 0x110-byte status block `buf`; its first word is the result. */
int ezNetCtlGetStatus(int *buf)
{
    if (!ezNetCtl_rpcBound) {
        EZNETCTL_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_GET_STATUS, 0, buf, 0x110, buf, 0x110, 0, 0);
    if (*buf) {
        EZNETCTL_LOG_HEADER();
        scePrintf("ezNetCtlGetStatus returned %d\n", *buf);
    }
    return *buf;
}

/* Copies `size` bytes from EE `src` to IOP `dst` with one SIF DMA transfer
 * (size rounded up to 16); waits for completion unless `async`. */
int dmaIOP(int src, int dst, int size, int async)
{
    struct { int data, addr, size, mode; } p; /* sceSifDmaData */
    int r;
    p.data = src;
    p.addr = dst;
    p.size = (size + 0xF) & ~0xF;
    p.mode = 0;
    if (size & 0xF) {
        EZNETCTL_LOG_HEADER();
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
