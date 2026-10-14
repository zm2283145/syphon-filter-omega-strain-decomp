/*
 * libezcnf.c: EE client of the SCE ezNetCnf sample IOP module (eznetcnf.irx),
 * which reads network configuration files (see ezNet.h).
 * Compiler: EE-GCC 2.96 -O2 -G0.
 */
#include "ezNet.h"

extern int ezNetCnf_modId;
extern int ezNetCnf_rpcBound;
extern SifRpcClientData ezNetCnf_cd;
extern char ezNetCnf_rpcBuf[];

#define EZNETCNF_LOG_HEADER() scePrintf("%s> ", "libezcnf.c")

/* Combination list filled in by ezNetCnfGetCombinationList: a count, then 0x68-byte entries. */
typedef struct { char b[0x68]; } EzNetCnfCombination;
typedef struct { int listLength; char pad[0x2C]; EzNetCnfCombination list[1]; } EzNetCnfCombinationList;
/* The same list as ezNetCnfGetDefault reads it: unsigned counts. */
typedef struct {
    unsigned int listLength;
    unsigned int defaultNumber;
    char pad[0x28];
    EzNetCnfCombination list[1];
} EzNetCnfCombinationListU;

/* Finds eznetcnf.irx and binds its RPC server (retries until bound). */
int ezNetCnfInit(void)
{
    int r, i;
    if ((ezNetCnf_modId = sceSifSearchModuleByName("eznetcnf")) < 0) {
        EZNETCNF_LOG_HEADER();
        scePrintf("%s module not found\n", "eznetcnf");
    }
    for (;;) {
        r = sceSifBindRpc(&ezNetCnf_cd, EZNETCNF_RPC_ID, 0);
        i = 0x10000;
        if (r < 0) {
            EZNETCNF_LOG_HEADER();
            scePrintf("Could not bind to RPC service\n");
        }
        if (ezNetCnf_cd.server) break;
        while (--i != -1)
            ;
    }
    ezNetCnf_rpcBound = 1;
    return r;
}

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

/* Asks the IOP module to read the combination list of configuration file
 * `fname`; `list` is the EE address of the result it fills in. */
int ezNetCnfGetCombinationList(char *fname, int type, int list)
{
    char *res = ezNetCnf_rpcBuf;
    if (!ezNetCnf_rpcBound) {
        EZNETCNF_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    if (EZNET_RPC_NAMES_SIZE > EZNET_RPC_BUF_SIZE) { /* inlined RPC size check, constant-false here: only its message remains */
        EZNETCNF_LOG_HEADER();
        scePrintf("RPC data size 0x%x exceeds buffer size 0x%x\n", EZNET_RPC_NAMES_SIZE, EZNET_RPC_BUF_SIZE);
        return -1;
    }
    String_Copy(res + 0x10, fname);
    ((int *)res)[0] = list;
    ((int *)res)[1] = type;
    sceSifCallRpc(&ezNetCnf_cd, EZNETCNF_FNO_GET_COMBINATION_LIST, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    EZNETCNF_LOG_HEADER();
    scePrintf("ezNetCnfGetCombinationList returned %d\n", *(int *)res);
    return *(int *)res;
}

/* Returns entry `idx` (1-based) of the list, or 0. */
EzNetCnfCombination *ezNetCnfGetCombination(EzNetCnfCombinationList *t, int idx)
{
    if (t == 0 || t->listLength == 0) {
        EZNETCNF_LOG_HEADER();
        scePrintf("ezNetCnfGetCombination: pList is empty\n");
        return 0;
    }
    if (idx <= 0 || t->listLength < idx) {
        EZNETCNF_LOG_HEADER();
        scePrintf("ezNetCnfGetCombination: invalid Combination number (%d)\n", idx);
        return 0;
    }
    return &t->list[idx - 1];
}

/* Returns the default entry (defaultNumber, 1-based) of the list, or 0. */
EzNetCnfCombination *ezNetCnfGetDefault(EzNetCnfCombinationListU *t)
{
    if (t == 0 || t->listLength == 0) {
        EZNETCNF_LOG_HEADER();
        scePrintf("ezNetCnfGetDefault: pList is empty\n");
        return 0;
    }
    if (t->listLength < t->defaultNumber) {
        EZNETCNF_LOG_HEADER();
        scePrintf("ezNetCnfGetDefault: defaultNumber (%d) exceeds listLength\n", t->defaultNumber);
        return 0;
    }
    return &t->list[t->defaultNumber - 1];
}

/* Asks the IOP module to read entry `usrName` of configuration file `fname`;
 * `data` is the EE address of the result it fills in. */
int ezNetCnfGetProperties(char *fname, char *usrName, int data)
{
    char *res = ezNetCnf_rpcBuf;
    if (!ezNetCnf_rpcBound) {
        EZNETCNF_LOG_HEADER();
        scePrintf("RPC service not running\n");
        return -1;
    }
    String_Copy(res + 0x10, fname);
    String_Copy(res + 0x110, usrName);
    ((int *)res)[0] = data;
    sceSifCallRpc(&ezNetCnf_cd, EZNETCNF_FNO_GET_PROPERTIES, 0, res, EZNET_RPC_NAMES_SIZE, res, EZNET_RPC_NAMES_SIZE, 0, 0);
    EZNETCNF_LOG_HEADER();
    scePrintf("ezNetCnfGetProperties returned %d\n", *(int *)res);
    return *(int *)res;
}
