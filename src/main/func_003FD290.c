#include "types.h"
typedef union { int i; void* p; float f; } ScriptArg;
extern int func_003FD2C0(int id);
/* Script native: returns the string for the id argument. */
int Script_GetString(ScriptArg* args)
{
    volatile int result;
    volatile int id = args[0].i;
    result = func_003FD2C0(id);
    return result;
}
