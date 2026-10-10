#include "types.h"

typedef union { int i; void* p; } ScriptArg;
typedef struct { char data[0x24]; } BonusReq;

extern char D_00532AA0[];
extern void* func_0032FFD0(BonusReq* req, int level, int a, int b, int c, int d);
extern void func_00147600(void* list, void* item);

/* Script native: registers a bonus level requirement with the agent data. */
int Script_cAgentData__RegisterBonusLevel(ScriptArg* args)
{
    BonusReq req;
    int c[1];
    int b[1];
    int level[1];
    c[0] = args[2].i;
    b[0] = args[1].i;
    level[0] = args[0].i;
    func_00147600(D_00532AA0, func_0032FFD0(&req, *(int*)level, 0, *(int*)b, *(int*)c, 0));
    return 0;
}
