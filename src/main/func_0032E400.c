#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct OmegaReq {
    char b[0x20];
} OmegaReq;

extern int D_00532BB0;
extern void* func_0032E260(OmegaReq*, int, int, int, int, int, int);
extern void func_0032E230(void*, void*);

/* Script: cAgentData::RegisterOmegaReq(a, b, c, d). */
int Script_cAgentData__RegisterOmegaReq(ScriptArg* args) {
    OmegaReq req;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_0032E230(&D_00532BB0, func_0032E260(&req, *(int*)a, 0, 0, *(int*)b, *(int*)c, *(int*)d));
    return 0;
}
