#ifndef HUMAN_TYPES_H
#define HUMAN_TYPES_H

/*
 * Provisional layouts used by src/main/human. Offsets are taken from the
 * matched code; names follow the research notes where they establish a role,
 * otherwise unkXX (hex offset).
 */

#include "types.h"

/* Object referenced from Actor.unk3584 (only two flag bytes are touched here). */
typedef struct ActorLink3584 {
    char pad00[0x32];
    signed char unk32;
    char pad33[1];
    signed char unk34;
} ActorLink3584;

/* Object referenced from Actor.unk3524. */
typedef struct ActorLink3524 {
    char pad00[0x84];
    unsigned char state; /* compared against 6 */
} ActorLink3524;

/* Human actor (partial). Roots at +0x3290/+0x3294/+0x3298 are the resolved
 * "flor", "edge" and "ladd" roots; +0x3314 is the secondary component. */
typedef struct Actor {
    char pad0000[0x14];
    unsigned char unk14;
    char pad0015[0x324C - 0x15];
    int flags324C;                  /* bit 8: secondary component needs release */
    char pad3250[0x3290 - 0x3250];
    void* floorRoot;                /* +0x3290 "flor" */
    void* edgeRoot;                 /* +0x3294 "edge" */
    char pad3298[0x3314 - 0x3298];
    void* secondary;                /* +0x3314 secondary component */
    char pad3318[0x33A4 - 0x3318];
    unsigned char unk33A4;
    char pad33A5[0x3524 - 0x33A5];
    ActorLink3524* unk3524;
    char pad3528[0x3584 - 0x3528];
    ActorLink3584* unk3584;
    char pad3588[0x3598 - 0x3588];
    unsigned char unk3598;
} Actor;

/* Message/event base (0x24 bytes): vtable, seven words and a byte. */
typedef struct Message {
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    signed char unk20;
    char pad21[3];
} Message; /* size 0x24 */

/* Message carrying an int argument and up to two byte arguments. */
typedef struct ArgMsg {
    Message base;
    int arg0;               /* +0x24 */
    signed char arg1;       /* +0x28 */
    signed char arg2;       /* +0x29 */
} ArgMsg;

/* Message carrying only byte arguments. */
typedef struct ByteMsg {
    Message base;
    signed char b0;         /* +0x24 */
    signed char b1;         /* +0x25 */
} ByteMsg;

/* Message carrying one unsigned byte argument. */
typedef struct FlagMsg {
    Message base;
    unsigned char value;    /* +0x24 */
} FlagMsg;

/* Animation event (0x38 bytes). */
typedef struct AnimEvent {
    Message base;
    int unk24;
    signed char unk28;
    char pad29[3];
    int unk2C;
    unsigned char unk30;
    char pad31[3];
    float unk34;
} AnimEvent; /* size 0x38 */

/* Scalar curve storage embedded at +0x18 of curve channels (0x18 bytes). */
typedef struct CurveSegment {
    char pad[0x18];
} CurveSegment;

/* Base of AnimChannel / AngleCurve (constructed with base table 0x004DA380). */
typedef struct CurveChannel {
    void* vtable;
    float previous;         /* +0x04 */
    float current;          /* +0x08 */
    float target;           /* +0x0C */
    float rate;             /* +0x10 */
    float damping;          /* +0x14 (AngleCurve: set to 15 by the actor) */
    CurveSegment segment;   /* +0x18 */
    char binding[8];        /* +0x30 bound to segment */
} CurveChannel;

/* Normalized animation channel (0x3C bytes, table 0x004DA840). */
typedef struct AnimChannel {
    CurveChannel base;
    unsigned char wrap;     /* +0x38 */
    char pad39[3];
} AnimChannel;

/* Indexed record of 0x3C bytes stored in a vector-like collection. */
typedef struct ChannelVec {
    int unk0;
    int count;
    AnimChannel* data;
} ChannelVec;

/* 3x4 float block (three rows of xyzw). */
typedef struct Mtx34 {
    float m[3][4];
} Mtx34;

#endif
