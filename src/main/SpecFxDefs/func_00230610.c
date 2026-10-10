#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void* GObj_IdentityB(void*);
extern void Global_SpawnLight(void*, int, float, float);

/* Script: SpawnLight(owner, a, b); arguments are staged through the stack. */
int Script_SpawnLight(ScriptArg* args) {
    int b[1];
    int a[1];
    float bValue;
    void* owner;
    b[0] = args[2].i;
    a[0] = args[1].i;
    bValue = *(float*)b;
    owner = GObj_IdentityB(args[0].p);
    Global_SpawnLight(owner, 1, *(float*)a, bValue);
    return 0;
}
