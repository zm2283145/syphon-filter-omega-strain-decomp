#include "types.h"
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268BF0;
typedef struct { float* data; int cap; int count; } Arr_268BF0;
extern Arr_268BF0* ScriptArray_Cast(int h);
static inline float Get_268BF0(Arr_268BF0* a, int i)
{
    if (i >= 0 && i < a->count)
        return a->data[i];
    return 0.0f;
}
static inline void Remove_268BF0(Arr_268BF0* a, int i)
{
    if (i >= 0 && i < a->count) {
        for (; i < a->count - 1; i++)
            a->data[i] = a->data[i + 1];
        a->count--;
    }
}
int Script_Array_GetAndRemoveIndex(ScriptArg_268BF0* args)
{
    int idx[1];
    float r[1];
    Arr_268BF0* a;
    int i;
    idx[0] = args[1].i;
    i = *(int*)idx;
    a = ScriptArray_Cast(args[0].i);
    {
        float v = Get_268BF0(a, i);
        Remove_268BF0(a, i);
        r[0] = v;
    }
    return *(int*)r;
}