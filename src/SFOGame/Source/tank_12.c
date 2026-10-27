/*
 * SFOGame/Source/tank: 10 files, 00285310-002856E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00285310 */
#pragma push /* merge_units */
#include "types.h"
#include "tank_types.h"

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

/* merge_units: begin func_00285410 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub285410 { char p[0x54]; unsigned char b54; };
struct Tank285410 { char p[0x6C]; Sub285410* sub; };
struct Msg285410 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth285410(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" void cTank_StopFiring(Tank285410* self) {
    if (self->sub) self->sub->b54 = 1;
    if (g_IsMultiplayer && IsAuth285410()) {
        Msg285410 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.b24 = 4;
m.b20 = 4;
m.f1C = 0x40;
m.f2C = 0;
m.f28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
static inline void merge_flush_func_00285410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00285410 */

/* merge_units: begin func_002854D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub2854D0 { char p[0x54]; unsigned char b54; };
struct Tank2854D0 { char p[0x6C]; Sub2854D0* sub; unsigned char b70; };
struct Msg2854D0 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
}
static inline int IsAuth2854D0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" void cTank_ResumeAiming(Tank2854D0* self) {
    if (self->sub) self->sub->b54 = 0;
    self->b70 = 1;
    if (g_IsMultiplayer && IsAuth2854D0()) {
        Msg2854D0 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f2C = 0;
m.b24 = 2;
m.f28 = 0;
m.b20 = 4;
m.f1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
static inline void merge_flush_func_002854D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002854D0 */

/* merge_units: begin func_00285590 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj285590 { char p[0xC]; int id; };
struct Sub285590 { char p[0x54]; unsigned char b54; char p55[7]; Obj285590* tgt; int tid; };
struct Tank285590 { char p[0x6C]; Sub285590* sub; unsigned char b70; };
struct Msg285590 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; Obj285590* f28; int f2C; };
extern "C" {
}
static inline int IsAuth285590(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void SetT285590(Sub285590* s, Obj285590* t) { int none; s->tgt = t; s->tid = *(t ? &t->id : (none = -1, &none)); }
extern "C" void cTank_AimAt(Tank285590* self, Obj285590* t) {
    if (self->sub) {
        self->sub->b54 = 0;
        SetT285590(self->sub, t);
    }
    self->b70 = 0;
    if (g_IsMultiplayer && IsAuth285590()) {
        Msg285590 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = t;
m.b20 = 4;
m.b24 = 0;
m.f1C = 0x40;
m.f2C = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
static inline void merge_flush_func_00285590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00285590 */

/* merge_units: begin func_00285690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tank_reset.h"

/* cTank: reset controller and aim. */
extern "C" void cTank_Reset(TankResetTank* self) { TankReset_Do(self); }
static inline void merge_flush_func_00285690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00285690 */

/* merge_units: begin func_002856E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x54]; char on; } T;
typedef struct { char pad[0x6C]; T* t; } S;
extern void cTurret_Fire(T*);
/* Clears the child's active flag and notifies it, if a child exists. */
void cTank_Fire_2(S* s) { if (s->t) { s->t->on = 0; cTurret_Fire(s->t); } }
static inline void merge_flush_func_002856E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002856E0 */
