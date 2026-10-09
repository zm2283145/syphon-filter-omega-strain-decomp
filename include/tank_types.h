#ifndef TANK_TYPES_H
#define TANK_TYPES_H

/*
 * Provisional types for src/main/tank (cTank script class and its turret).
 * Field names are placeholders (unkXX) unless the function names justify them.
 */

#include "types.h"

/* One script-native argument slot; args[0] is the receiver object. */
typedef union TankScriptArg {
    int i;
    float f;
    void* p;
} TankScriptArg;

/* Turret object reached through cTank +0x6C. */
typedef struct cTankTurret {
    char pad00[0x2C];
    float accel;          /* 0x2C: written by SetTurretAccel */
    char pad30[0x64 - 0x30];
    int unk64;            /* 0x64: cleared by func_00286560 */
    void* weaponDef;      /* 0x68: weapon definition looked up from weaponId */
    int weaponId;         /* 0x6C */
} cTankTurret;

typedef struct cTank {
    char pad00[0x60];
    void* gobj;           /* 0x60: owning game object */
    char pad64[0x6C - 0x64];
    cTankTurret* turret;  /* 0x6C: may be null */
} cTank;

/* Small record built by func_00287C10 (purpose unknown). */
typedef struct TankLink {
    int unk00;            /* 0x00 */
    char* source;         /* 0x04: object whose float at +0x144 is copied */
    char pad08[0x24 - 0x08];
    float unk24;          /* 0x24 */
    unsigned char unk28;  /* 0x28 */
} TankLink;

/* Weapon definition table (global at D_004FFD30) lookup by weapon id. */
extern void* WeaponDb_Get(void* table, int id);

#endif
