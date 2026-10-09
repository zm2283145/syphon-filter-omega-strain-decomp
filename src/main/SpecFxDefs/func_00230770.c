/*
 * Matched functions (byte-identical with the retail executable).
 * SpawnParticle script native.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern int GObj_IdentityB(void* obj);
extern int Global_SpawnParticle(int particle, int target, int c);

/* Script native: SpawnParticle(type, obj). */
int Script_SpawnParticle(ScriptArg* args) {
    int particle = (signed char)args[0].i;

    Global_SpawnParticle(particle, GObj_IdentityB(args[1].p), 1);
    return 0;
}
