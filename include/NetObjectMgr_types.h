#ifndef NETOBJECTMGR_TYPES_H
#define NETOBJECTMGR_TYPES_H

#include "GobjMan_types.h"

typedef struct NetObjectUpdate {
    char pad00[8];
    GobjId id;                     /* 0x08 */
    short value;                   /* 0x0C */
} NetObjectUpdate;

typedef struct NetSessionEntry {
    char pad00[0x1C];
    int value;                     /* 0x1C */
} NetSessionEntry;

/* Red-black tree container header (map/set): 0x10 bytes.
 * The header node lives at +4; its first word is the root pointer. */
typedef struct RbTree {
    int count;          /* 0x00 number of elements */
    void* root;         /* 0x04 root node (header node starts here) */
    int unk08;          /* 0x08 */
    void* leftmost;     /* 0x0C first node, or &root when empty */
} RbTree;

#endif
