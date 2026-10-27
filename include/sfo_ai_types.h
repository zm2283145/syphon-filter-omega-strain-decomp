#ifndef SFO_AI_TYPES_H
#define SFO_AI_TYPES_H

/*
 * NPC AI: the AI component (cNPC; actor +0x58 for NPCs, vtable 004D9380), its mode block,
 * perception object and awareness records, the path follower, route buffer and path node.
 * Sources: NPC_SPAWN_AND_AI.md (component, vtable, path follower, node), NPC_COMBAT.md
 * (sections 2, 5, 6), COMBAT.md (perception). Extends include/npc_types.h cNPC / NpcAi.
 * Note: npc_types.h treats +0x44..+0x5F as one 0x1C-byte block; the notes put the team at
 * +0x54 and the script timer at +0x58, so the mode block here is 0x10 bytes (verify).
 */

#include "types.h"

#include "sfo_common_types.h"


/* AI modes (mode table 0049B6A0, cNPC_Update). */
#define SF_AIMODE_PATROL 0
#define SF_AIMODE_ALERT 1
#define SF_AIMODE_ATTACK 4
#define SF_AIMODE_SCRIPT 7
#define SF_AIMODE_EVADE_GRENADE 10
/* Path node type bits (node +0x64). */
#define SF_NODE_GENERIC 0x1
#define SF_NODE_STAND_COVER 0x2
#define SF_NODE_CROUCH_COVER 0x4
#define SF_NODE_PATH 0x8
#define SF_NODE_GOAL 0x10
#define SF_NODE_SPAWN 0x20
#define SF_NODE_ACTION 0x40
#define SF_NODE_NAV 0x80
#define SF_NODE_CROSS 0x100
/* AI component vtable slots (vtable 004D9380). */
#define SF_AIVT_DISPATCH 0x0C        /* 00151D30 */
#define SF_AIVT_ALWAYS 0x3C          /* 0015A440 radius activation */
#define SF_AIVT_UPDATE 0x40          /* 00159590 */
#define SF_AIVT_ACTIVATE 0x48        /* 00157DF0 */
#define SF_AIVT_DEACTIVATE 0x4C      /* 00157AD0 */
#define SF_AIVT_AIM_UPDATE 0x60      /* 0022F5B0 cGameGobjController_UpdateToHitProbability */
#define SF_AIVT_WEAPON_DRAW 0xBC     /* 0014FC20 */
#define SF_AIVT_SET_MODE 0xDC        /* 0014BCF0 */
#define SF_AIVT_MOVE_TO_NODE 0x100   /* 0014BE50 */
#define SF_AIVT_KILL 0x168           /* 0014B370 */

/* Mode request block at component +0x44 (setter cStateMachine_ChangeState 0016E170). */
typedef struct SfAiModeBlock {
    int mode; /* +0x0 */
    int requested; /* +0x4 */
    int priority; /* +0x8 request accepted when priority >= this */
    int pending; /* +0xC ? width */
} SfAiModeBlock; /* size 0x10 */

/* AI component (cNPC). Constructed by 001588D0 -> cAI_ctor 0016F5B0 -> cNPC_Init 00158BC0. */
typedef struct SfAiComponent {
    void* vtable; /* +0x0 004D9380 */
    char pad0004[0x10];
    unsigned char owned; /* +0x14 */
    char pad0015[0xB];
    float aimPercent; /* +0x20 */
    char pad0024[0xC];
    void* actor; /* +0x30 SfActor */
    unsigned char forceOnRadar; /* +0x34 */
    char pad0035[0x3];
    float skill; /* +0x38 SetSkill; constructor 1.0 */
    char pad003C[0x8];
    SfAiModeBlock modeBlock; /* +0x44 */
    int team; /* +0x54 4 for NPCs */
    float scriptTimer; /* +0x58 crossing 0 sends TimeElapsed; -1 none */
    char pad005C[0x4];
    float travelSpeed; /* +0x60 Walk 0.1 */
    int travelSpeedPriority; /* +0x64 script 100, path link 20, resume 0 */
    char pad0068[0x4];
    float aggressiveness; /* +0x6C 0.25 + 0.5 * rand */
    float searchDistMin; /* +0x70 -100.0 */
    float searchDistMax; /* +0x74 100.0 */
    float firingThreshold; /* +0x78 -1: use WorthShootingThreshold */
    float stopMovementTimer; /* +0x7C */
    float lookReactionThreshold; /* +0x80 100.0 */
    float burstPause; /* +0x84 */
    float shotCooldown; /* +0x88 */
    float shotInterval; /* +0x8C */
    float throwScatter; /* +0x90 4.0 */
    float throwAngle; /* +0x94 35 degrees */
    float activationRadiusSq; /* +0x98 */
    char pad009C[0x4];
    int movementStatePriority; /* +0xA0 */
    int burstLength; /* +0xA4 */
    int shotsLeft; /* +0xA8 */
    char pad00AC[0x4];
    int primaryItem; /* +0xB0 */
    int secondaryItem; /* +0xB4 */
    float weaponSwitchDistance; /* +0xB8 */
    unsigned int allowedRegions[9]; /* +0xBC bitmask, all ones at construction */
    int firingNode; /* +0xE0 -1 */
    int coverNode; /* +0xE4 -1 */
    int eventCountdown; /* +0xE8 updates until AI event 3 */
    int modeCounter; /* +0xEC */
    int carryNode; /* +0xF0 */
    int carryObjectId; /* +0xF4 go-to body / follow / grenade target */
    char pad00F8[0x8];
    int follow[4]; /* +0x100 ? follow parameters */
    short pendingTag; /* +0x110 ? pending pair */
    short pendingMode; /* +0x112 ? mode requested on path event 2 */
    int pathLinkAction; /* +0x114 */
    int weaponStatePriority; /* +0x118 */
    int aimSubtarget; /* +0x11C -1 */
    int drawPriority; /* +0x120 */
    char pad0124[0x8];
    int forceFireItem; /* +0x12C */
    int forceFireShots; /* +0x130 */
    float forceFireInterval; /* +0x134 */
    int pendingMoveNode; /* +0x138 MoveToNode, -1 */
    unsigned char movementState; /* +0x13C 0 stopped, 1 moving, 2 turn to path */
    unsigned char drawRequest; /* +0x13D 0 holster, 1 raise when engaged, 2 always */
    unsigned char weaponState; /* +0x13E 1 fire allowed */
    unsigned char routePurpose; /* +0x13F 2 cover, 3 firing position, 4 approach, 10 cached cover */
    unsigned char routePurposeActive; /* +0x140 */
    unsigned char flags141; /* +0x141 bit 0 route to searched node, bit 7 radius activation */
    char pad0142[0x16];
    unsigned char floorContact; /* +0x158 */
    unsigned char inactive; /* +0x159 */
    char pad015A[0x6];
    unsigned char lookRequests[0x32]; /* +0x160 +0x160..+0x191 (NPC_COMBAT.md 5.9) */
    char pad0192[0x16];
    unsigned char headLookSent; /* +0x1A8 */
    char pad01A9[0x3];
    struct SfAiPerception* perception; /* +0x1AC */
    struct SfPathFollower* pathFollower; /* +0x1B0 */
    void* occupiedHotbox; /* +0x1B4 */
    void* lookSlot; /* +0x1B8 004EA1D0 + 0x18 * k */
    float thinkTimer; /* +0x1BC */
    float stuckProgress; /* +0x1C0 */
    float stuckTimer; /* +0x1C4 > 2.0 s: relocation */
    SfWeakHandle throwTarget; /* +0x1C8 */
    char pad01D0[0x4];
    unsigned char deactivateLatch; /* +0x1D4 */
    unsigned char activateLatch; /* +0x1D5 */
} SfAiComponent; /* size unknown (>= 0x1D6); prefix only */

/* Perception object at component +0x1AC (cAITarget_ctor 0016E0A0). */
typedef struct SfAiPerception {
    SfVec4 lastKnown; /* +0x0 */
    float viewRadius; /* +0x10 SetViewConeRadius; reset to the far distance 0053834C */
    float viewHalfAngle; /* +0x14 pi/4; SetViewConeAngle stores deg/2 in radians */
    int targetRegion; /* +0x18 */
    int targetPriority; /* +0x1C auto 20, SetTarget 100, ResumeAITargeting 0 */
    unsigned char flags; /* +0x20 bit0 head view, 1 body view, 2 line clear, 3 ever seen, 4 last known valid */
    unsigned char flags2; /* +0x21 bit 0 also non-enemy players */
    char pad0022[0xE];
    SfPtrVec records; /* +0x30 ? list of SfAwarenessRecord (ai.cc nodes, new at front) */
    void* component; /* +0x3C */
    SfWeakHandle target; /* +0x40 */
    SfWeakHandle nextCandidate; /* +0x48 round robin of cAITarget_GetNextNpcToTest */
    int resetFrame; /* +0x50 frame counter + 20 */
} SfAiPerception; /* size unknown (>= 0x54); prefix only */

/* Awareness record (cAITarget_AddAwareness creates, cAITarget_UpdateAwareness ages). */
typedef struct SfAwarenessRecord {
    void* object; /* +0x0 */
    int id; /* +0x4 */
    int id2; /* +0x8 */
    char pad000C[0x4];
    SfVec4 lastSeen; /* +0x10 */
    int cause; /* +0x20 eCauseForAwareness; 9 = all players */
    float age; /* +0x24 < 0: pending delay */
    float sinceEvent7; /* +0x28 */
    float visibility; /* +0x2C */
    float threat; /* +0x30 */
    float salience; /* +0x34 cause 4 0.2, 8 1.0, 7 5.0; x0.9 per think */
    unsigned char inView; /* +0x38 */
    unsigned char lineClear; /* +0x39 */
    unsigned char everSeen; /* +0x3A */
    unsigned char deadBodyNoticeSent; /* +0x3B */
    unsigned char newAwarenessSent; /* +0x3C */
    char pad003D[0x3];
} SfAwarenessRecord; /* size 0x40 */

/* Route buffer at path follower +0x74 (cPathNavigator_Activate / cPathNavigator_Deactivate). */
typedef struct SfRouteBuffer {
    SfVec4 destPoint; /* +0x0 */
    int destNode; /* +0x10 */
    char pad0014[0xC];
    int* nodes; /* +0x20 */
    char pad0024[0x4];
    int count; /* +0x28 */
    char pad002C[0x4];
} SfRouteBuffer; /* size 0x30 */

/* Path follower at component +0x1B0 (cPathNavigator_ctor 00161840). */
typedef struct SfPathFollower {
    SfVec4 target; /* +0x0 */
    SfVec4 direction; /* +0x10 unit segment direction */
    SfVec4 saved; /* +0x20 */
    char pad0030[0x10];
    float remaining; /* +0x40 */
    float segmentLength; /* +0x44 */
    int routeIndex; /* +0x48 counts down */
    int holdNode; /* +0x4C released beyond 2.0 units */
    int targetNode; /* +0x50 */
    int prevNode; /* +0x54 */
    char pad0058[0x4];
    int region; /* +0x5C from node +0x7C; mode 1 decides only while >= 0 */
    unsigned int flags; /* +0x60 bit0 patrolling, 1 path node, 2 off support, 3 ended, 4/5 arrival */
    char pad0064[0xC];
    void* actor; /* +0x70 */
    SfRouteBuffer* route; /* +0x74 */
    char pad0078[0x8];
} SfPathFollower; /* size 0x80 */

/* Path node (0015C390). Size inferred from the last field. */
typedef struct SfPathNode {
    char pad0000[0xC];
    int id; /* +0xC */
    char pad0010[0x50];
    int association; /* +0x60 */
    unsigned int typeBits; /* +0x64 SF_NODE_* */
    SfPtrVec links; /* +0x68 8-byte entries {target index, link type} */
    char pad0074[0x4];
    int index; /* +0x78 */
    int region; /* +0x7C GRP: group index, -1 none */
    SfVec4 position; /* +0x80 w lane = yaw */
} SfPathNode; /* size 0x90 */


#endif /* SFO_AI_TYPES_H */
