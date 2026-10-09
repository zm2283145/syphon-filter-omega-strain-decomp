/*
 * Matched functions (byte-identical with the retail executable).
 * SetCheckpointFont script native and its setter.
 */

#include "types.h"
#include "Checkpoint_types.h"

extern unsigned char D_004F7960; /* current checkpoint font index */
extern void Checkpoint_SetFont(int font);

/* SetCheckpointFont(font) */
int Script_SetCheckpointFont(CheckpointScriptArg* args) {
    Checkpoint_SetFont(args[0].u8);
    return 0;
}

void Checkpoint_SetFont(int font) {
    D_004F7960 = font;
}
