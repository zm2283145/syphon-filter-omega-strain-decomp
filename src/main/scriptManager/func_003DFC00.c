#include "types.h"

extern void Script_Reschedule_3DFC40(int target, float delay);

typedef union { int i; void* p; float f; } ScriptArg;

/* Script native: reschedules target args[0] after args[1] seconds. */
int Script_Reschedule(ScriptArg* args)
{
    volatile int delay = args[1].i;
    volatile int target = args[0].i;
    Script_Reschedule_3DFC40(target, *(float*)&delay);
    return 0;
}
