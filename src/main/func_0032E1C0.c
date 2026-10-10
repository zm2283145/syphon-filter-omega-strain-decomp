#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char data[0x1C]; } OmegaReq;
extern char D_00532BB0[];
extern void* func_0032E260(OmegaReq* r, int a, int zero, int e, int b, int c, int d);
extern void func_0032E230(void* registry, void* item);

/* Script native: builds an Omega requirement from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterOmegaReq_2(ScriptArg* args)
{
    OmegaReq r;
    int p4[1];
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_0032E230(D_00532BB0, func_0032E260(&r, *(int*)p0, 0, *(int*)p4, *(int*)p1, *(int*)p2, *(int*)p3));
    return 0;
}
