#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCnf_rpcBound;
extern char ezNetCnf_rpcBuf[];
extern SifRpcClientData ezNetCnf_cd;
extern char ezNetCnf_logPrefix[];
extern char ezNetCnf_srcFile[];
extern char ezNetCnf_msgNotRunning[];
extern int scePrintf(const char *, ...);
extern int sceSifCallRpc(SifRpcClientData *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endFunc, void *endParam);
extern void String_Copy(char *, char *);
/* Asks the IOP module to read entry `usrName` of configuration file `fname`;
 * `data` is the EE address of the result it fills in. */
int ezNetCnfGetProperties(char *fname, char *usrName, int data)
{
    char *res = ezNetCnf_rpcBuf;
    if (!ezNetCnf_rpcBound) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf(ezNetCnf_msgNotRunning);
        return -1;
    }
    String_Copy(res + 0x10, fname);
    String_Copy(res + 0x110, usrName);
    ((int *)res)[0] = data;
    sceSifCallRpc(&ezNetCnf_cd, EZNETCNF_FNO_GET_PROPERTIES, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
    scePrintf("ezNetCnfGetProperties returned %d\n", *(int *)res);
    return *(int *)res;
}
