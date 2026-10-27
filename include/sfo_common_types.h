#ifndef SFO_COMMON_TYPES_H
#define SFO_COMMON_TYPES_H

/*
 * Shared base layouts for game objects, weak handles and messages, synced from the
 * PC-port research notes (research/*.md in the port checkout). Layout only: offsets
 * in comments are byte offsets; names follow the note that established the role.
 * '?' in a comment marks a field whose type or meaning is inferred, not verified.
 * All types carry an Sf prefix so they never collide with include/*_types.h.
 */

#include "types.h"


typedef struct SfVec4 { float x, y, z, w; } SfVec4;          /* VU0 quad; usually 16-byte aligned in place */
typedef struct SfMtx44 { SfVec4 row[4]; } SfMtx44;            /* rows 0..2 axes (row 1 forward), row 3 origin */
typedef struct SfWeakHandle { void* object; int id; } SfWeakHandle; /* valid while object->id (+0xC) == id */
typedef struct SfPtrVec { int unk0; int count; void* data; } SfPtrVec; /* vector header: +4 count, +8 data */

/* Root-object virtual slots (byte offsets into the vtable). */
#define SF_VT_DELETE        0x08  /* (obj, flags) */
#define SF_VT_ACTIVATE      0x5C  /* sets +0x2D, then controller +0x48 */
#define SF_VT_DEACTIVATE    0x60  /* (obj, 1) */
#define SF_VT_BOUNDS        0x88
#define SF_VT_SET_TRANSFORM 0x90  /* (obj, matrix, flags) */
#define SF_VT_POSITION      0xE4  /* returns SfVec4 world position */
#define SF_VT_MATRIX        0xE8  /* row 3 = position */
#define SF_VT_BODY_CENTRE   0xF0  /* actor: body centre, stored at +0x3E0 of the physical */
#define SF_VT_WORLD_MATRIX  0xF4
#define SF_VT_DAMAGE        0x100 /* (obj, source, category, type, ?, 0, point*, float amount) */
#define SF_VT_BULLET_HIT    0x104 /* returns the hit category */
#define SF_VT_LIFE_STATE    0x108 /* 2 dying, 3 dead */
#define SF_VT_KILL          0x10C /* (obj, int amount, source, category, type, point*) */
#define SF_VT_MODEL_READY   0x110

/* Controller (actor +0x58) virtual slots. */
#define SF_CVT_IS_PLAYER    0x54
#define SF_CVT_IS_AI        0x58
#define SF_CVT_TEAM         0x68
#define SF_CVT_IS_ENEMY_TEAM 0x6C
#define SF_CVT_IS_ENEMY     0x70
#define SF_CVT_SHOOTER_MOTION 0x74
#define SF_CVT_DEATH_NOTICE 0x7C
#define SF_CVT_FIRE_NOTICE  0xCC

/* Root world object ('base world object', 0x60 bytes; e.g. the flashlight lit spot). */
typedef struct SfGameObject {
    void* vtable; /* +0x0 */
    char pad0004[0x8];
    int id; /* +0xC weak-handle generation / object id (category << 16 | index for actors) */
    char pad0010[0x4];
    unsigned char owned; /* +0x14 owned by this machine (1 in single player) */
    char pad0015[0x17];
    unsigned char enabled; /* +0x2C active/visible flags: present = enabled && activated && !removed */
    unsigned char activated; /* +0x2D */
    unsigned char removed; /* +0x2E */
    char pad002F[0x11];
    float health; /* +0x40 actors and damageable objects */
    int stealth; /* +0x44 actor: darkness 0..100 written each frame by UpdateDarkness */
    char pad0048[0x1];
    unsigned char classByte; /* +0x49 ? hotbox 8 */
    char pad004A[0x2];
    void* classWord; /* +0x4C class key (actor *0049D010, hotbox 004EE6B8) */
    void* transform; /* +0x50 transform component (matrix at +0x10, dirty byte +0x50) */
    char pad0054[0x4];
    void* controller; /* +0x58 player or AI component (SfAiComponent for NPCs) */
    char pad005C[0x4];
} SfGameObject; /* size 0x60 */

/* Message/event base (0x24 bytes); payload starts at +0x24. Same as include/human_types.h Message. */
typedef struct SfMessage {
    void* vtable; /* +0x0 */
    char pad0004[0x18];
    int flags; /* +0x1C ? 0x40 for hotbox/link messages */
    unsigned char event; /* +0x20 event byte (hotbox: 1 for types 5/0x12, else 2; timed events 4) */
    char pad0021[0x3];
} SfMessage; /* size 0x24 */

/* Generic payload message (AI notifications, melee start, route results). */
typedef struct SfObjMsg {
    SfMessage base; /* +0x0 */
    void* object; /* +0x24 AIGOBJMsg Who / AINodeMsg node / melee target */
    int arg28; /* +0x28 AIDeadMsg: byte damage type; melee: takedown; route result: node */
    int arg2C; /* +0x2C route result: second node; hotbox: 0 */
} SfObjMsg; /* size 0x30 */

/* cHotboxMsg sent by cHotboxMan_Update. */
typedef struct SfHotboxMsg {
    SfMessage base; /* +0x0 */
    int action; /* +0x24 0 enter, 2 exit (cHotboxMsg) */
    int code; /* +0x28 box type */
    int unk2C; /* +0x2C 0 */
    void* who; /* +0x30 actor that triggered it */
} SfHotboxMsg; /* size 0x34 */


#endif /* SFO_COMMON_TYPES_H */
