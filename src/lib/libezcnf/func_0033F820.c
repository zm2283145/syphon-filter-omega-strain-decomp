#include "sif_rpc_types.h"
#include "ezNet.h"
/* Same list as ezNetCnfGetCombination, read with unsigned counts here. */
typedef struct { char b[0x68]; } EzNetCnfCombination;
typedef struct { unsigned int listLength; unsigned int defaultNumber; char pad[0x28]; EzNetCnfCombination list[1]; } EzNetCnfCombinationList;
extern char ezNetCnf_logPrefix[];
extern char ezNetCnf_srcFile[];
extern int scePrintf(const char *, ...);
/* Returns the default entry (defaultNumber, 1-based) of the list, or 0. */
EzNetCnfCombination *ezNetCnfGetDefault(EzNetCnfCombinationList *t)
{
    if (t == 0 || t->listLength == 0) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("ezNetCnfGetDefault: pList is empty\n");
        return 0;
    }
    if (t->listLength < t->defaultNumber) {
        scePrintf(ezNetCnf_logPrefix, ezNetCnf_srcFile);
        scePrintf("ezNetCnfGetDefault: defaultNumber (%d) exceeds listLength\n", t->defaultNumber);
        return 0;
    }
    return &t->list[t->defaultNumber - 1];
}
