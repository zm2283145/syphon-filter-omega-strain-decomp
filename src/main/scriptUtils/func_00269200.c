#include "types.h"

extern float Global_Random(float max);

/* Script native: returns a random float in [0, args[0]). */
int Script_Random(int* args)
{
    volatile float result;
    int x[1];
    x[0] = args[0];
    result = Global_Random(*(float*)x);
    return *(int*)&result;
}
