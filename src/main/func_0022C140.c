#include "types.h"

typedef union { int i; float f; void* p; } ScriptArg;

extern void* GObj_IdentityB(void* p);
extern void Radar_SetBlipDeprecated(void* obj, float value);

/* Script native: sets a radar blip value on the resolved object. */
int Script_SetRadarBlip_2(ScriptArg* args)
{
    ScriptArg value[1];
    value[0].i = args[1].i;
    Radar_SetBlipDeprecated(GObj_IdentityB(args[0].p), value[0].f);
    return 0;
}
