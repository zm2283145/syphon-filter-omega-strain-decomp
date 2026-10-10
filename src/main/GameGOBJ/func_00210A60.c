#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern int func_00171EB0(void*);
extern int* func_00171EA0(void*, int);

/* Script: cInteractGOBJ.GetTarget(index) -> target handle or 0. */
int Script_cInteractGOBJ_GetTarget(ScriptArg* args) {
    volatile int result;
    int index[1];
    char* self;
    int indexValue;
    int target;
    index[0] = args[1].i;
    self = args[0].p;
    indexValue = *(int*)index;
    if (func_00171EB0(self + 0x98) != 0) {
        target = *func_00171EA0(self + 0x98, indexValue);
    } else {
        target = 0;
    }
    result = target;
    return result;
}
