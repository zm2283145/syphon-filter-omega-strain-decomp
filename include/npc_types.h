#ifndef NPC_TYPES_H
#define NPC_TYPES_H

/*
 * Types used by the cNPC script/AI glue (npc.cc) and NPCInfoObject.cc.
 * Offsets are from the matched code; names come from the script command that
 * reaches each field (Script_cNPC_* -> cNPC vtable slot -> field).
 * Fields named unkXX are not understood yet.
 */

#include "types.h"

/* Actor that owns a cNPC component (cNPC+0x30). Only the fields used here. */
typedef struct NpcActor {
    char pad0000[0x44];
    int darkness;                   /* 0x0044 */
    char pad0048[0x3370];
    char fireInvulnerable;          /* 0x33B8 */
    char pad33B9[0x16B];
    struct NpcWeaponSet* weapons;   /* 0x3524 */
    int items;                      /* 0x3528 inventory handle for Global_Player*Item* */
} NpcActor;

/* Weapon set of an actor (NpcActor+0x3524). */
typedef struct NpcWeaponSet {
    char pad00[0xA8];
    char dontDropWeapons;           /* 0xA8 */
} NpcWeaponSet;

/* AI controller of a cNPC (cNPC+0x1AC). */
typedef struct NpcAi {
    char pad00[0x10];
    float viewConeRadius;           /* 0x10 */
    float viewConeHalfAngle;        /* 0x14 radians */
    char pad18[0x4];
    int targetOverride;             /* 0x1C cleared by ResumeAITargeting */
} NpcAi;

/* 20-byte record in cNPC+0x17C, first byte read by cNPC_v28. */
typedef struct NpcRec14 {
    unsigned char unk00;
    char pad01[0x13];
} NpcRec14;

/* cNPC: AI component attached to an actor. Size unknown (> 0x1B0). */
typedef struct cNPC {
    void* vtable;                   /* 0x000 */
    char pad004[0x1C];
    float aimPercent;               /* 0x020 */
    char pad024[0xC];
    NpcActor* actor;                /* 0x030 */
    char forceOnRadar;              /* 0x034 */
    char pad035[0xF];
    char unk044[0x1C];              /* 0x044 sub-object passed to func_0016E170 */
    float unk060;                   /* 0x060 */
    int travelSpeedOverride;        /* 0x064 0 = AI decides */
    char pad068[0x4];
    float aggressiveness;           /* 0x06C */
    char pad070[0x8];
    float firingThreshold;          /* 0x078 */
    float unk07C;                   /* 0x07C set by StopMovement */
    char pad080[0x14];
    float grenadeThrowAngle;        /* 0x094 */
    char pad098[0x20];
    float weaponPreferenceDistance; /* 0x0B8 */
    char pad0BC[0x38];
    int moveTargetGobj;             /* 0x0F4 */
    char pad0F8[0x20];
    int unk118;                     /* 0x118 */
    int aimSubtarget;               /* 0x11C -1 = none */
    int aimOverride;                /* 0x120 cleared by ResumeAIAiming */
    char pad124[0x14];
    int moveTargetNode;             /* 0x138 */
    signed char unk13C;             /* 0x13C */
    char aiAiming;                  /* 0x13D set by ResumeAIAiming */
    char unk13E;                    /* 0x13E */
    char pad13F[0x29];
    char unk168;                    /* 0x168 cleared by StopMovement */
    char pad169[0x13];
    NpcRec14 unk17C[2];             /* 0x17C */
    char pad1A4[0x8];
    NpcAi* ai;                      /* 0x1AC */
} cNPC;

/* Argument block passed to Script_cNPC_* commands: object, then parameters. */
typedef struct NpcScriptArgs {
    cNPC* npc;
    int arg1;
} NpcScriptArgs;

/* Reinterprets a script argument word as a float. */
typedef union NpcScriptWord {
    int i;
    float f;
} NpcScriptWord;

/* Script message carrying an AI mode (cAIModeChangeMsg). */
typedef struct NpcAiMsg {
    char pad00[0x24];
    unsigned char aiMode;           /* 0x24 */
} NpcAiMsg;

#endif
