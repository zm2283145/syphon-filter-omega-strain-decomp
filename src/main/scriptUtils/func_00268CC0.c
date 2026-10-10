#include "types.h"
typedef struct { float* data; int pad; int count; } ScriptArr_e1;
extern ScriptArr_e1* func_002690C0(int);
int Script_Array_GetIndex(int* args)
{
    volatile int idx = args[1];
    volatile float r;
    int i = idx;
    ScriptArr_e1* a = func_002690C0(args[0]);
    float f;
    if (i >= 0 && i < a->count) {
        f = a->data[i];
    } else {
        f = 0.0f;
    }
    r = f;
    return *(int*)&r;
}