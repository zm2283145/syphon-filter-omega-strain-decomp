/*
 * main/Checkpoint: range (2 files, 0022E1A0-0022E1D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "Checkpoint_types.h"

/* merge_units: begin func_0022E1A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* target; } S;
void Global_ReSpawn(S* s); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * ReSpawn script native.
 */


#if 0 /* merge_units */
extern int Global_ReSpawn(int checkpoint);
#endif /* merge_units */
#define Global_ReSpawn(a0) (Global_ReSpawn((void *)(a0))) /* merge_units */


/* ReSpawn(checkpoint) */
int Script_ReSpawn(CheckpointScriptArg* args) {
    Global_ReSpawn(cPlayer_SOBJ_convert(args[0].i));
    return 0;
}
#undef Global_ReSpawn /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E1A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E1A0 */

/* merge_units: begin func_0022E1D0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int value; char pad3[8]; } Msg;

extern char D_004F7940[];
extern char D_004DB890[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a respawn message to the object's target. */
void Global_ReSpawn(S* s)
{
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7940);
    msg.value = 0;
    msg.vtable = D_004DB890;
    msg.flags = 0x40;
    QueueMessage_cMessageR_cSystemP_int(&msg, s->target, 0);
    msg.vtable = D_004DB890;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E1D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E1D0 */
