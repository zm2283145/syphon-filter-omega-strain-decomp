#ifndef WEAPON_TYPES_H
#define WEAPON_TYPES_H

/*
 * Provisional types for src/main/weapon (actor inventory, weapon definitions,
 * cOutOfAmmoMsg). Field names are placeholders (unkXX) unless the research
 * notes or function names justify them.
 */

#include "types.h"

/* One script-native argument slot; args[0] is the receiver object. */
typedef union WeaponScriptArg {
    int i;
    float f;
    void* p;
} WeaponScriptArg;

/* Weapon definition, looked up by id in the table at D_004FFD30. */
typedef struct WeaponDef {
    char pad00[0x30];
    unsigned char unk30;     /* 0x30: index into the D_00489D60 byte table */
    char pad31[0x48 - 0x31];
    signed char equipMode;   /* 0x48: 6 means no weapon selected */
    char pad49[0x70 - 0x49];
    int unk70;               /* 0x70: multiplied by the func_001861F0 result */
    int unk74;               /* 0x74: key passed to func_001861F0 */
} WeaponDef;

/* Inventory slot (16 bytes); id -1 marks an empty slot. */
typedef struct InventorySlot {
    int unk0;                /* 0x0 */
    int id;                  /* 0x4: weapon id */
    int unk8;                /* 0x8 */
    int unkC;                /* 0xC: subtracted in func_00142AE0 */
} InventorySlot;

/* Actor inventory (actor +0x3524). */
typedef struct Inventory {
    int unk00;               /* 0x00 */
    InventorySlot slots[8];  /* 0x04 */
    unsigned char selected;  /* 0x84: selected slot; 6 = holstered */
    char pad85[0x88 - 0x85];
    void* unk88;             /* 0x88: passed to func_001861F0 */
} Inventory;

/* cOutOfAmmoMsg payload. */
typedef struct cOutOfAmmoMsg {
    char pad00[0x24];
    int weapon;              /* 0x24 */
} cOutOfAmmoMsg;

/* 24-byte element of the vector handled by func_00147600. */
typedef struct WeaponRec24 {
    char data[24];
} WeaponRec24;

typedef struct WeaponRec24Vec {
    int unk0;
    int count;
    WeaponRec24* data;
} WeaponRec24Vec;

extern void* D_004FFD30;     /* weapon definition table */
extern WeaponDef* WeaponDb_Get(void* table, int id);

#endif
