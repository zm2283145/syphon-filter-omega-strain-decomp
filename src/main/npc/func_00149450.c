/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern void cNPC_SetMaxActiveNpcCount(int count);

/* Script: cNPC.SetMaxActiveNpcCount(count). */
int Script_cNPC_SetMaxActiveNpcCount(NpcScriptArgs* args) {
    int count[1]; /* staged through the stack like the other argument readers */

    *(int*)(char*)count = args->arg1;
    cNPC_SetMaxActiveNpcCount(*(int*)(char*)count);
    return 0;
}
