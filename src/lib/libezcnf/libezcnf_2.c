/*
 * lib/libezcnf: 2 files, 0033F688-0033F770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033F688 */
#include "sif_rpc_types.h"
#include "ezNet.h"
extern int ezNetCnf_rpcBound;
extern char ezNetCnf_rpcBuf[];
extern SifRpcClientData ezNetCnf_cd;
extern char ezNetCnf_logPrefix[];
extern char ezNetCnf_srcFile[];
extern int scePrintf(const char *, ...);
extern int sceSifCallRpc(SifRpcClientData *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endFunc, void *endParam);
extern void String_Copy(char *, char *);
/* Asks the IOP module to read the combination list of configuration file
 * `fname`; `list` is the EE address of the result it fills in. */
int ezNetCnfGetCombinationList(char *fname, int type, int list)
{
    char *res = ezNetCnf_rpcBuf;
    if (!ezNetCnf_rpcBound) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("RPC service not running\n");
        return -1;
    }
    if (EZNET_RPC_NAMES_SIZE > EZNET_RPC_BUF_SIZE) { /* inlined RPC size check, constant-false here: only its message remains */
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("RPC data size 0x%x exceeds buffer size 0x%x\n", EZNET_RPC_NAMES_SIZE, EZNET_RPC_BUF_SIZE);
        return -1;
    }
    String_Copy(res + 0x10, fname);
    ((int *)res)[0] = list;
    ((int *)res)[1] = type;
    sceSifCallRpc(&ezNetCnf_cd, EZNETCNF_FNO_GET_COMBINATION_LIST, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
    scePrintf("ezNetCnfGetCombinationList returned %d\n", *(int *)res);
    return *(int *)res;
}
/* merge_units: end func_0033F688 */

/* merge_units: begin func_0033F770 */
/* Combination list filled in by ezNetCnfGetCombinationList: a count, then 0x68-byte entries. */
typedef struct { char b[0x68]; } EzNetCnfCombination;
typedef struct { int listLength; char pad[0x2C]; EzNetCnfCombination list[1]; } EzNetCnfCombinationList;
/* Returns entry `idx` (1-based) of the list, or 0. */
EzNetCnfCombination *ezNetCnfGetCombination(EzNetCnfCombinationList *t, int idx)
{
    if (t == 0 || t->listLength == 0) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("ezNetCnfGetCombination: pList is empty\n");
        return 0;
    }
    if (idx <= 0 || t->listLength < idx) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("ezNetCnfGetCombination: invalid Combination number (%d)\n", idx);
        return 0;
    }
    return &t->list[idx - 1];
}
/* merge_units: end func_0033F770 */
