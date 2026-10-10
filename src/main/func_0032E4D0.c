#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x20]; } Medal;
extern char D_00532A90[];
extern void* func_0032FF50(Medal* c, int a, int b, int c2, int d, unsigned char e);
extern void func_00147600(void* registry, void* c);

/* Script native: builds a medal from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterMedal_3(ScriptArg* args)
{
    Medal c;
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    unsigned char e = args[4].b;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_00147600(D_00532A90, func_0032FF50(&c, *(int*)p0, *(int*)p1, *(int*)p2, *(int*)p3, e));
    return 0;
}
