#ifndef HOTBOX_TYPES_H
#define HOTBOX_TYPES_H

/*
 * Provisional types for src/main/hotbox (cHotbox interaction volumes, cHotboxMsg
 * and the trigger zone built on cHotbox). Field names are placeholders (unkXX)
 * unless the function names or research notes justify them.
 */

#include "types.h"

/* One script-native argument slot; args[0] is the receiver object. */
typedef union HotboxScriptArg {
    int i;
    float f;
    void* p;
} HotboxScriptArg;

typedef struct cHotbox {
    void* vtable;          /* 0x00 */
    char pad04[0x60 - 0x04];
    PtrVec unk60;          /* 0x60: vector filled by func_00171C40 */
    char pad6C[0x90 - 0x6C];
    int type;              /* 0x90: zone type (9 = crouch zone) */
    char pad94[0x98 - 0x94];
    int occupants;         /* 0x98: > 0 while occupied */
    char pad9C[0xA0 - 0x9C];
    int interactMessage;   /* 0xA0 */
} cHotbox;

/* Message sent by a hotbox to script. */
typedef struct cHotboxMsg {
    char pad00[0x24];
    unsigned char action;  /* 0x24 */
    char pad25[0x30 - 0x25];
    void* who;             /* 0x30: game object that triggered the message */
} cHotboxMsg;

/* Receiver-derived object built by func_001716E0 (class table D_004D9960). */
typedef struct HotboxReceiver {
    void* vtable;          /* 0x00 */
    char pad04[0x20 - 0x04];
    int unk20;             /* 0x20 */
    int unk24;             /* 0x24 */
    char unk28[1];         /* 0x28: scalar collection, size unknown */
} HotboxReceiver;

/* Linked-list node: next pointer at +4, payload at +8. */
typedef struct HotboxListNode {
    struct HotboxListNode* prev;  /* 0x00 (assumed) */
    struct HotboxListNode* next;  /* 0x04 */
    int value;                    /* 0x08 */
} HotboxListNode;

typedef struct HotboxListIter {
    HotboxListNode* node;
} HotboxListIter;

#endif
