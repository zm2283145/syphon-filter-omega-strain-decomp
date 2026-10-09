#ifndef INTERFACE_MODEL_TYPES_H
#define INTERFACE_MODEL_TYPES_H

/*
 * Types used by the interface model containers (interface_model).
 * Offsets come from the matched code. Fields named unkXX are not understood yet.
 */

#include "types.h"

/* PtrVec followed by a flag byte. */
typedef struct OwnedVec {
    int unk0;
    int count;
    int* data;
    char unk0C;                     /* 0x0C set to 1 after init */
} OwnedVec;

/* Vector with untyped storage (element size chosen by the caller). */
typedef struct RawVec {
    int unk0;
    int count;                      /* 0x04 */
    char* data;                     /* 0x08 */
} RawVec;

/* List iterator used by the push_back wrappers. */
typedef struct ListPos {
    void* node;
} ListPos;

typedef struct Vec2f {
    float x, y;
} Vec2f;

/* Float followed by a 3-float vector, read from a stream by func_003F3DF0. */
typedef struct FloatVec3 {
    float f;
    float v[3];
} FloatVec3;

/* Object constructed by func_003F1C10 (vtable D_004E0800); 0x18 bytes. */
typedef struct IfModelItem {
    void* vtable;                   /* 0x00 */
    int unk04;                      /* 0x04 */
    float unk08;                    /* 0x08 -1.0 initially */
    float unk0C;                    /* 0x0C -1.0 initially */
    int unk10;                      /* 0x10 */
    char unk14;                     /* 0x14 */
} IfModelItem;

#endif
