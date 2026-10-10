#include "types.h"
#include "scriptUtils_types.h"
typedef struct { float* data; int pad; int count; } SAF_Arr;
extern SAF_Arr* func_002690C0(void* obj);
static inline int SAF_Find(SAF_Arr* arr, float val) {
    int i;
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i] == val) return i;
    }
    return -1;
}
int Script_Array_FindElem(ScriptArg* args) {
    volatile ScriptArg a;
    volatile int r;
    float val;
    a.i = args[1].i;
    val = a.f;
    r = SAF_Find(func_002690C0(args[0].p), val);
    return r;
}