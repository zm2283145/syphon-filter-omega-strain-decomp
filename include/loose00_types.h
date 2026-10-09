#ifndef LOOSE00_TYPES_H
#define LOOSE00_TYPES_H

/*
 * Types for loose functions in src/main/ (not yet assigned to a directory).
 * Field names are provisional (unkXX) unless research notes justify a name.
 */

#include "types.h"
#include "gobj_types.h"
#include "humanCollision_types.h"

/* Human collision preset record (0xF0 bytes); nine live in a manager at +0x10.
 * See research HUMAN_COLLISION.md. */
typedef struct HumanColPreset {
    unsigned char selector;         /* 0x00 */
    char pad01[3];
    int mask0;                      /* 0x04 */
    int mask1;                      /* 0x08 */
    int mask2;                      /* 0x0C */
    int mask3;                      /* 0x10 */
    float heightMin;                /* 0x14 */
    float heightMax;                /* 0x18 */
    float distSqMin;                /* 0x1C */
    float distSqMax;                /* 0x20 */
    float cosMin;                   /* 0x24 */
    float cosMax;                   /* 0x28 */
    unsigned char negateFlag;       /* 0x2C */
    char pad2D[3];
    unsigned char enabled;          /* 0x30 */
    unsigned char active;           /* 0x31 */
    unsigned char accepted;         /* 0x32 */
    char pad33[0x70 - 0x33];
    unsigned char unk70;            /* 0x70 */
    char pad71[0x90 - 0x71];
    int unk90;                      /* 0x90 */
    int unk94;                      /* 0x94 */
    int unk98;                      /* 0x98 */
    char pad9C[4];
    int unkA0;                      /* 0xA0 */
    char padA4[0xE0 - 0xA4];
    float savedHeight;              /* 0xE0 */
    int unkE4;                      /* 0xE4 */
    char padE8[8];
} HumanColPreset;

/* Hit detail block of a line-of-sight result (0x70 bytes, copied by
 * func_00139B00 / func_0013AA30). */
typedef struct LosHitInfo {
    Vec4 row0;                      /* 0x00 */
    Vec4 row1;                      /* 0x10 */
    Vec4 row2;                      /* 0x20 */
    Vec4 row3;                      /* 0x30 */
    Vec4 unk40;                     /* 0x40 */
    unsigned char unk50;            /* 0x50 */
    unsigned char unk51;            /* 0x51 */
    unsigned char unk52;            /* 0x52 */
    char pad53[0x60 - 0x53];
    Vec4 unk60;                     /* 0x60 */
} LosHitInfo;

/* Line-of-sight query result (see research LOS_QUERY_NATIVE.md: status byte +0,
 * point +0x10, metadata, word +0x90). */
typedef struct LosResult {
    unsigned char status;           /* 0x00 */
    char pad01[0x10 - 0x01];
    Vec4 point;                     /* 0x10 */
    LosHitInfo hit;                 /* 0x20 */
    int unk90;                      /* 0x90 */
} LosResult;

/* "LOS result ready" event: Event base then a copy of the result at +0x30. */
typedef struct LosResultEvent {
    void* vtable;                   /* 0x00 */
    char pad04[0x30 - 0x04];
    LosResult result;               /* 0x30 */
} LosResultEvent;

typedef struct IntPair {
    int a;                          /* 0x00 */
    int b;                          /* 0x04 */
} IntPair;

/* Owner + value + flag (func_0013EE70). */
typedef struct Unk0013EE70 {
    int owner;                      /* 0x00 */
    unsigned char valid;            /* 0x04 */
    char pad05[3];
    int value;                      /* 0x08 */
} Unk0013EE70;

/* 0x24-byte record (copy func_001D7840, ctor func_001D86D0). */
typedef struct Rec24 {
    int unk00;                      /* 0x00 */
    int unk04;                      /* 0x04 */
    float unk08;                    /* 0x08 */
    float unk0C;                    /* 0x0C */
    int unk10;                      /* 0x10 */
    float unk14;                    /* 0x14 */
    int unk18;                      /* 0x18 */
    int unk1C;                      /* 0x1C */
    unsigned char unk20;            /* 0x20 */
} Rec24;

typedef struct FloatPair {
    float a;                        /* 0x00 */
    float b;                        /* 0x04 */
} FloatPair;

typedef struct Float6 {
    float f[6];                     /* 0x00 */
} Float6;

typedef struct IntQuad {
    int v[4];                       /* 0x00 */
} IntQuad;

typedef struct Unk001EB2F0 {
    char pad00[0x30];
    unsigned char unk30;            /* 0x30 */
    char pad31[0x50 - 0x31];
    int unk50;                      /* 0x50 */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
} Unk001EB2F0;

/* Object built by func_00147910 (at least 0xD8 bytes). */
typedef struct Unk00147910 {
    char pad00[0x10];
    unsigned char unk10;            /* 0x10 */
    char pad11[3];
    int unk14;                      /* 0x14 */
    unsigned char unk18;            /* 0x18 */
    char pad19[3];
    char unk1C[0xB8 - 0x1C];        /* 0x1C sub-object */
    int unkB8[7];                   /* 0xB8 */
    int unkD4;                      /* 0xD4 */
} Unk00147910;

/* Counted int array: capacity +0, size +8, data +0xC. */
typedef struct IntArray {
    int capacity;                   /* 0x00 */
    int unk04;                      /* 0x04 */
    int size;                       /* 0x08 */
    int* data;                      /* 0x0C */
} IntArray;

typedef struct IntSpan {
    int* end;                       /* 0x00 */
    int* begin;                     /* 0x04 */
    int* end2;                      /* 0x08 */
    int* capEnd;                    /* 0x0C */
} IntSpan;

/* 16-byte element with a flag byte at +0x0C. */
typedef struct FlagElem16 {
    char pad00[0x0C];
    unsigned char unk0C;            /* 0x0C */
    char pad0D[3];
} FlagElem16;

/* 0x60-byte record (stride of the collision edge candidate lists). */
typedef struct Elem60 {
    char pad00[0x60];
} Elem60;

typedef struct Vec16Array {
    int unk00;                      /* 0x00 */
    int count;                      /* 0x04 */
    FlagElem16* data;                   /* 0x08 */
} Vec16Array;

typedef struct Vec60Array {
    int unk00;                      /* 0x00 */
    int count;                      /* 0x04 */
    Elem60* data;                   /* 0x08 */
} Vec60Array;

typedef struct Unk001E1D10 {
    char pad00[0x3C];
    float unk3C;                    /* 0x3C */
} Unk001E1D10;

typedef struct Unk001E1D60 {
    char pad00[0x50];
    int unk50;                      /* 0x50 */
} Unk001E1D60;

/* Object holding a table of 16-byte entries at +0x20 (same as SpecTableOwner). */
typedef struct TableOwner {
    char pad00[0x20];
    char* table;                    /* 0x20 */
} TableOwner;

typedef struct TableOwnerRef {
    int unk00;                      /* 0x00 */
    TableOwner** owner;             /* 0x04 */
} TableOwnerRef;

/* List iterator (one node pointer). */
typedef struct ListPos {
    void* node;
} ListPos;

/* 0xE0-byte record. */
typedef struct ElemE0 {
    char pad00[0xE0];
} ElemE0;

typedef struct ElemE0Iter {
    ElemE0* p;
} ElemE0Iter;

typedef struct VecE0Array {
    int unk00;                      /* 0x00 */
    int count;                      /* 0x04 */
    ElemE0* data;                   /* 0x08 */
} VecE0Array;

/* cGOBJ-derived object built by func_001C5950 (at least 0x74 bytes). */
typedef struct UnkGobj001C5950 {
    cGOBJ base;                     /* 0x00 */
    int unk60;                      /* 0x60: constructor argument */
    int unk64;                      /* 0x64 */
    short unk68;                    /* 0x68 */
    char pad6A[6];
    float unk70;                    /* 0x70: 1.0 after construction */
} UnkGobj001C5950;

typedef struct Unk0013AAE0 {
    char pad00[0x40];
    unsigned char unk40;            /* 0x40 */
    char pad41;
    unsigned char unk42;            /* 0x42 */
    char pad43[0x60 - 0x43];
    int unk60;                      /* 0x60 */
    int unk64;                      /* 0x64 */
} Unk0013AAE0;

typedef struct FlagElem16Iter {
    FlagElem16* p;
} FlagElem16Iter;

typedef struct Elem60Iter {
    Elem60* p;
} Elem60Iter;

/* Buffer cursor: current pointer, start, byte offset. */
typedef struct BufCursor {
    int cur;                        /* 0x00 */
    int start;                      /* 0x04 */
    int pos;                        /* 0x08 */
} BufCursor;

typedef struct FloatIntPair {
    float f;                        /* 0x00 */
    int i;                          /* 0x04 */
} FloatIntPair;

typedef struct ValFlag {
    int value;                      /* 0x00 */
    unsigned char flag;             /* 0x04 */
} ValFlag;

/* 0x1D0-byte record. */
typedef struct Elem1D0 {
    char pad00[0x1D0];
} Elem1D0;

typedef struct Elem1D0Iter {
    Elem1D0* p;
} Elem1D0Iter;

typedef struct Vec1D0Array {
    int unk00;                      /* 0x00 */
    int count;                      /* 0x04 */
    Elem1D0* data;                  /* 0x08 */
} Vec1D0Array;

/* 0x70-byte record. */
typedef struct Elem70 {
    char pad00[0x70];
} Elem70;

typedef struct Vec70Array {
    int unk00;                      /* 0x00 */
    int count;                      /* 0x04 */
    Elem70* data;                   /* 0x08 */
} Vec70Array;

typedef struct Unk00182880 {
    char pad00[0x08];
    int unk08;                      /* 0x08 */
    char pad0C[4];
    int unk10;                      /* 0x10 */
} Unk00182880;

typedef struct Unk001CEA20 {
    char pad000[0x380];
    unsigned char unk380;           /* 0x380 */
    unsigned char unk381;           /* 0x381 */
} Unk001CEA20;

typedef struct ByteBool {
    unsigned char value;            /* 0x00 */
    unsigned char nonZero;          /* 0x01 */
} ByteBool;

typedef struct AnimScalarDef {
    char pad00[0x10];
    float duration;                 /* 0x10 */
} AnimScalarDef;

typedef struct AnimScalar {
    AnimScalarDef* def;             /* 0x00 */
    float timer;                    /* 0x04 */
    char pad08[4];
    float unk0C;                    /* 0x0C */
} AnimScalar;

/* Object returned by func_001698C0; font handles at +0x280. */
typedef struct FontOwner {
    char pad000[0x280];
    int fonts[1];                   /* 0x280 */
} FontOwner;

typedef struct Unk0013D5B0 {
    char pad00[0x10];
    int unk10;                      /* 0x10 */
} Unk0013D5B0;

typedef struct Unk001830D0 {
    char pad00[0x2C];
    unsigned char unk2C;            /* 0x2C */
    unsigned char unk2D;            /* 0x2D */
    unsigned char unk2E;            /* 0x2E */
} Unk001830D0;

typedef struct Byte3 {
    unsigned char b0;               /* 0x00 */
    unsigned char b1;               /* 0x01 */
    unsigned char b2;               /* 0x02 */
} Byte3;

/* Global at 0x004E2D58: handler +0x0C and its argument +0x10. */
typedef struct Unk004E2D58 {
    char pad00[0x0C];
    int handler;                    /* 0x0C */
    int arg;                        /* 0x10 */
} Unk004E2D58;

/* Node of the global destructor chain. */
typedef struct DestructorChain {
    struct DestructorChain* next;   /* 0x00 */
    void* destructor;               /* 0x04 */
    void* object;                   /* 0x08 */
} DestructorChain;

/* Scalar curve storage embedded at +0x18 of curve channels (0x18 bytes). */
typedef struct CurveSegment {
    char pad[0x18];
} CurveSegment;

/* Base of AnimChannel (copied from GuiAgentInfo_types.h). */
typedef struct CurveChannel {
    void* vtable;
    float previous;                 /* 0x04 */
    float current;                  /* 0x08 */
    float target;                   /* 0x0C */
    float rate;                     /* 0x10 */
    float damping;                  /* 0x14 */
    CurveSegment segment;           /* 0x18 */
    char binding[8];                /* 0x30 bound to segment */
} CurveChannel;

/* Normalized animation channel (0x3C bytes, vtable 0x004DA840). */
typedef struct AnimChannel {
    CurveChannel base;
    unsigned char wrap;             /* 0x38 */
    char pad39[3];
} AnimChannel;

/* Doubly linked list node / list with sentinel at +4. */
typedef struct LinkNode {
    struct LinkNode* next;          /* 0x00 */
    struct LinkNode* prev;          /* 0x04 */
} LinkNode;

typedef struct LinkList {
    int count;                      /* 0x00 */
    LinkNode sentinel;              /* 0x04 */
} LinkList;

typedef struct Unk0013BDE0 {
    char pad00[0x0C];
    int unk0C;                      /* 0x0C */
} Unk0013BDE0;

typedef struct VObject {
    void* vtable;                   /* 0x00 */
} VObject;

typedef struct RegionCache {
    char pad00[0x08];
    int region;                     /* 0x08 */
} RegionCache;

typedef struct TimedRefDef {
    char pad00[0x40];
    float unk40;                    /* 0x40 */
} TimedRefDef;

typedef struct TimedRef {
    TimedRefDef* def;               /* 0x00 */
    float timer;                    /* 0x04 */
} TimedRef;

typedef struct Unk001CAE10 {
    char pad000[0x312];
    signed char unk312;             /* 0x312 */
    signed char unk313;             /* 0x313 */
} Unk001CAE10;

typedef struct Elem20 {
    char pad00[0x20];
} Elem20;

typedef struct Elem1C0 {
    char pad00[0x1C0];
} Elem1C0;

typedef struct ByteIter {
    unsigned char* p;
} ByteIter;

typedef struct Unk00184470 {
    char pad00[0x24];
    unsigned char type;             /* 0x24 */
} Unk00184470;

typedef struct NodeRef {
    int unk00;                      /* 0x00 */
    char* node;                     /* 0x04 */
} NodeRef;

typedef struct Unk00183220 {
    char pad00[0x50];
    int unk50;                      /* 0x50 */
} Unk00183220;

typedef struct Unk001827A0 {
    char pad00[0x54];
    int unk54;                      /* 0x54 */
    char pad58[5];
    unsigned char unk5D;            /* 0x5D */
} Unk001827A0;

#endif
