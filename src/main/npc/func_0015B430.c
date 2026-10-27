/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cGOBJ_SOBJ_convert(int handle);

/* Script: LosCam(a, b); resolves both handles, result unused. */
int Script_LosCam(NpcScriptArgs* args) {
    cGOBJ_SOBJ_convert(args->arg1);
    cGOBJ_SOBJ_convert((int)args->npc);
    return 0;
}
