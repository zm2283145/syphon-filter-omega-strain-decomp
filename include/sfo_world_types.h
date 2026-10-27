#ifndef SFO_WORLD_TYPES_H
#define SFO_WORLD_TYPES_H

/*
 * World systems around combat: explosion events (Blast_Prepare / game::CreateBlast), area
 * effects, thrown projectiles, level lights and the light manager, renderer camera records,
 * hotboxes, HUD target nodes, the mission item table and script handler descriptors.
 * Sources: COMBAT_ITEMS.md, explosion.hpp / area_effect.hpp / thrown_projectile.hpp in the
 * port, LEVEL_LIGHTS.md (2.3, 2.4, 3.2), FLASHLIGHT.md (5), CROUCH_ZONES_AND_RUNNING_JUMP.md
 * (hotbox record), OBJECTIVE_MARKERS.md, ITEM_INVENTORY.md, SCRIPT_HOSTING.md (1.3).
 */

#include "types.h"

#include "sfo_common_types.h"


/* Level light types (light +0x1E). */
#define SF_LIGHT_AMBIENT 0x01
#define SF_LIGHT_DIRECTIONAL 0x02
#define SF_LIGHT_POINT 0x04
#define SF_LIGHT_SPOT 0x10
#define SF_LIGHT_FLASHLIGHT 0x40

/* Delayed blast damage event (virtual +0x10 = cDamageCallback_Call 0021B890). Vtable position and size unverified. */
typedef struct SfExplosionEvent {
    float delay; /* +0x0 ? due when <= 0 (scheduled by 0021A820(event, delay, 1, 0)) */
    unsigned char countDown; /* +0x4 ? 1 = count down on the game clock */
    char pad0005[0xF];
    int damage; /* +0x14 */
    SfWeakHandle source; /* +0x18 */
    signed char type; /* +0x20 0, 2 or 13 */
    char pad0021[0xF];
    SfVec4 point; /* +0x30 */
} SfExplosionEvent; /* size 0x40 */

/* Lingering area effect (cAreaEffect_ctor 0025A2D0, update 00259880). */
typedef struct SfAreaEffect {
    SfGameObject base; /* +0x0 */
    float age; /* +0x60 */
    char pad0064[0xC];
    SfVec4 position; /* +0x70 */
    int record; /* +0x80 weapon record id */
    SfWeakHandle owner; /* +0x84 */
    char pad008C[0x4];
    SfVec4 extents[4]; /* +0x90 types 5/6/7 only */
    char pad00D0[0x4];
    unsigned char done; /* +0xD4 */
    unsigned char flagD5; /* +0xD5 */
    unsigned char particles; /* +0xD6 record +0xDC */
} SfAreaEffect; /* size unknown (>= 0xD7); prefix only */

/* Thrown/launched projectile (cGrenade_ctor 0025D730, cGrenade_NextFrame 0025AD80). */
typedef struct SfThrownProjectile {
    SfGameObject base; /* +0x0 +0xC id, +0x50 transform node */
    float mass; /* +0x60 */
    float inverseMass; /* +0x64 */
    char pad0068[0x8];
    SfVec4 position; /* +0x70 */
    SfVec4 previous; /* +0x80 */
    SfVec4 velocity; /* +0x90 */
    SfVec4 acceleration; /* +0xA0 */
    SfVec4 force; /* +0xB0 */
    char pad00C0[0x20];
    float fuse; /* +0xE0 */
    unsigned char retired; /* +0xE4 */
    unsigned char atRest; /* +0xE5 */
    unsigned char firstStep; /* +0xE6 */
    char pad00E7[0x1];
    unsigned char stuck; /* +0xE8 */
    char pad00E9[0x7];
    SfVec4 launch; /* +0xF0 launch velocity */
    float prevDt; /* +0x100 */
    float age; /* +0x104 */
    char pad0108[0x8];
    SfVec4 spin; /* +0x110 rad/s */
    int record; /* +0x120 weapon record (item id) */
    SfWeakHandle owner; /* +0x124 */
} SfThrownProjectile; /* size unknown (>= 0x12C); prefix only */

/* Level light record (LEVEL_LIGHTS.md 2.3). Point pool stride is 0x40; size 0x58 is for spot/directional. */
typedef struct SfLevelLight {
    unsigned char kindTag; /* +0x0 */
    char pad0001[0x3];
    void* vtable; /* +0x4 point 004D9200, base 004D9240, released 004D9280, flashlight glare 004E15E0 */
    int id; /* +0x8 -1 free */
    float intensity; /* +0xC */
    float inner; /* +0x10 */
    float outer; /* +0x14 also the range */
    float sortWeight; /* +0x18 1/|colour.xyz|^2 */
    unsigned char enabled; /* +0x1C */
    unsigned char aux; /* +0x1D */
    unsigned char type; /* +0x1E SF_LIGHT_* */
    char pad001F[0x1];
    SfVec4 colour; /* +0x20 */
    SfVec4 position; /* +0x30 */
    SfVec4 direction; /* +0x40 point-pool entries use a 0x40 stride and stop before this */
    float coneOuter; /* +0x50 */
    float coneInner; /* +0x54 1.0 disables the cone */
} SfLevelLight; /* size 0x58 */

/* Per-frame light table entry (cLightMan_TestVisibleLight). */
typedef struct SfLightTableEntry {
    unsigned char type; /* +0x0 */
    unsigned char aux; /* +0x1 */
    unsigned char lightClass; /* +0x2 */
    char pad0003[0x1];
    SfLevelLight* light; /* +0x4 */
    float range; /* +0x8 */
    float weight; /* +0xC */
    SfVec4 position; /* +0x10 */
} SfLightTableEntry; /* size 0x20 */

/* Light manager singleton at 00535D20. */
typedef struct SfLightManager {
    SfLevelLight* pools[4]; /* +0x0 ambient, directional, point, spot */
    int poolSize[4]; /* +0x10 point pool 24 */
    SfVec4 reference; /* +0x20 model-light reference point */
    SfVec4 corner; /* +0x30 */
    unsigned char gatherMode; /* +0x40 */
    unsigned char referenceChanged; /* +0x41 */
    unsigned char dirty; /* +0x42 00535D62 */
    unsigned char dynamicColour; /* +0x43 */
    unsigned char lastMask; /* +0x44 */
    char pad0045[0x7];
    int tableCount; /* +0x4C */
    int candidateCount; /* +0x50 */
    void* scratch; /* +0x54 0x70000000 */
    char pad0058[0x8];
    SfLightTableEntry table[1]; /* +0x60 variable length, no capacity check */
} SfLightManager; /* size unknown (>= 0x80); prefix only */

/* Renderer camera record (renderer +0x1F0 + 0x110 * k; constructor 003755C0). */
typedef struct SfCameraRecord {
    char pad0000[0x8];
    float orthoWidth; /* +0x8 */
    float orthoHeight; /* +0xC */
    SfMtx44 ortho; /* +0x10 */
    SfMtx44 perspective; /* +0x50 */
    char pad0090[0x40];
    SfVec4 nearTerms; /* +0xD0 (0, 0, -n, 1/n) */
    SfVec4 farTerms; /* +0xE0 (0, 0, f, 1/f) */
    float orthoNear; /* +0xF0 */
    float perspNear; /* +0xF4 */
    float orthoFar; /* +0xF8 */
    float perspFar; /* +0xFC */
    float halfAngle; /* +0x100 */
    unsigned char orthographic; /* +0x104 */
    unsigned char viewport; /* +0x105 */
    unsigned char dirty; /* +0x106 */
    char pad0107[0x9];
} SfCameraRecord; /* size 0x110 */

/* cHotbox (record version 70, cHotbox_ctor_cPopulationR_int 00172AE0). Extends include/hotbox_types.h cHotbox. */
typedef struct SfHotbox {
    SfGameObject base; /* +0x0 +0xC id, +0x2C enabled, +0x2D activated, +0x2E removed, +0x49 = 8 */
    SfPtrVec links; /* +0x60 resolved link targets */
    char pad006C[0x4];
    SfVec4 boundsMin; /* +0x70 +FLT_MAX at load */
    SfVec4 boundsMax; /* +0x80 -FLT_MAX at load */
    int type; /* +0x90 9 crouch zone, 12 solo no-op, 1/6/7 send cDisable/cEnable to links */
    char pad0094[0x4];
    int occupants; /* +0x98 clamped 0..3 */
    int unk9C; /* +0x9C 10 */
    int interactMessage; /* +0xA0 */
} SfHotbox; /* size unknown (>= 0xA4); prefix only */

/* HUD target list node (*004FFC2C + 0xA8). */
typedef struct SfHudTargetNode {
    struct SfHudTargetNode* prev; /* +0x0 */
    struct SfHudTargetNode* next; /* +0x4 */
    void* object; /* +0x8 */
    int id; /* +0xC */
} SfHudTargetNode; /* size 0x10 */

/* Objective marker binding stored by 00273570 (OBJECTIVE_MARKERS.md). */
typedef struct SfObjectiveMarker {
    int objectId; /* +0x0 packed identifier, by value */
    void* resourceA; /* +0x4 */
    void* resourceB; /* +0x8 */
    unsigned char unk0C; /* +0xC */
    char pad000D[0x3];
    int kind; /* +0x10 2 */
    char pad0014[0x8];
    char* text; /* +0x1C owned localized text */
    char pad0020[0x8];
    char* third; /* +0x28 owned; empty when null */
} SfObjectiveMarker; /* size unknown (>= 0x2C); prefix only */

/* Mission item table entry (table 0x587FF0, RegisterItem). */
typedef struct SfItemTableEntry {
    int nameId; /* +0x0 layered intern id, -1 missing */
    int descriptionId; /* +0x4 */
    char resource[32]; /* +0x8 */
    void* resourceObject; /* +0x28 */
} SfItemTableEntry; /* size unknown (>= 0x2C); prefix only */

/* Script event handler descriptor as read by cScriptInterpreter_callEvent_cSystemP_cMessageP_charP_int_etc 003E0510. */
typedef struct SfScriptHandler {
    char pad0000[0x24];
    void* activationContext; /* +0x24 byte +0x64 must be nonzero */
    int literalId; /* +0x28 match when receiver id equals it (>= 0) */
    void* variableSelector; /* +0x2C */
    void* groupSelector; /* +0x30 */
    char pad0034[0x4];
    int linkCount; /* +0x38 must be nonzero */
    char pad003C[0x4];
    unsigned char pass; /* +0x40 must equal the current pass */
} SfScriptHandler; /* size unknown (>= 0x41); prefix only */


#endif /* SFO_WORLD_TYPES_H */
