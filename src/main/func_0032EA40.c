#include "types.h"

typedef union { int i; unsigned char b; void* p; } ScriptArg;
typedef struct { char data[0x28]; } RankReq;

extern char D_00532B50[];
extern int func_0032EB80(void* list);
extern void* func_0032EB00(RankReq* req, int a, int b, int id, int index, int flag);
extern void func_0032EAD0(void* list, void* item);

/* Script native: registers a rank requirement with the agent data. */
int Script_cAgentData__RegisterRank_4(ScriptArg* args)
{
    RankReq req;
    int bArg[1];
    int aArg[1];
    int a;
    int b;
    unsigned char rank;
    rank = args[2].b;
    bArg[0] = args[1].i;
    b = *(int*)bArg;
    aArg[0] = args[0].i;
    a = *(int*)aArg;
    func_0032EAD0(D_00532B50, func_0032EB00(&req, a, b, rank + 10000, func_0032EB80(D_00532B50), 0));
    return 0;
}
