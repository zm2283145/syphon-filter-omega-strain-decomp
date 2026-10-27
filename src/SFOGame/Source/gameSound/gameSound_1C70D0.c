/*
 * main/gameSound: range (2 files, 001C70D0-001C7100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "gameSound_types.h"

/* merge_units: begin func_001C70D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * SetReverb script native.
 */


extern void snd_SetReverbDepth(int unk0, int level1, int level2);

/* SetReverb(level): passes the level in both value slots. */
int Script_SetReverb(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int level = arg;
    snd_SetReverbDepth(1, level, level);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C70D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C70D0 */

/* merge_units: begin func_001C7100 */
#pragma push /* merge_units */
extern void nGameSound_StopAllQuips(int);

/* Script native: stops all quips. */
int Script_StopAllQuips(void) {
    nGameSound_StopAllQuips(0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7100 */
