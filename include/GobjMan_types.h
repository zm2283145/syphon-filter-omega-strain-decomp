#ifndef GOBJMAN_TYPES_H
#define GOBJMAN_TYPES_H

/*
 * Script object ID word: bits 0..15 index, bits 16..23 category,
 * bits 24..30 (kind + 1), bit 31 "return registered object directly".
 */
typedef struct GobjId {
    unsigned int word;
} GobjId;

/* Pointer vector with an "owns elements" flag (0x10 bytes; same head as PtrVec). */
typedef struct GobjVec {
    int unk00;                  /* 0x00 */
    int count;                  /* 0x04 */
    int* data;                  /* 0x08 */
    unsigned char owned;        /* 0x0C */
    char pad0D[3];
} GobjVec;

/*
 * Object scope / registry (0x24 bytes, built by GobjScopeBase_Ctor, destroyed by
 * GobjScopeBase_Dtor). Lookups walk an object's scope chain through `parent` and
 * accept it only when the chain reaches the requested scope. Every scope is
 * also kept in the global list returned by GobjScope_GetList.
 * IdMgr_Init creates the root scope g_GobjRootScope (4500 slots) and the world
 * scope g_GobjWorldScope (2500 slots, parent = root).
 */
typedef struct GobjScope {
    struct GobjScope* parent;   /* 0x00 */
    GobjVec objects;            /* 0x04 registered objects (owned = 0) */
    GobjVec ids;                /* 0x14 object id words (owned = 1) */
} GobjScope;

/* Liveness tag at GobjEntry +0x04 (the object has not been destroyed). */
#define GOBJ_ALIVE_MAGIC 0xBEBAAFDE

/* Registered object as seen by the lookup (size unknown). */
typedef struct GobjEntry {
    void* vtable;                 /* 0x00 */
    unsigned int magic;           /* 0x04 GOBJ_ALIVE_MAGIC while alive */
    char pad08[0x04];
    GobjId id;                    /* 0x0C */
    char pad10[0x0C];
    GobjScope* scope;           /* 0x1C */
} GobjEntry;

/* Registry map node, with an unsigned ID key and object payload. */
typedef struct GobjMapNode {
    struct GobjMapNode* left;
    struct GobjMapNode* right;
    struct GobjMapNode* parent;
    unsigned int key;
    GobjEntry* object;
} GobjMapNode;

typedef struct GobjMap {
    int unk00;
    GobjMapNode* root;             /* 0x04 also identifies the end sentinel */
} GobjMap;


#endif
