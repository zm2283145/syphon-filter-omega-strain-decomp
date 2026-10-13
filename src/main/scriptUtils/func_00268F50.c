#include "types.h"
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268F50;
typedef struct { float* data; int cap; int count; } Arr_268F50;
extern Arr_268F50* ScriptArray_Cast(int h);
static inline unsigned char Remove_268F50(int h, int i)
{
    Arr_268F50* a = ScriptArray_Cast(h);
    if (i >= 0 && i < a->count) {
        for (; i < a->count - 1; i++)
            a->data[i] = a->data[i + 1];
        a->count--;
        return 1;
    }
    return 0;
}
int Script_Array_RemoveIndex(ScriptArg_268F50* args)
{
    int idx[1];
    idx[0] = args[1].i;
    return Remove_268F50(args[0].i, *(int*)idx);
}