#ifndef SCRIPTUTILS_TYPES_H
#define SCRIPTUTILS_TYPES_H

/*
 * Types used by the generic script natives (scriptUtils): timers, callouts,
 * arrays and cNodeList.
 * Offsets come from the matched code. Fields named unkXX are not understood yet.
 */

#include "types.h"

/* One script-native argument word (int, float bits or pointer). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* Object group (PtrVec-like; count at +4). */
typedef struct ScriptGroup {
    int unk0;
    int count;                      /* 0x04 */
    int* data;                      /* 0x08 */
} ScriptGroup;

/* Script-side cNodeList: the native group lives at +0x60. */
typedef struct cNodeList {
    char pad00[0x60];
    ScriptGroup* group;             /* 0x60 */
} cNodeList;

/* Script array object: element count at +8. */
typedef struct ScriptArray {
    char pad00[0x8];
    int count;                      /* 0x08 */
} ScriptArray;

/* Object whose callout record lives behind +0x30 (see Global_ClearCallout_2). */
typedef struct CalloutOwner {
    char pad00[0x30];
    char* callout;                  /* 0x30 passed to the callout clear as callout+0x0C */
} CalloutOwner;

/* Linked list node (next at +4, value at +8). */
typedef struct ListNode {
    struct ListNode* unk00;         /* 0x00 */
    struct ListNode* next;          /* 0x04 */
    int value;                      /* 0x08 */
} ListNode;

/* List iterator used by the push_back wrappers. */
typedef struct ListPos {
    void* node;
} ListPos;

#endif
