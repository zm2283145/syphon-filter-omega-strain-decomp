#ifndef GAMEFRONTEND_TYPES_H
#define GAMEFRONTEND_TYPES_H

/*
 * Front-end (menu) types. Offsets come from the matched code.
 */

#include "types.h"

/* Linked list node (next at +4, value at +8). */
typedef struct FeListNode {
    struct FeListNode* unk00;       /* 0x00 */
    struct FeListNode* next;        /* 0x04 */
    int value;                      /* 0x08 */
} FeListNode;

/* List iterator. */
typedef struct FeListPos {
    FeListNode* node;
} FeListPos;

typedef struct FeWidget {
    char pad00[0x14];
    unsigned short flags;           /* 0x14 bit 3 tested by func_002CAB70 */
} FeWidget;

typedef struct FeScreen {
    char pad00[0x258];
    FeWidget* widget;               /* 0x258 */
} FeScreen;

typedef struct FeItem {
    char pad00[0x30];
    char unk30;                     /* 0x30 */
} FeItem;

#endif
