/*
 * main/tank: range (5 files, 00285310-002853E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "tank_types.h"

/* merge_units: begin func_00285310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern void* g_WeaponDatabase; /* weapon definition table */
extern int cGOBJ_SetHitpoints(void* gobj, int hitpoints, int unk);

/* Sets the hitpoints of the tank's game object. */
int cTank_SetHitpoints(cTank* tank, int hitpoints) {
    return cGOBJ_SetHitpoints(tank->gobj, hitpoints, 0);
}

/* Selects the turret weapon (no-op without a turret). */
void cTank_SetWeapon(cTank* tank, int weaponId) {
    cTankTurret* turret = tank->turret;

    if (turret != 0) {
        void* table = g_WeaponDatabase;

        turret->weaponId = weaponId;
        turret->weaponDef = cWeaponDB_GetEntry(table, weaponId);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285310 */

/* merge_units: begin func_00285360 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; float angle; } Ang5360;
typedef struct { char pad[0x6C]; Ang5360* angles; } AngOwner5360;
void cTank_SetFiringCone(AngOwner5360* self, float deg) {
    Ang5360* a = self->angles;
    if (a) {
        a->angle = 0.017453292f * deg;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285360 */

/* merge_units: begin func_00285390 */
#pragma push /* merge_units */
/* Sets the turret acceleration (no-op without a turret). */
void cTank_SetTurretAccel(cTank* tank, float accel) {
    cTankTurret* turret = tank->turret;

    if (turret != 0) {
        turret->accel = accel;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285390(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285390 */

/* merge_units: begin func_002853B0 */
#pragma push /* merge_units */
typedef struct Angles {
    char pad[0x18];
    float pitch;
    float yaw;
} Angles;

typedef struct AngleOwner {
    char pad[0x6C];
    Angles* angles;
} AngleOwner;

/* Stores two angles given in degrees as radians into the attached angle block. */
void cTank_SetPitchLimit(AngleOwner* self, float pitchDeg, float yawDeg) {
    Angles* angles = self->angles;
    if (angles) {
        angles->pitch = 0.017453292f * pitchDeg;
        angles->yaw = 0.017453292f * yawDeg;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002853B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002853B0 */

/* merge_units: begin func_002853E0 */
#pragma push /* merge_units */
typedef struct Target20 {
    char pad[0x20];
    float x;
    float y;
} Target20;

typedef struct Obj6C {
    char pad[0x6C];
    Target20* target;
} Obj6C;

/* Stores (x, y) scaled by 0.0174533 (degrees to radians) into the target. */
void cTank_SetRotLimit(Obj6C* o, float x, float y) {
    Target20* t = o->target;
    if (t != 0) {
        float k = 0.017453292f;
        t->x = k * x;
        t->y = k * y;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002853E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002853E0 */
