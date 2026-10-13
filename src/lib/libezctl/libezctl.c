/*
 * lib/libezctl: 2 files, 00352CD0-00352DD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00352CD0 */
#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCtl_modId;
extern int ezNetCtl_rpcBound;
extern SifRpcClientData ezNetCtl_cd;
extern char ezNetCtl_logPrefix[], ezNetCtl_srcFile[], ezNetCtl_msgModuleNotFound[], ezNetCtl_msgBindFailed[];
extern int scePrintf(const char *, ...);
extern int sceSifSearchModuleByName(char *);
extern int sceSifBindRpc(SifRpcClientData *cd, unsigned int rpcId, int mode);
/* Finds eznetctl_inet.irx and binds its RPC server (retries until bound). */
int ezNetCtlInit(void)
{
    int r, i;
    if ((ezNetCtl_modId = sceSifSearchModuleByName("eznetctl_inet")) < 0) {
        scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
        scePrintf(ezNetCtl_msgModuleNotFound, "eznetctl_inet");
    }
    for (;;) {
        r = sceSifBindRpc(&ezNetCtl_cd, EZNETCTL_RPC_ID, 0);
        i = 0x10000;
        if (r < 0) {
            scePrintf(ezNetCtl_logPrefix, ezNetCtl_srcFile);
            scePrintf(ezNetCtl_msgBindFailed);
        }
        if (ezNetCtl_cd.server) break;
        while (--i != -1)
            ;
    }
    ezNetCtl_rpcBound = 1;
    return r;
}
/* merge_units: end func_00352CD0 */

/* merge_units: begin func_00352DD0 */
extern int sceSifStopModule(int fd, int a, int b, int *stat);
extern int sceSifUnloadModule(int fd);
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
/* merge_units: end func_00352DD0 */
