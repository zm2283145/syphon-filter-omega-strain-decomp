#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
    unsigned char uc;
} ScriptArg;

typedef struct Ratio {
    char b[0x20];
} Ratio;

extern int D_00532A70;
extern void* func_0032FF50(Ratio*, int, int, int, int, unsigned char);
extern void func_00147600(void*, void*);

/* Script: cAgentData::RegisterSpecialRatio(a, b, c, d, flag). */
int Script_cAgentData__RegisterSpecialRati_3(ScriptArg* args) {
    Ratio ratio;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    unsigned char flag = args[4].uc;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_00147600(&D_00532A70, func_0032FF50(&ratio, *(int*)a, *(int*)b, *(int*)c, *(int*)d, flag));
    return 0;
}
