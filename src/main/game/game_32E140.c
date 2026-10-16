/*
 * main/game: 2 files, 0032E140-0032E150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0032E140(void) {
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E140 */

/* merge_units: begin func_0032E150 */
#pragma push /* merge_units */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void Objective_AddGlobal(int);

/* Script native: adds an objective by id. */
int Game_AddObjective(ScriptArg* args) {
    volatile int id = args[0].i;
    Objective_AddGlobal(id);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E150 */
