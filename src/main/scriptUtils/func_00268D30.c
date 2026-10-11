#include "types.h"
typedef union { int i; float f; void* p; } ScriptArg_268D30;
typedef struct { float* data; int cap; int count; } Arr_268D30;
extern Arr_268D30* func_002690C0(int h);
extern float func_002692D0(float max);
int Script_Array_RandomizeArray(ScriptArg_268D30* args)
{
    Arr_268D30* a = func_002690C0(args[0].i);
    int i;
    for (i = a->count; i > 0; i--) {
        int j = (int)func_002692D0((float)i);
        float t = a->data[i - 1];
        a->data[i - 1] = a->data[j];
        a->data[j] = t;
    }
    return 0;
}