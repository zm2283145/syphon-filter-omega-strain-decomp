#ifndef GOBJMAN_TYPES_H
#define GOBJMAN_TYPES_H

/*
 * Script object ID word: bits 0..15 index, bits 16..23 category,
 * bits 24..30 (kind + 1), bit 31 "return registered object directly".
 */
typedef struct GobjId {
    unsigned int word;
} GobjId;

/* Scope in the object visibility chain; first word links to the parent. */
typedef struct GobjScope {
    struct GobjScope* parent;   /* 0x00 */
} GobjScope;

/* Registered object as seen by the lookup (size unknown). */
typedef struct GobjEntry {
    char pad00[0x1C];
    GobjScope* scope;           /* 0x1C */
} GobjEntry;

/* Container whose payload starts at +0x08 (size unknown). */
typedef struct GobjHolder {
    int unk00;
    int unk04;
    char data[1];               /* 0x08 */
} GobjHolder;

#endif
