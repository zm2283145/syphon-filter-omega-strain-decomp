#ifndef SFO_ACTOR_TYPES_H
#define SFO_ACTOR_TYPES_H

/*
 * Human actor (player Gabe and NPCs share the same class; the controller at +0x58
 * decides). Sources: ACTOR_DAMAGE_AND_HEALTH.md (actor fields), COMBAT.md, COMBAT_ITEMS.md
 * (item fields), FLASHLIGHT.md (2.2), NPC_ACTIVATION_AND_RESPAWN.md (checkpoint object),
 * HANGING.md / CROUCH_ZONES_AND_RUNNING_JUMP.md (action words). Prefix layout only: the
 * actor is about 0x35A0 bytes and most of 0x60..0x31C0 (model, physical, animation) is
 * not described here. Consistent with include/human_types.h Actor and npc_types.h NpcActor.
 */

#include "types.h"

#include "sfo_common_types.h"


/* Life states (SF_VT_LIFE_STATE). */
#define SF_LIFE_ALIVE 0
#define SF_LIFE_DYING 2
#define SF_LIFE_DEAD  3
/* Damage types (weapon record +0xBC, WpnDamageType). */
#define SF_DMG_BULLET 1
#define SF_DMG_EXPLOSION 2
#define SF_DMG_FLASH 3
#define SF_DMG_FIRE 4
#define SF_DMG_KNOCKOUT 7

/* Flashlight object at actor +0x33EC (cFlashlight_ctor, created for roles 1 and 3). */
typedef struct SfFlashlight {
    unsigned char on; /* +0x0 */
    char pad0001[0x3];
    void* owner; /* +0x4 SfActor */
    void* beam; /* +0x8 level light, point pool entry, type 4 */
    void* glare; /* +0xC level light, point pool entry, type 0x40 */
    float beamLength; /* +0x10 smoothed; <= 0 means unset (-1 at construction) */
    float beamSpeed; /* +0x14 */
    SfGameObject* spot; /* +0x18 lit-spot world object (0x60 bytes) */
} SfFlashlight; /* size 0x1C */

/* Checkpoint object embedded at actor +0x33F0 (actor +0x3440 = transform, +0x3450 = health). */
typedef struct SfCheckpoint {
    char pad0000[0x50];
    void* transform; /* +0x50 transform component (matrix at +0x10) */
    char pad0054[0xC];
    int health; /* +0x60 trunc(health) when set (constructor 100) */
    int unk64; /* +0x64 constructor 100 */
    int armor; /* +0x68 armor when set */
    float labelTimer; /* +0x6C 5.0 on set */
    char* label; /* +0x70 */
} SfCheckpoint; /* size 0x74 */

/* Human actor (player and NPC). */
typedef struct SfActor {
    SfGameObject base; /* +0x0 +0x40 health, +0x44 stealth, +0x58 controller */
    char pad0060[0x2D90];
    unsigned char muzzleFlash[2]; /* +0x2DF0 per hand */
    char pad2DF2[0xCE];
    void* modelContext; /* +0x2EC0 ? motion/name lookups go through it */
    char pad2EC4[0x1E0];
    float fallStartZ; /* +0x30A4 ? not written by the constructor */
    float fallDistance; /* +0x30A8 ? body-fall sound when <= 12.0 */
    char pad30AC[0x148];
    float killCountdown; /* +0x31F4 below 0 kills the actor; -1 never */
    char pad31F8[0x8];
    unsigned int inputFlagsPrev; /* +0x3200 previous +0x3204 */
    unsigned int inputFlags; /* +0x3204 bit 0 movement, bit 7 player-only */
    char pad3208[0x4];
    int topAction; /* +0x320C current top action */
    unsigned int actionBits; /* +0x3210 active actions (bit n = action n; 23 takedown, 24 throw); busy bits 4,5,7,8,20 */
    char pad3214[0x4];
    unsigned int actionChanges; /* +0x3218 */
    char pad321C[0x2C];
    unsigned int stateFlags; /* +0x3248 bit 1 crouch request, bit 3 checked by the climb gate */
    unsigned int flags324C; /* +0x324C bit 8 secondary needs release, bit 9 throw armed */
    char pad3250[0x10];
    unsigned char female; /* +0x3260 1 selects the _F voice tables */
    char pad3261[0x8];
    unsigned char respawned; /* +0x3269 */
    unsigned char burning; /* +0x326A */
    unsigned char viewMode; /* +0x326B ? cleared by the death action for the player */
    char pad326C[0x24];
    void* floorRoot; /* +0x3290 'flor' */
    void* edgeRoot; /* +0x3294 'edge' */
    void* ladderRoot; /* +0x3298 'ladd' */
    char pad329C[0x78];
    void* secondary; /* +0x3314 secondary (upper-body) component; states at +0x310/+0x311 */
    char pad3318[0x80];
    int maxHealth; /* +0x3398 */
    int maxArmor; /* +0x339C StartingArmor 250 for the player */
    int armor; /* +0x33A0 */
    unsigned char invulnerable; /* +0x33A4 */
    unsigned char killed; /* +0x33A5 forces life state 3 */
    char pad33A6[0x2];
    float blindTime; /* +0x33A8 decays by dt; blocks ToHit, targeting and NPC sight */
    float flashTime; /* +0x33AC decays by dt; NPC ignores AI sounds while > 0 */
    int fireDamage; /* +0x33B0 accumulated type-4 damage */
    char pad33B4[0x4];
    unsigned char fireImmune; /* +0x33B8 */
    char pad33B9[0x3];
    float stunElapsed; /* +0x33BC -1 idle */
    float stunDuration; /* +0x33C0 */
    char pad33C4[0x4];
    unsigned char stunLethal; /* +0x33C8 ? width unverified */
    char pad33C9[0x3];
    int pendingTarget; /* +0x33CC weak handle id (melee) or script name word (throws) */
    SfVec4 throwAimPoint; /* +0x33D0 w = 0: actor-local */
    float throwArc; /* +0x33E0 radians */
    unsigned char throwState; /* +0x33E4 1 throwing, 2 launched, 0 released */
    unsigned char gogglesState; /* +0x33E5 */
    unsigned char gogglesArg; /* +0x33E6 */
    unsigned char gogglesUnk; /* +0x33E7 */
    unsigned char meleeState; /* +0x33E8 1 attacking, 2 hit done, 0 idle */
    char pad33E9[0x3];
    SfFlashlight* flashlight; /* +0x33EC roles 1 and 3 only */
    SfCheckpoint checkpoint; /* +0x33F0 */
    void* backpack; /* +0x3464 world inventory object (cBackpack_NewBackpack_cHumanP_bool_cObjectIdP) */
    unsigned char pickupable; /* +0x3468 corpse stays a perceivable body (SetPickupable) */
    char pad3469[0x1];
    unsigned char stunImmune; /* +0x346A */
    unsigned char notGasable; /* +0x346B */
    unsigned char netFlag; /* +0x346C cNetSetFlagMsg; 0 in single player */
    char pad346D[0x1];
    unsigned char crosshairState; /* +0x346E */
    unsigned char irState; /* +0x346F */
    unsigned char nightVision; /* +0x3470 blindness x BlindNVFactor */
    char pad3471[0xF];
    SfWeakHandle fireSource; /* +0x3480 who set the actor on fire */
    char pad3488[0x8];
    int jumpMode; /* +0x3490 ? running jump: 1 launch, 2 action 0x16 */
    char pad3494[0xC];
    SfVec4 jumpQuat; /* +0x34A0 ? */
    SfVec4 jumpStart; /* +0x34B0 ? */
    SfVec4 jumpTarget; /* +0x34C0 */
    char pad34D0[0x14];
    int deathMotionOverride[12]; /* +0x34E4 per death code 0..11, -1 none */
    char pad3514[0x10];
    struct SfWeaponInventory* weapons; /* +0x3524 */
    void* items; /* +0x3528 mission item list (ItemInv_*) */
    float shake; /* +0x352C screen-shake amount */
    char pad3530[0x18];
    int startNode; /* +0x3548 ? hold node handed to cPathNavigator_ctor */
    SfWeakHandle effectSlots[3]; /* +0x354C ? effect objects (count inferred) */
    char pad3564[0x20];
    void* playerRecord; /* +0x3584 per-player record (shot counter) */
    char pad3588[0xC];
    int respawnStamp; /* +0x3594 network timestamp of the respawn message (replica path only) */
    unsigned char unk3598; /* +0x3598 */
} SfActor; /* size unknown (>= 0x3599); prefix only */


#endif /* SFO_ACTOR_TYPES_H */
