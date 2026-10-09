/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int GObj_IdentityB(int handle);

/* Script: LosCam(a, b); resolves both handles, result unused. */
int Script_LosCam(NpcScriptArgs* args) {
    GObj_IdentityB(args->arg1);
    GObj_IdentityB((int)args->npc);
    return 0;
}
