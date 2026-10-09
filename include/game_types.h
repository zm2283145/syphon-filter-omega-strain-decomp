#ifndef GAME_TYPES_H
#define GAME_TYPES_H

/*
 * Provisional types for src/main/game. Field names are placeholders (unkXX)
 * unless the research notes or function names justify a real name.
 */

#include "types.h"

/* Four floats without the 16-byte alignment of Vec4 (copied with lwc1/swc1). */
typedef struct Float4 {
    float x, y, z, w;
} Float4;

/* 3x4 matrix stored as three rows of four floats (0x30 bytes). */
typedef struct Mtx34 {
    Float4 row[3];
} Mtx34;

/* Iterator into a linked list (one node pointer). */
typedef struct ListIter {
    void* node;
} ListIter;

/* Linked-list container: +0 unknown, +4 header (sentinel) node, +8 first node. */
typedef struct LinkList {
    int unk0;
    int header;
    void* first;
} LinkList;

/*
 * Object reached through the global at D_004FFC2C (world +0xDC); receives the
 * global timer requests (func_00245560).
 */
typedef struct GameTimerService {
    char pad0[0x6DC];
    int unk6DC;   /* cleared on level/stats reset */
    int unk6E0;   /* set to -1.0f (bit pattern) on level/stats reset */
} GameTimerService;

/* Record with four 16-byte name slots at +0xF0 and an int array at +0x130. */
typedef struct NameSlotTable {
    char pad0[0xF0];
    char names[4][16];
    int values[1];   /* +0x130, length unknown */
} NameSlotTable;

/* Message object (cMessage): vtable followed by a 0x1C-byte payload and a flag. */
typedef struct cMessage {
    void* vtable;     /* +0x00 */
    int args[7];      /* +0x04..+0x1C */
    signed char flag; /* +0x20 */
} cMessage;

#endif
