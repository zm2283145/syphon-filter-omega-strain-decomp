/*
 * SFOGame/Source/SpecFxDefs: 1 file, 00230CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00230CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNetSpawnParticleMsg serialization and the Shatter script native.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern signed char* D_005061D0;   /* network message byte cursor */
extern void* cGOBJ_SOBJ_convert(void* obj);
extern int Global_Shatter(void* a, void* b, int c);
extern int Global_SpawnParticle(int particle, int target, int c);
extern void cNetMsg_PutGOBJ(int handle);    /* writes an object handle to the stream */
extern int cNetMsg_GetGOBJ(int* handle);    /* reads an object handle from the stream */

/* Reads the message from the network stream and spawns the particle. */
int cNetSpawnParticleMsg_UnpackAndProcess(cNetSpawnParticleMsg* msg) {
    signed char* cursor;
    signed char particle;

    cNetMsg_GetGOBJ(&msg->target);
    cursor = D_005061D0;
    particle = *cursor;
    D_005061D0 = cursor + 1;
    msg->particle = particle;
    return Global_SpawnParticle(msg->particle, msg->target, 0);
}

/* Writes the message to the network stream. */
void cNetSpawnParticleMsg_Pack(cNetSpawnParticleMsg* msg) {
    cNetMsg_PutGOBJ(msg->target);
    *D_005061D0 = msg->particle;
    D_005061D0++;
}

/* Script native: Shatter(obj0, obj1). */
int Script_Shatter(ScriptArg* args) {
    void* a = cGOBJ_SOBJ_convert(args[0].p);

    Global_Shatter(a, cGOBJ_SOBJ_convert(args[1].p), 0);
    return 0;
}
static inline void merge_flush_func_00230CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00230CE0 */
