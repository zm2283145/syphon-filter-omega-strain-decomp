#include "types.h"
typedef union { int i; void* p; float f; } ScriptArg;
extern void func_002693F0(int s);
/* Script native: prints its argument. */
int Script_Print(ScriptArg* args)
{
    volatile int s = args[0].i;
    func_002693F0(s);
    return 0;
}
