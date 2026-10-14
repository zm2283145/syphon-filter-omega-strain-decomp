/*
 * main/tank: range (3 files, 00282F30-00282FF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "tank_types.h"

/* merge_units: begin func_00282F30 */
#pragma push /* merge_units */
#pragma peephole off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char pad[0x18]; float min; float max; } Turret;
typedef struct { char pad[0x6C]; Turret* turret; } Tank;
/* Sets the turret rotation limits from degrees. */
static inline void Tank_SetRotLimit(Tank* tank, float lo, float hi)
{
    Turret* t = tank->turret;
    if (t) { t->min = 0.017453292f * lo; t->max = 0.017453292f * hi; }
}
/* Script native: sets tank args[0]'s turret rotation limits from degrees args[1], args[2]; returns 0. */
int Script_cTank_SetPitchLimit(ScriptArg* args)
{
    int minv[1];
    int maxv[1];
    maxv[0] = args[2].i;
    minv[0] = args[1].i;
    Tank_SetRotLimit((Tank*)args[0].p, *(float*)minv, *(float*)maxv);
    return 0;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282F30 */

/* merge_units: begin func_00282F90 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x20]; float min; float max; } Turret_00282F90;
typedef struct { char pad[0x6C]; Turret_00282F90* turret; } Tank_00282F90;
/* Sets the turret rotation limits from degrees. */
static inline void Tank_SetRotLimit_00282F90(Tank_00282F90* tank, float lo, float hi)
{
    Turret_00282F90* t = tank->turret;
    if (t) { t->min = 0.017453292f * lo; t->max = 0.017453292f * hi; }
}
/* Script native: sets tank args[0]'s turret rotation limits from degrees args[1], args[2]; returns 0. */
int Script_cTank_SetRotLimit(ScriptArg* args)
{
    int minv[1];
    int maxv[1];
    maxv[0] = args[2].i;
    minv[0] = args[1].i;
    Tank_SetRotLimit_00282F90((Tank_00282F90*)args[0].p, *(float*)minv, *(float*)maxv);
    return 0;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282F90 */

/* merge_units: begin func_00282FF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int func_00285590(cTank* tank, void* target);

int Script_cTank_ClearEnemy(TankScriptArg* args) {
    func_00285590((cTank*)args[0].p, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282FF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282FF0 */
