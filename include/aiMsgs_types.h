#ifndef AIMSGS_TYPES_H
#define AIMSGS_TYPES_H

/*
 * AI script message types (cAI*Msg). All derive from the 0x24-byte base script
 * message; field names come from the script native accessor names.
 */

/* Base script message (0x24 bytes); see ai_types.h. */
typedef struct cAIMsgBase {
    void* vtable;              /* 0x00 */
    char pad04[0x20];
} cAIMsgBase;

/* cAIGOBJMsg and derivatives: subject object at 0x24. */
typedef struct cAIGOBJMsg {
    cAIMsgBase base;
    int who;                   /* 0x24: identity word (Who / GetGOBJ / Attacker) */
} cAIGOBJMsg;

/* cAINodeMsg (destination/waypoint reached): node at 0x24. */
typedef struct cAINodeMsg {
    cAIMsgBase base;
    int node;                  /* 0x24 */
} cAINodeMsg;

/* cAIBodyMovedMsg */
typedef struct cAIBodyMovedMsg {
    cAIGOBJMsg gobj;
    unsigned char pickedUp;    /* 0x28 */
} cAIBodyMovedMsg;

/* cAIWeaponFiredMsg */
typedef struct cAIWeaponFiredMsg {
    cAIGOBJMsg gobj;
    int weaponId;              /* 0x28 */
    int count;                 /* 0x2C */
    unsigned char isThrown;    /* 0x30 */
} cAIWeaponFiredMsg;

/* cAINewAwarenessMsg */
typedef struct cAINewAwarenessMsg {
    cAIGOBJMsg gobj;
    unsigned char cause;       /* 0x28 */
} cAINewAwarenessMsg;

/* cAIDeadMsg */
typedef struct cAIDeadMsg {
    cAIGOBJMsg gobj;           /* 0x24: attacker */
    unsigned char damageType;  /* 0x28 */
} cAIDeadMsg;

#endif
