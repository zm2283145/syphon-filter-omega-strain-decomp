#include "types.h"

typedef union { int i; float f; } ScriptArg;

extern float Global_Random_2(float lo, float hi);

/* Script native: returns a random float between two bounds, as raw bits. */
int Script_Random_2(ScriptArg* args)
{
    ScriptArg result[1];
    ScriptArg hi[1];
    ScriptArg lo[1];
    hi[0].i = args[1].i;
    lo[0].i = args[0].i;
    result[0].f = Global_Random_2(lo[0].f, hi[0].f);
    return result[0].i;
}
