/*
 * Matched functions (byte-identical with the retail executable).
 * SetCheckpoint script native.
 */

#include "types.h"
#include "Checkpoint_types.h"

extern int Global_SetCheckpoint(int checkpoint, int object, int value);

/* SetCheckpoint(checkpoint, object, value) */
int Script_SetCheckpoint(CheckpointScriptArg* args) {
    volatile int value = args[2].i; /* original stack temporary */
    int checkpoint = func_00175FA0(args[0].i);
    int object = GObj_IdentityB(args[1].i);
    Global_SetCheckpoint(checkpoint, object, value);
    return 0;
}
