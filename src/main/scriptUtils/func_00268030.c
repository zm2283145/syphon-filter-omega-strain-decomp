#include "types.h"
typedef union { int i; void* p; } ScriptArg;
extern void* func_0014A690(void* p);
extern void Global_SetCalloutLabel_2(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_4(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = func_0014A690(args[0].p);
    Global_SetCalloutLabel_2(obj, *(int*)labelArg, value, flag);
    return 0;
}