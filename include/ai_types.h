#ifndef AI_TYPES_H
#define AI_TYPES_H

/*
 * AI script object and AI message types. Field names are provisional unless the
 * research notes (actor animation channels / movement adjustment) justify them.
 */

/* One script-native argument slot (4 bytes). */
typedef union AIScriptArg {
    int i;
    float f;
    void* p;
} AIScriptArg;

/* Game object as seen from cAI; only the fields used here. */
typedef struct AIGObj {
    char pad00[0x38];
    int unk38;                 /* 0x38: compared with 0x80 by Script_cAI_IsVisible */
    char pad3C[0x3584 - 0x3C];
    struct AIGObjSub* unk3584; /* 0x3584 */
} AIGObj;

typedef struct AIGObjSub {
    char pad00[0x30];
    short unk30;               /* 0x30: mirrors cAI.unk54 in multiplayer */
} AIGObjSub;

typedef struct cAI {
    char pad00[0x30];
    AIGObj* gobj;              /* 0x30 */
    char pad34[0x20];
    int unk54;                 /* 0x54 */
    float timeElapsed;         /* 0x58: set by SendTimeElapsedMessage */
} cAI;

/* Base script message (vtable D_004DFD80); 0x24 bytes. */
typedef struct cMessage {
    void* vtable;              /* 0x00 */
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    signed char unk20;         /* 0x20 */
    char pad21[3];
} cMessage;

/* Action message (vtables D_004D92A0 -> D_004D92C0 -> D_004D9870). */
typedef struct cActionMsg {
    cMessage base;             /* 0x00 */
    signed char event;         /* 0x24 */
    signed char action;        /* 0x25 */
    char pad26[2];
    float amplitude;           /* 0x28 */
    float unk2C;               /* 0x2C */
    int sender;                /* 0x30: sender identity word */
    int target;                /* 0x34: only in the D_004D9870 subclass */
} cActionMsg;

#endif
