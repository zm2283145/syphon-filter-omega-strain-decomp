#include "types.h"

typedef union { int i; float f; } ScriptArg;

extern float Script_RandomIntCore(float range);

/* Script native: returns a random value for the given range, as raw bits. */
int Script_RandomInt(ScriptArg* args)
{
    ScriptArg out[1];
    ScriptArg in[1];
    in[0].i = args[0].i;
    out[0].f = Script_RandomIntCore(in[0].f);
    return out[0].i;
}
