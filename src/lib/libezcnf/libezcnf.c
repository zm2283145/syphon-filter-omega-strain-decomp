/*
 * lib/libezcnf: 2 files, 0033F508-0033F608
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033F508 */
#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCnf_modId;
extern int ezNetCnf_rpcBound;
extern SifRpcClientData ezNetCnf_cd;
extern char ezNetCnf_logPrefix[], ezNetCnf_srcFile[], ezNetCnf_msgModuleNotFound[], ezNetCnf_msgBindFailed[];
extern int scePrintf(const char *, ...);
extern int sceSifSearchModuleByName(char *);
extern int sceSifBindRpc(SifRpcClientData *cd, unsigned int rpcId, int mode);
/* Finds eznetcnf.irx and binds its RPC server (retries until bound). */
int ezNetCnfInit(void)
{
    int r, i;
    if ((ezNetCnf_modId = sceSifSearchModuleByName("eznetcnf")) < 0) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf(ezNetCnf_msgModuleNotFound, "eznetcnf");
    }
    for (;;) {
        r = sceSifBindRpc(&ezNetCnf_cd, EZNETCNF_RPC_ID, 0);
        i = 0x10000;
        if (r < 0) {
            scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
            scePrintf(ezNetCnf_msgBindFailed);
        }
        if (ezNetCnf_cd.server) break;
        while (--i != -1)
            ;
    }
    ezNetCnf_rpcBound = 1;
    return r;
}
/* merge_units: end func_0033F508 */

/* merge_units: begin func_0033F608 */
extern int sceSifStopModule(int fd, int a, int b, int *stat);
extern int sceSifUnloadModule(int fd);
/* Stops and unloads eznetcnf.irx. */
int ezNetCnfExit(void)
{
    int stat;
    if (ezNetCnf_rpcBound == 1) {
        if (sceSifStopModule(ezNetCnf_modId, 0, 0, &stat) >= 0) {
            stat = sceSifUnloadModule(ezNetCnf_modId);
            if (stat >= 0) {
                ezNetCnf_rpcBound = 0;
                stat = 0;
            }
        }
    }
    return stat;
}
/* merge_units: end func_0033F608 */
