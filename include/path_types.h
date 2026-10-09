#ifndef PATH_TYPES_H
#define PATH_TYPES_H

/*
 * Types for path.cc. Layouts are provisional and inferred only from the
 * accessors and constructors in this file.
 */

/* Doubly linked list header as built by ScalarCollection_Init (12 bytes). */
typedef struct PathListLink {
    struct PathListLink* next;
    struct PathListLink* prev;
} PathListLink;

typedef struct PathList {
    int count;                  /* 0x00 */
    PathListLink head;          /* 0x04: sentinel, end() */
} PathList;

/* List node: links followed by the stored value. */
typedef struct PathListNode {
    PathListLink link;          /* 0x00 */
    int value;                  /* 0x08 */
} PathListNode;

/* Vector of 8-byte elements (same header layout as PtrVec). */
typedef struct PathPair {
    int a, b;
} PathPair;

typedef struct PathPairVec {
    int unk0;
    int count;                  /* 0x04 */
    PathPair* data;             /* 0x08 */
} PathPairVec;

/* 2D point with a byte tag (constructed by 0x0015E0F0). */
typedef struct PathPoint {
    float x;                    /* 0x00 */
    float y;                    /* 0x04 */
    signed char tag;            /* 0x08 */
} PathPoint;

/* Object initialized by 0x00161930. */
typedef struct PathCursor {
    char pad00[0x10];
    int unk10;                  /* 0x10: -1 when unset */
    int unk14;                  /* 0x14: -1 when unset */
    char pad18[0x08];
    int unk20;                  /* 0x20 */
    int owner;                  /* 0x24 */
    int unk28;                  /* 0x28 */
} PathCursor;

/* Object with two scalars written together by 0x0015FDC0. */
typedef struct PathScalarPair {
    char pad00[0x08];
    float unk08;                /* 0x08 */
    char pad0C[0x1C];
    float unk28;                /* 0x28 */
} PathScalarPair;

/* Polymorphic object holding two linked sub-objects (0x00163970). */
typedef struct PathLinkedSub {
    void* vtable;               /* 0x00 */
    void* unk04;                /* 0x04 */
    void* unk08;                /* 0x08 */
} PathLinkedSub;

typedef struct PathLinkedPair {
    void* vtable;               /* 0x00 */
    PathLinkedSub first;        /* 0x04 */
    PathLinkedSub second;       /* 0x10 */
    int unk1C;                  /* 0x1C */
} PathLinkedPair;               /* size 0x20 */

/* Receiver that owns two value lists (constructor 0x00164620). */
typedef struct PathReceiver {
    void* vtable;               /* 0x00 */
    char pad04[0x1C];
    PathList listA;             /* 0x20 */
    PathList listB;             /* 0x2C */
} PathReceiver;

#endif
