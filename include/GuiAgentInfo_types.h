#ifndef GUIAGENTINFO_TYPES_H
#define GUIAGENTINFO_TYPES_H

/*
 * Types used by GuiAgentInfo.cc (agent info / stats screen) and the template
 * helpers emitted into it. Offsets come from the matched code.
 */

#include "types.h"

/* Scalar curve storage embedded at +0x18 of curve channels (0x18 bytes). */
typedef struct CurveSegment {
    char pad[0x18];
} CurveSegment;

/* Base of AnimChannel (constructed with base table 0x004DA380). */
typedef struct CurveChannel {
    void* vtable;
    float previous;         /* +0x04 */
    float current;          /* +0x08 */
    float target;           /* +0x0C */
    float rate;             /* +0x10 */
    float damping;          /* +0x14 */
    CurveSegment segment;   /* +0x18 */
    char binding[8];        /* +0x30 bound to segment */
} CurveChannel;

/* Normalized animation channel (0x3C bytes, table 0x004DA840). */
typedef struct AnimChannel {
    CurveChannel base;
    unsigned char wrap;     /* +0x38 */
    char pad39[3];
} AnimChannel;

/* 3x4 float block (three rows of xyzw). */
typedef struct Mtx34 {
    float m[3][4];
} Mtx34;

/* Object holding a 4x4-style matrix at +0x10 whose first three rows are set
 * from a Mtx34 (rows copied xyz first, then the w column). */
typedef struct MtxHolder {
    char pad00[0x10];
    float m[3][4];          /* +0x10 */
} MtxHolder;

/* Pair constructed as (value, 0). */
typedef struct ValuePair {
    int value;
    int unk04;
} ValuePair;

/* Range-like record whose five float fields get shifted by the same offset. */
typedef struct ShiftRange {
    int unk00;
    float unk04;
    float unk08;
    int unk0C;
    float unk10;
    int unk14;
    float unk18;
    int unk1C;
    float unk20;
} ShiftRange;

#endif
