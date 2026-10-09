#ifndef GUISCORESEQUIP_TYPES_H
#define GUISCORESEQUIP_TYPES_H

/* Types used by GuiScoresEquip.cc. Offsets come from the matched code. */

#include "types.h"

/* Six-float record (two xyz triples). */
typedef struct Float6 {
    float v[6];
} Float6;

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

#endif
