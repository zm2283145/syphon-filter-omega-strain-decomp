#ifndef NETOBJECTMGR_TYPES_H
#define NETOBJECTMGR_TYPES_H

/* Red-black tree container header (map/set): 0x10 bytes.
 * The header node lives at +4; its first word is the root pointer. */
typedef struct RbTree {
    int count;          /* 0x00 number of elements */
    void* root;         /* 0x04 root node (header node starts here) */
    int unk08;          /* 0x08 */
    void* leftmost;     /* 0x0C first node, or &root when empty */
} RbTree;

#endif
