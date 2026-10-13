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
/* Selects entry `usrName` of configuration file `fname` for the interface. */
int ezNetCtlSetCombination(char *fname, char *usrName)
{
    char *res = ezNetCtl_rpcBuf;
    int r;
    if (!ezNetCtl_rpcBound) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgNotRunning);
        return -1;
    }
    String_Copy(res + 0x10, fname);
    String_Copy(res + 0x110, usrName);
    sceSifCallRpc(&ezNetCtl_cd, EZNETCTL_FNO_SET_COMBINATION, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    r = *(int *)res;
    scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
    scePrintf("ezNetCtlSetCombination returned %d\n", r);
    return r;
}
