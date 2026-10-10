#include "types.h"
extern void Global_SetObjectiveSuccColor(int objective, int a, int b, float c);
/* Script: SetObjectiveSuccColor(objective, a, b, c). */
int Script_SetObjectiveSuccColor(int* args)
{
    float c[1];
    int b[1];
    int a[1];
    int o[1];
    *(int*)c = args[3];
    b[0] = args[2];
    a[0] = args[1];
    o[0] = args[0];
    Global_SetObjectiveSuccColor(*(int*)o, *(int*)a, *(int*)b, *(float*)c);
    return 0;
}
