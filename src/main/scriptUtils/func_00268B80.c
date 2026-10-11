#include "types.h"
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268B80;
typedef struct { float* data; int cap; int count; } Arr_268B80;
extern Arr_268B80* func_002690C0(int h);
static inline void SetIdx_268B80(int h, int i, float v)
{
    Arr_268B80* a = func_002690C0(h);
    if (i >= 0 && i < a->count)
        a->data[i] = v;
}
int Script_Array_ChangeIndex(ScriptArg_268B80* args)
{
    int v[1];
    int idx[1];
    v[0] = args[2].i;
    idx[0] = args[1].i;
    SetIdx_268B80(args[0].i, *(int*)idx, *(float*)v);
    return 0;
}