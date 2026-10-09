#ifndef HUDTARGETS_TYPES_H
#define HUDTARGETS_TYPES_H

/*
 * Types used by hudTargets.cc (objective map markers). Layouts follow the
 * matched code and the objective-marker research notes.
 */

#include "types.h"

/* Doubly linked list node (next at +4, payload at +8). */
typedef struct ListNode {
    struct ListNode* prev;          /* 0x00 */
    struct ListNode* next;          /* 0x04 */
    int value;                      /* 0x08 */
} ListNode;

/* List iterator (one node pointer). */
typedef struct ListPos {
    ListNode* node;
} ListPos;

/* 12-byte collection header (initialized by ScalarCollection_Init). */
typedef struct MarkerList {
    int unk00;
    int unk04;                      /* 0x04 end sentinel */
    int unk08;
} MarkerList;

/* One objective marker record (0x34 bytes). */
typedef struct ObjMarkerRecord {
    int id;                         /* 0x00 packed object identifier */
    void* icon0;                    /* 0x04 UI resource */
    void* icon1;                    /* 0x08 UI resource */
    unsigned char unk0C;            /* 0x0C */
    char pad0D[0x3];
    int kind;                       /* 0x10 1 or 2 for map markers */
    int unk14;                      /* 0x14 */
    int unk18;                      /* 0x18 initialized to -2 */
    char* text;                     /* 0x1C owned localized text */
    int unk20;                      /* 0x20 */
    int unk24;                      /* 0x24 */
    char* text2;                    /* 0x28 owned third string */
    int unk2C;                      /* 0x2C */
    int unk30;                      /* 0x30 */
} ObjMarkerRecord;

/* Objective marker manager (lives at UI +0x90). */
typedef struct ObjMarkerMgr {
    MarkerList unk00;               /* 0x00 observers */
    MarkerList records;             /* 0x0C main record list (admission order) */
    char unk18[0xC];                /* 0x18 initialized by func_00222B60 */
    MarkerList secondary;           /* 0x24 secondary record list */
    float unk30;                    /* 0x30 defaults to 1.0 */
    int unk34;                      /* 0x34 */
    int unk38;                      /* 0x38 defaults to -2 */
    ObjMarkerRecord* selected;      /* 0x3C */
} ObjMarkerMgr;

#endif
