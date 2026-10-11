#ifndef SFO_WEAPON_TYPES_H
#define SFO_WEAPON_TYPES_H

/*
 * Weapons: the WEAPONS.WDB record, the actor weapon inventory (weapon.cc, actor +0x3524),
 * the discharge request, the candidate-scan request and the bullet pool record.
 * Sources: COMBAT.md sections 1-4, COMBAT_ITEMS.md (record additions), bullet_pool.hpp /
 * flashlight.hpp in the port (request fields). Compatible with include/weapon_types.h
 * (WeaponDef, Inventory, InventorySlot) which covers fewer fields.
 */

#include "types.h"

#include "sfo_common_types.h"


/* Hold class (record +0xF0). */
#define SF_HOLD_FIREARM 0
#define SF_HOLD_THROWN 1
#define SF_HOLD_NEVER 2
#define SF_HOLD_KNIFE 3
#define SF_HOLD_BATON 4
#define SF_HOLD_AIR_TASER 5
#define SF_HOLD_STAR 7
#define SF_HOLD_FLAME 8
#define SF_HOLD_ROCKET 9
#define SF_HOLD_TORCH 10
#define SF_HOLD_NOTHING 11
#define SF_SLOT_NONE 6   /* inventory +0x84 when nothing is held */

/* Weapon record (WEAPONS.WDB, WeaponDb_Get(*004FFD30, id); record 0 for out-of-range ids). */
typedef struct SfWeaponRecord {
    char pad0000[0x10];
    char fireSound[16]; /* +0x10 ? inline string; also detonation sound (class 8) */
    char reloadSound[16]; /* +0x20 ? inline string; bounce sound for projectiles */
    unsigned char weaponClass; /* +0x30 slot via table 00489D60 */
    char pad0031[0x3];
    int rangeNear; /* +0x34 */
    int rangeMid; /* +0x38 */
    int rangeFar; /* +0x3C also the hitscan length */
    int accuracyNear; /* +0x40 percent */
    int accuracyMid; /* +0x44 */
    unsigned char itemKind; /* +0x48 6 = no weapon (WeaponDef.equipMode) */
    char pad0049[0x3];
    int accuracyFar; /* +0x4C */
    float aimTimeNear; /* +0x50 */
    float aimTimeFar; /* +0x54 */
    char pad0058[0x4];
    int burstLength; /* +0x5C >= 2 arms the burst */
    char pad0060[0x4];
    int damageMid; /* +0x64 also knife stab / blast damage */
    int damageNear; /* +0x68 */
    int damageFar; /* +0x6C */
    int clipSize; /* +0x70 */
    int clipsGiven; /* +0x74 */
    unsigned char fullAuto; /* +0x78 */
    char pad0079[0x7];
    char displayName[32]; /* +0x80 ? inline */
    int tracerInterval; /* +0xA0 */
    float rateOfFire; /* +0xA4 cooldown = 1/rate */
    char pad00A8[0x10];
    float noiseRadius; /* +0xB8 AI hearing, cause 4 */
    unsigned char damageType; /* +0xBC SF_DMG_* */
    char pad00BD[0x3];
    float fuseTime; /* +0xC0 copied to projectile +0xE0 */
    float blastInner; /* +0xC4 */
    float blastOuter; /* +0xC8 also the area radius */
    char pad00CC[0x4];
    float areaDuration; /* +0xD0 */
    unsigned char launchMode; /* +0xD4 2 detonate on impact; 1/2 for hold 0 = launched projectile */
    char pad00D5[0x3];
    int impactEffect; /* +0xD8 -1 none */
    unsigned char areaParticles; /* +0xDC */
    char pad00DD[0x13];
    unsigned char holdClass; /* +0xF0 SF_HOLD_* */
    char pad00F1[0x7];
    int stabPenetration; /* +0xF8 */
    float detonationNoise; /* +0xFC AI noise radius at detonation */
    char pad0100[0x4];
    int power; /* +0x104 projectile max speed */
    char pad0108[0x4];
    int ammoType; /* +0x10C */
    char pad0110[0x8];
    unsigned char loopingFire; /* +0x118 first pull arms a 0.5 s spin-up */
    char pad0119[0x3];
    void* hudIcon; /* +0x11C class 7 icon */
    char pad0120[0x19];
    unsigned char keepLoaded; /* +0x139 */
    unsigned char shakeStrength; /* +0x13A */
    char pad013B[0x1];
    void* model; /* +0x13C attached weapon model / HUD icon */
} SfWeaponRecord; /* size unknown (>= 0x140); prefix only */

/* Inventory slot. */
typedef struct SfWeaponSlot {
    unsigned char holsterOk; /* +0x0 constructor: 00489D70[k] < 8 */
    char pad0001[0x3];
    int itemId; /* +0x4 -1 empty */
    int clip; /* +0x8 */
    int spare; /* +0xC */
} SfWeaponSlot; /* size 0x10 */

/* Actor weapon inventory (weapon.cc, actor +0x3524, WeaponInv_Construct). */
typedef struct SfWeaponInventory {
    void* heldObject; /* +0x0 optional object (class-5 items) */
    SfWeaponSlot slots[8]; /* +0x4 slot 6 = current, 7 = flashlight item */
    unsigned char current; /* +0x84 SF_SLOT_NONE when nothing held */
    unsigned char previous; /* +0x85 */
    char pad0086[0x2];
    void* actor; /* +0x88 */
    char pad008C[0x4];
    SfWeakHandle burstTarget; /* +0x90 */
    unsigned char aimView; /* +0x98 */
    unsigned char infiniteReserve; /* +0x99 set by AI init */
    char pad009A[0x2];
    int subtarget; /* +0x9C */
    unsigned char reloading; /* +0xA0 */
    char pad00A1[0x3];
    int equipMarker; /* +0xA4 -1 after equip/holster */
    unsigned char dontDropWeapons; /* +0xA8 */
    unsigned char activeHand; /* +0xA9 dual */
    char pad00AA[0x2];
    float cooldown[2]; /* +0xAC per hand */
    float unkB4[2]; /* +0xB4 cleared per shot; constructor 10000.0 */
    int burstLeft[2]; /* +0xBC */
    int loopSoundActive[2]; /* +0xC4 ? width */
    float spinUp[2]; /* +0xCC */
    char pad00D4[0x14];
    float unkE8; /* +0xE8 180.0 */
    char pad00EC[0x3];
    unsigned char busy; /* +0xEF blocks switching */
    char pad00F0[0x8];
} SfWeaponInventory; /* size 0xF8 */

/* Discharge request built by Weapon_Discharge (size inferred from the last field). */
typedef struct SfShotRequest {
    SfMtx44 frame; /* +0x0 row 1 forward, row 3 origin */
    float damage; /* +0x40 float(record +0x104), then band damage */
    void* shooter; /* +0x44 */
    void* target; /* +0x48 designated target */
    char pad004C[0x84];
    int subtarget; /* +0xD0 -1 none, 0 head */
    unsigned char hitRoll; /* +0xD4 Weapon_HitRoll(controller) */
    unsigned char aimView; /* +0xD5 */
    unsigned char tracer; /* +0xD6 */
    char pad00D7[0x1];
    float range; /* +0xD8 float(record +0x3C) */
    SfWeaponRecord* record; /* +0xDC */
    int unkE0; /* +0xE0 -1 */
    float unkE4; /* +0xE4 1.0 */
} SfShotRequest; /* size 0xE8 */

/* Candidate scan request for Projectile_QueryCandidates (0022BA30). */
typedef struct SfScanRequest {
    void* owner; /* +0x0 */
    SfMtx44* frame; /* +0x4 */
    int unk08; /* +0x8 */
    unsigned char unk0C; /* +0xC */
    unsigned char aimView; /* +0xD */
    char pad000E[0x2];
    int subtarget; /* +0x10 -1 */
    float range; /* +0x14 */
    char pad0018[0x4];
    int unk1C; /* +0x1C */
    unsigned char skipDamage; /* +0x20 */
    char pad0021[0x3];
    unsigned char unk24; /* +0x24 0: stop at the first hit */
    char pad0025[0x3];
    float hitRadius; /* +0x28 FlashHitRad for the flashlight probe */
    char pad002C[0x4];
    int result30; /* +0x30 filled by the hit entry */
    int result34; /* +0x34 */
} SfScanRequest; /* size unknown (>= 0x38); prefix only */

/* Bullet pool record (stride 0x150; BulletPool_Request indexes by 336). */
typedef struct SfBullet {
    char pad0000[0xC];
    int subtarget; /* +0xC -1 */
    int penetration; /* +0x10 */
    char pad0014[0xC];
    SfMtx44 frame; /* +0x20 row 3 (+0x50) is the position */
    void* target; /* +0x60 */
    int targetId; /* +0x64 */
    void* shooter; /* +0x68 */
    int shooterId; /* +0x6C */
    void* staticObject; /* +0x70 */
    int staticObjectId; /* +0x74 */
    char pad0078[0x4];
    void* links; /* +0x7C ? other pellets of the shot (+0x7C/+0x80) */
    char pad0080[0x10];
    SfVec4 staticHit[7]; /* +0x90 ? static LOS result copied +0x90..+0x100 */
    SfVec4 endPoint; /* +0x100 */
    char pad0110[0x4];
    unsigned char rolled; /* +0x114 */
    unsigned char active; /* +0x115 */
    unsigned char alive; /* +0x116 */
    unsigned char tracer; /* +0x117 */
    unsigned char aimView; /* +0x118 */
    unsigned char statistics; /* +0x119 */
    char pad011A[0x2E];
    int item; /* +0x148 */
    char pad014C[0x4];
} SfBullet; /* size 0x150 */


#endif /* SFO_WEAPON_TYPES_H */
