#ifndef MATERIALPROPERTIES_TYPES_H
#define MATERIALPROPERTIES_TYPES_H

/* Material property record. */
typedef struct MaterialProps {
    char pad00[0x124];
} MaterialProps;                    /* size 0x124 */

typedef struct MaterialVec {
    int unk0;
    int count;                      /* 0x04 */
    MaterialProps* data;            /* 0x08 */
} MaterialVec;

/* Tree node: payload starts at +0x18. */
typedef struct MatTreeNode {
    char pad00[0x18];
    int value;                      /* 0x18 */
} MatTreeNode;

typedef struct MatIter {
    MatTreeNode* node;
} MatIter;

#endif
