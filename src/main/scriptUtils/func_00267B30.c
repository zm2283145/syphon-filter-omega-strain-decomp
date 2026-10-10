#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* func_00175FA0(void* object);
extern void* func_0014A690(void* p);
extern float Global_Distance_3(void* a, void* b);

/* Script native: distance between the objects of args[0] and args[1], returned as float bits. */
int Script_Distance_3(ScriptArg* args)
{
    void* a = func_00175FA0(args[0].p);
    void* b = func_0014A690(args[1].p);
    float result = Global_Distance_3(a, b);
    return *(int*)&result;
}
