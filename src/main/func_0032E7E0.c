#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct Ratio {
    char b[0x1C];
} Ratio;

extern int D_00532A70;
extern void* func_0032FFD0(Ratio*, int, int, int, int, int);
extern void func_00147600(void*, void*);

/* Script: cAgentData::RegisterSpecialRatio(a, b, c, d, e). */
int Script_cAgentData__RegisterSpecialRati_2(ScriptArg* args) {
    Ratio ratio;
    int e[1];
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    e[0] = args[4].i;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_00147600(&D_00532A70, func_0032FFD0(&ratio, *(int*)a, *(int*)b, *(int*)c, *(int*)d, *(int*)e));
    return 0;
}
