#ifndef GOBJ_TYPES_H
#define GOBJ_TYPES_H

/*
 * Provisional types for src/main/gobj (cGOBJ base), src/main/GameGOBJ
 * (cSoundGOBJ, cInteractGOBJ, cPathedGOBJ, cElevatorGOBJ and their notice
 * messages) and src/main/gameobj (cVUM_GOBJ). Field names are placeholders
 * (unkXX) unless the function names or research notes justify a real name.
 */

#include "types.h"

/* One script-native argument slot (4 bytes). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/*
 * Base world object (cGOBJ). Constructor cGOBJ_ctor (0x003CF0E0) runs the
 * parent constructor func_003CB090 and then initializes +0x2C..+0x5C.
 * Total size unknown (at least 0x60).
 */
typedef struct cGOBJ {
    void* vtable;              /* 0x00 */
    char pad04[0x0C];
    int unk10;                 /* 0x10: copied from the constructor's descriptor */
    char pad14[0x18];
    unsigned char unk2C;       /* 0x2C: 1 after construction */
    unsigned char unk2D;       /* 0x2D */
    unsigned char unk2E;       /* 0x2E */
    unsigned char unk2F;       /* 0x2F */
    int unk30;                 /* 0x30: -1 after construction */
    char pad34[4];
    int unk38;                 /* 0x38: 128 after construction */
    int unk3C;                 /* 0x3C */
    int unk40;                 /* 0x40 */
    int darkness;              /* 0x44: script GetDarkness/SetDarkness */
    unsigned char unk48;       /* 0x48 */
    unsigned char unk49;       /* 0x49: constructor argument */
    char pad4A[2];
    int unk4C;                 /* 0x4C: constructor argument (by pointer) */
    int unk50;                 /* 0x50 */
    int unk54;                 /* 0x54 */
    void* attached;            /* 0x58: attached object, null when unattached */
    int unk5C;                 /* 0x5C */
} cGOBJ;

/*
 * Notice/trigger message delivered to GOBJ scripts (cGOBJTriggerEventMsg,
 * cPathedNotice, cElevatorNotice share this layout).
 */
typedef struct cGOBJNotice {
    char pad00[0x24];
    unsigned char action;      /* 0x24 */
    char pad25[3];
    int data;                  /* 0x28 */
    int box;                   /* 0x2C: object id of the trigger box */
    int who;                   /* 0x30: object id of the triggering object */
} cGOBJNotice;

/* Expanded lift path state (0x30 bytes), aliased from cElevatorGOBJ +0x128. */
typedef struct LiftState {
    int index;                 /* 0x00: current floor / path index */
    char pad04[0x1C];
    int dest;                  /* 0x20: destination floor */
    int unk24;                 /* 0x24 */
    int busy;                  /* 0x28 */
    int unk2C;                 /* 0x2C */
} LiftState;

/* Sound controller embedded in cElevatorGOBJ (0x190 bytes each). */
typedef struct LiftSound {
    char data[0x190];
} LiftSound;

/* Elevator / lift object (derives from cPathedGOBJ). */
typedef struct cElevatorGOBJ {
    char pad000[0x88];
    int passengers;            /* 0x088 */
    char pad08C[0x9C];
    LiftState* state;          /* 0x128 */
    char pad12C[0x24];
    LiftSound dingSound;       /* 0x150 */
    LiftSound loopSound;       /* 0x2E0 */
    LiftSound startSound;      /* 0x470 */
    LiftSound stopSound;       /* 0x600 */
} cElevatorGOBJ;

/* Parameter block passed to ModelCtx_Init (0x30 bytes on the stack). */
typedef struct ModelCtxParams {
    int skel;                  /* 0x00: Skel_Find result */
    int unk04;                 /* 0x04 */
    int unk08;                 /* 0x08 */
    int unk0C;                 /* 0x0C */
    float unk10;               /* 0x10 */
    float unk14;               /* 0x14 */
    float unk18;               /* 0x18 */
    float unk1C;               /* 0x1C */
    float unk20;               /* 0x20 */
    char pad24[0x0C];
} ModelCtxParams;

/* cVUM_GOBJ (gameobj.cc): cGOBJ with an embedded model context at +0x2E50. */
typedef struct cVUM_GOBJ {
    cGOBJ base;                /* 0x0000 */
    int unk60;                 /* 0x0060 */
    void* unk64;               /* 0x0064 */
    char pad68[4];
    struct cVUM_GOBJ* self;    /* 0x006C */
    int unk70;                 /* 0x0070 */
    int unk74;                 /* 0x0074: sub-object (func_0036D630) */
    char pad78[0x178];
    unsigned char unk1F0;      /* 0x01F0 */
    unsigned char unk1F1;      /* 0x01F1 */
    unsigned char unk1F2;      /* 0x01F2 */
    unsigned char unk1F3;      /* 0x01F3 */
    char pad1F4[0x2A70];
    void* model;               /* 0x2C64: points at modelCtx */
    char pad2C68[0x1E8];
    int modelCtx;              /* 0x2E50: model context (ModelCtx_Init) */
} cVUM_GOBJ;

/* 16-byte vector element and an (unk, count, data) array of them. */
typedef struct Elem16 {
    int w[4];
} Elem16;

typedef struct Elem16Vec {
    int unk0;
    int count;
    Elem16* data;
} Elem16Vec;

/* 8-byte (int, float) pair and an (unk, count, data) array of them. */
typedef struct IntFloat {
    int i;
    float f;
} IntFloat;

typedef struct IntFloatVec {
    int unk0;
    int count;
    IntFloat* data;
} IntFloatVec;

/* Small record initialized by func_0021A800 / func_0021A820 (0x0C bytes). */
typedef struct Rec0C {
    int unk0;                  /* 0x0 */
    signed char unk4;          /* 0x4 (func_0021A800 writes -2 as a word over 0x4..0x7) */
    signed char unk5;          /* 0x5 */
    char pad6[2];
    void* unk8;                /* 0x8 */
} Rec0C;

/* Three-word record followed by a flag byte set by its constructors. */
typedef struct RelFlag {
    Rel rel;                   /* 0x0 */
    unsigned char flag;        /* 0xC */
} RelFlag;

/* Four-word record cleared by func_00393EF0; func_00393F10 sets min/max to FLT_MAX. */
typedef struct Quad4 {
    int unk0;
    int unk4;
    float unk8;
    float unkC;
} Quad4;

/* Quad4 followed by two more words (0x18 bytes). */
typedef struct Quad4Ext {
    Quad4 q;
    int unk10;
    int unk14;
} Quad4Ext;

#endif
