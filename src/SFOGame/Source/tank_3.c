/*
 * SFOGame/Source/tank: 6 files, 00282C90-00282DC0
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

/* merge_units: begin func_00282DC0 */
#pragma push /* merge_units */
#include "vslot_pad.h"

typedef struct { char pad[0x68]; int weapon; int weaponId; } Ang2DC0;
typedef struct { char pad[0x6C]; Ang2DC0* angles; } Tank2DC0;
typedef union { int i; Tank2DC0* p; } Arg2DC0;
extern int g_WeaponDatabase;
#if 0 /* merge_units */
extern int cWeaponDB_GetEntry(int db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((int)cWeaponDB_GetEntry((void *)(a0), (a1))) /* merge_units */

int Script_cTank_SetWeapon(Arg2DC0* args) {
    volatile int id = args[1].i;
    Ang2DC0* a = args[0].p->angles;
    int i = id;
    if (a) {
        int db = g_WeaponDatabase;
        a->weaponId = i;
        a->weapon = cWeaponDB_GetEntry(db, i);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282DC0(void) {}
#undef cWeaponDB_GetEntry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282DC0 */

/* merge_units: begin func_00282E10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Gun282E10 { VPAD32(a) VPAD16(b) VPAD16(c) VPAD2(d) VPAD1(e) virtual void Fire(); virtual void Arm(int on); };
struct Sub282E10 { Gun282E10* gun; };
struct Tank282E10 { char p[0x60]; Gun282E10* turret; char p64[8]; Sub282E10* sub; };
struct Msg282E10 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; float f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void cNIEventBase_SetSpeed(Gun282E10*, float);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

}
static inline int IsAuth282E10(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
union Arg282E10 { int i; float f; void* p; };
extern "C" int Script_cTank_Move(Arg282E10* args) {
    float v;
Gun282E10* t;
Tank282E10* self;
int tmp;
    tmp = args[1].i;
    v = *(float*)&tmp;
    self = (Tank282E10*)args[0].p;
    t = self->turret;
    cNIEventBase_SetSpeed(t, v);
    t->Fire();
    if (self->sub) self->sub->gun->Arm(1);
    if (g_IsMultiplayer && IsAuth282E10()) {
        Msg282E10 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = 0;
        m.b24 = 1;
        m.f2C = v;
        m.b20 = 4;
        m.f1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282E10(void) {}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282E10 */
