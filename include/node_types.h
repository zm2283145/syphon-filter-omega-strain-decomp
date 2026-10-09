#ifndef NODE_TYPES_H
#define NODE_TYPES_H

/*
 * Types for node.cc: the cNode script class (a placed point with a
 * translation) and its script-native helpers.
 */

/* One script-native argument slot (4 bytes). */
typedef union NodeScriptArg {
    int i;
    float f;
    void* p;
    unsigned short u16;
    unsigned char u8;
} NodeScriptArg;

typedef struct NodeVec3 {
    float x, y, z;
} NodeVec3;

/* Script object header as seen by type tests. */
typedef struct NodeScriptObj {
    char pad00[0x64];
    int typeMask;               /* 0x64: script type bits */
} NodeScriptObj;

/* cNode (partial). */
typedef struct cNode {
    void* vtable;               /* 0x00 */
    char pad04[0x28];
    unsigned char flag2C;       /* 0x2C: set/cleared by 0x0015BF80/0x0015BF90 */
    char pad2D[0x53];
    NodeVec3 translation;       /* 0x80 */
} cNode;

#endif
