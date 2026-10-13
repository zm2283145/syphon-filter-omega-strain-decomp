#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCtl_rpcBound;
extern char ezNetCtl_rpcBuf[];
extern SifRpcClientData ezNetCtl_cd;
extern char ezNetCtl_logPrefix[];
extern char ezNetCtl_srcFile[];
extern void scePrintf(const char *, ...);
extern int sceSifCallRpc(SifRpcClientData *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endFunc, void *endParam);
extern int ezNetCtl_SifDmaSend(int, int, int, int);
/* Sends the EE properties block at `props` (EZNET_RPC_BUF_SIZE bytes): asks
 * the IOP module where to put it, DMAs it there and applies it. */
int ezNetCtlSetProperties(int props)
{
    int *res = (int *)ezNetCtl_rpcBuf;
    int r;
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf("RPC service not running\n");
        return -1;
    }
    if (4 > EZNET_RPC_BUF_SIZE) { /* inlined RPC size check, constant-false here: only its message remains */
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf("RPC data size 0x%x exceeds buffer size 0x%x\n", 4, EZNET_RPC_BUF_SIZE);
        return -1;
    }
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_GET_PROPERTIES_ADDRESS, 0, res, 4, res, 4, 0, 0);
    if (*res == 0) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf("eCtlGetPropertiesAddress returned NULL\n");
        *res = -2;
        return -2;
    }
    ezNetCtl_SifDmaSend(props, *res, EZNET_RPC_BUF_SIZE, 0);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_SET_PROPERTIES, 0, res, 4, res, 4, 0, 0);
    r = *res;
    scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
    scePrintf("ezNetCtlSetProperties returned %d\n", r);
    return r;
}
