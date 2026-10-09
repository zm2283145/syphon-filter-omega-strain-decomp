/*
 * Matched functions (byte-identical with the retail executable).
 * cNetSpawnParticleMsg serialization and the Shatter script native.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern signed char* D_005061D0;   /* network message byte cursor */
extern void* GObj_IdentityB(void* obj);
extern int Global_Shatter(void* a, void* b, int c);
extern int Global_SpawnParticle(int particle, int target, int c);
extern void func_00282020(int handle);    /* writes an object handle to the stream */
extern int func_00282160(int* handle);    /* reads an object handle from the stream */

/* Reads the message from the network stream and spawns the particle. */
int cNetSpawnParticleMsg_Receive(cNetSpawnParticleMsg* msg) {
    signed char* cursor;
    signed char particle;

    func_00282160(&msg->target);
    cursor = D_005061D0;
    particle = *cursor;
    D_005061D0 = cursor + 1;
    msg->particle = particle;
    return Global_SpawnParticle(msg->particle, msg->target, 0);
}

/* Writes the message to the network stream. */
void cNetSpawnParticleMsg_v04(cNetSpawnParticleMsg* msg) {
    func_00282020(msg->target);
    *D_005061D0 = msg->particle;
    D_005061D0++;
}

/* Script native: Shatter(obj0, obj1). */
int Script_Shatter(ScriptArg* args) {
    void* a = GObj_IdentityB(args[0].p);

    Global_Shatter(a, GObj_IdentityB(args[1].p), 0);
    return 0;
}
