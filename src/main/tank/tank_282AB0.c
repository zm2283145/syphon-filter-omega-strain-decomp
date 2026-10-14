/*
 * main/tank: range (2 files, 00282AB0-00282AE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "tank_types.h"

/* merge_units: begin func_00282AB0 */
#pragma push /* merge_units */
typedef struct TankBody {
    char pad[0x40];
    float hitpoints;
} TankBody;

typedef struct Tank {
    char pad[0x60];
    TankBody* body;
} Tank;

typedef struct TankArgs {
    Tank* obj;
} TankArgs;

/* Script native: cTank.GetHitpoints - returns the body's hitpoints truncated to int. */
int Script_cTank_GetHitpoints(TankArgs* args) {
    volatile int hp = args->obj->body->hitpoints;
    return hp;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282AB0 */

/* merge_units: begin func_00282AE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int GObj_IdentityA(void*);

int Script_cTank_GetGobj(TankScriptArg* args) {
    return GObj_IdentityA(((cTank*)args[0].p)->gobj);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282AE0 */
