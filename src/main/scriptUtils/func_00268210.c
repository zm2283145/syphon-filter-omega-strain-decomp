#include "types.h"
typedef union { int i; void* p; } ScriptArg;
extern void* GObj_IdentityB(void* p);
extern void Global_SetCalloutLabel(void* obj, int label, int value, int flag);int Script_SetCalloutLabel_2(ScriptArg* args)
{
int labelArg[1]; int valueArg[1]; int flag; int value;
    void* obj;
    flag = args[3].i != 0;
    valueArg[0] = args[2].i;
    labelArg[0] = args[1].i;
    value = *(int*)valueArg;
    obj = GObj_IdentityB(args[0].p);
    Global_SetCalloutLabel(obj, *(int*)labelArg, value, flag);
    return 0;
}