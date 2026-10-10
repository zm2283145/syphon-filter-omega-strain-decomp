#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char data[0x1C]; } Medal;
extern char D_00532A90[];
extern void* func_0032FFD0(Medal* m, int a, int b, int c, int d, int e);
extern void func_00147600(void* registry, void* item);

/* Script native: builds a medal from args[0..3] (last field 0) and registers it; returns 0. */
int Script_cAgentData__RegisterMedal(ScriptArg* args)
{
    Medal m;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A90, func_0032FFD0(&m, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, 0));
    return 0;
}
