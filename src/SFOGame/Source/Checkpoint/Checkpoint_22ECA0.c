/*
 * main/Checkpoint: range (2 files, 0022ECA0-0022ED00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "Checkpoint_types.h"

/* merge_units: begin func_0022ECA0 */
#pragma push /* merge_units */
typedef struct cCheckpoint {
    void* vtable;
    char pad[0x5C];
    int unk60;
    int unk64;
    char pad2[8];
    int unk70;
} cCheckpoint;

extern char D_004F7980[];
extern char D_004DB8F0[]; /* cCheckpoint vtable */
extern void cGOBJ_ctor(cCheckpoint* self, int* handle, int flags, const char* name);

/* cCheckpoint constructor. */
cCheckpoint* cCheckpoint_ctor(cCheckpoint* self) {
    int handle = -1;
    cGOBJ_ctor(self, &handle, 0, D_004F7980);
    self->vtable = D_004DB8F0;
    self->unk60 = 100;
    self->unk64 = 100;
    self->unk70 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022ECA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022ECA0 */

/* merge_units: begin func_0022ED00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * SetCheckpointFont script native and its setter.
 */


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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022ED00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022ED00 */
