/*
 * SFOGame/Source/tank: 4 files, 00282C90-00282D90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00282C90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetCreateTankMsg_dtor, cNetCreateTankMsg_vtable, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_00282C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282C90 */

/* merge_units: begin func_00282D00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "tank_types.h"

extern int cGOBJ_SetHitpoints(void* gobj, int hitpoints, int unk);

int Script_cTank_SetHitpoints(TankScriptArg* args) {
    volatile int hitpoints = args[1].i; /* mirrors the original stack temporary */
    cGOBJ_SetHitpoints(((cTank*)args[0].p)->gobj, hitpoints, 0);
    return 0;
}
static inline void merge_flush_func_00282D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282D00 */

/* merge_units: begin func_00282D40 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; float cone; } Ang2D40;
typedef struct { char pad[0x6C]; Ang2D40* angles; } Tank2D40;
typedef union { int i; Tank2D40* p; } Arg2D40;
int Script_cTank_SetFiringCone(Arg2D40* args) {
    float deg[1];
    Ang2D40* a;
    float d;
    *(int*)deg = args[1].i;
    a = args[0].p->angles;
    d = deg[0];
    if (a) {
        a->cone = 0.017453292f * d;
    }
    return 0;
}
static inline void merge_flush_func_00282D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282D40 */

/* merge_units: begin func_00282D90 */
#pragma push /* merge_units */
int Script_cTank_SetTurretAccel(TankScriptArg* args) {
    volatile int bits = args[1].i; /* mirrors the original stack temporary */
    cTankTurret* turret = ((cTank*)args[0].p)->turret;
    float accel = *(float*)&bits;

    if (turret != 0) {
        turret->accel = accel;
    }
    return 0;
}
static inline void merge_flush_func_00282D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282D90 */
