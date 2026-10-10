#include "types.h"

typedef union { int i; float f; } ScriptArg;

extern float func_002692D0(float range);

/* Script native: returns a random value for the given range, as raw bits. */
int Script_RandomInt(ScriptArg* args)
{
    ScriptArg out[1];
    ScriptArg in[1];
    in[0].i = args[0].i;
    out[0].f = func_002692D0(in[0].f);
    return out[0].i;
}
