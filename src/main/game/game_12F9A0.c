/*
 * main/game: range (2 files, 0012F9A0-0012F9D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_0012F9A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char g_Game[]; /* world object */
extern int Global_RequestLevelEnd(void);
extern int Game_EndLevel(char* world, int);

int Script_RequestLevelEnd(void) {
    Global_RequestLevelEnd();
    return 0;
}

int Global_RequestLevelEnd(void) {
    return Game_EndLevel(g_Game, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F9A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F9A0 */

/* merge_units: begin func_0012F9D0 */
#pragma push /* merge_units */
extern void Global_SetScrollDelay(float delay);

/* Script native: SetScrollDelay(delay = args[0]).
 * volatile mirrors the original stack temporary. */
int Script_SetScrollDelay(ScriptArg* args) {
    volatile int bits = args[0].i;
    Global_SetScrollDelay(*(float*)&bits);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012F9D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012F9D0 */
