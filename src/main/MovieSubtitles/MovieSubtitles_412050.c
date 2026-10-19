/*
 * main/MovieSubtitles: range (9 files, 00412050-00412210)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "MovieSubtitles_types.h"

/* merge_units: begin func_00412050 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Resets the block to its default state. */
void func_00412050(SubtitleBlock* b) {
    b->base = 0;
    b->unk90 = 0;
    b->unk6C = 0;
    b->unk64 = 0;
    b->unk94 = 0;
    b->unk70 = 0;
    b->unk68 = 0;
    b->unk98 = 0;
    b->unk74 = 0;
    b->color.x = 1.0f;
    b->color.y = 1.0f;
    b->color.z = 1.0f;
    b->color.w = 1.0f;
    b->unk9C = 0x749dc5ae;
    b->unkA0 = -1.0f;
    b->unkA4 = 3;
    b->unkA8 = 1;
    b->unkAC = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412050 */

/* merge_units: begin func_004120C0 */
#pragma push /* merge_units */
#pragma optimization_level 1

typedef struct Cursor {
    char pad[0x64];
    int count;
    int current;
} Cursor;

/* Advances current while below count. */
void func_004120C0(Cursor* c) {
    if (c->current < c->count) c->current++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004120C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004120C0 */

/* merge_units: begin func_004120F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x13C]; int value; } Entry140; /* size 0x140 */
typedef struct { char pad[0x60]; Entry140* entries; char pad64[4]; int current; } Table;

/* Returns the value of the current 0x140-byte entry. */
int func_004120F0(Table* t)
{
    return t->entries[t->current].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004120F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004120F0 */

/* merge_units: begin func_00412110 */
#pragma push /* merge_units */
/* Return the final float field of the selected subtitle transform. */
float func_00412110(SubtitleTransformTable* table)
{
    return table->entries[table->current].unk134;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412110 */

/* merge_units: begin func_00412130 */
#pragma push /* merge_units */
typedef struct Entry140_00412130 {
    char pad[0x130];
    float value;
    char pad2[0xC];
} Entry140_00412130;

typedef struct EntryTable {
    char pad[0x60];
    Entry140_00412130* entries;
    int unk64;
    int current;
} EntryTable;

/* Returns the float at +0x130 of the current 0x140-byte entry. */
float func_00412130(EntryTable* t) {
    return t->entries[t->current].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412130 */

/* merge_units: begin func_00412150 */
#pragma push /* merge_units */
/* Copies a four-float vector. */
SubVec4* SubtitleTrack_LoadCue(SubVec4* dst, SubVec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}

char* func_00412180(SubtitleBlock* b) {
    return b->unk50;
}

/* Address of column col in the current row (rows of 320 bytes, columns of 100 bytes). */
int func_00412190(SubtitleBlock* b, int col) {
    int row = b->unk68;
    int base = b->base;
    return (base + (row * 320)) + (col * 100);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412150 */

/* merge_units: begin func_004121D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x12C]; int unk12C; char pad130[0x10]; } Entry004121D0; /* 0x140 */
typedef struct { char pad[0x60]; Entry004121D0* entries; int unk64; int current; } Obj004121D0;
/* Return field 0x12C of the current entry. */
int func_004121D0(Obj004121D0* obj)
{
    return obj->entries[obj->current].unk12C;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004121D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004121D0 */

/* merge_units: begin func_004121F0 */
#pragma push /* merge_units */
typedef struct Entry140_004121F0 {
    char pad000[0x138];
    int value; /* 0x138 */
    char pad13C[4];
} Entry140_004121F0; /* size 0x140 */

typedef struct EntryTable_004121F0 {
    char pad00[0x60];
    Entry140_004121F0* entries; /* 0x60 */
    char pad64[4];
    int current;       /* 0x68 */
} EntryTable_004121F0;

/* Returns the value field of the current entry. */
int func_004121F0(EntryTable_004121F0* t) {
    return t->entries[t->current].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004121F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004121F0 */

/* merge_units: begin func_00412210 */
#pragma push /* merge_units */
/* True while the current row is below unk64. */
int func_00412210(SubtitleBlock* b) {
    return b->unk68 < b->unk64;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412210 */
