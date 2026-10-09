/*
 * Matched functions (byte-identical with the retail executable).
 * ReSpawn script native.
 */

#include "types.h"
#include "Checkpoint_types.h"

extern int Global_ReSpawn(int checkpoint);

/* ReSpawn(checkpoint) */
int Script_ReSpawn(CheckpointScriptArg* args) {
    Global_ReSpawn(func_00175FA0(args[0].i));
    return 0;
}
