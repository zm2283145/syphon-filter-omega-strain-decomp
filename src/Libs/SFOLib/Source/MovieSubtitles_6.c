/*
 * Libs/SFOLib/Source/MovieSubtitles: 11 files, 00412050-00412220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00412050 */
#pragma push /* merge_units */
#include "types.h"
#include "MovieSubtitles_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Resets the block to its default state. */
void cMovieSubtitles_ResetText(SubtitleBlock* b) {
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
void cSubtitleFeed_NextItem(Cursor* c) {
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
int cSubtitleFeed_GetLanguage(Table* t)
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
float cSubtitleFeed_GetEndTime(SubtitleTransformTable* table)
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
float cSubtitleFeed_GetStartTime(EntryTable* t) {
    return t->entries[t->current].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412130 */

/* merge_units: begin func_00412150 */
#pragma push /* merge_units */
/* Copies a four-float vector. */
SubVec4* tRGBA_opAssign(SubVec4* dst, SubVec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}

char* cSubtitleFeed_GetColor(SubtitleBlock* b) {
    return b->unk50;
}

/* Address of column col in the current row (rows of 320 bytes, columns of 100 bytes). */
int cSubtitleFeed_GetText(SubtitleBlock* b, int col) {
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
int cSubtitleFeed_GetNumLines(Obj004121D0* obj)
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
int cSubtitleFeed_GetDisplayFlags(EntryTable_004121F0* t) {
    return t->entries[t->current].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004121F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004121F0 */

/* merge_units: begin func_00412210 */
#pragma push /* merge_units */
/* True while the current row is below unk64. */
int cSubtitleFeed_ItemPending(SubtitleBlock* b) {
    return b->unk68 < b->unk64;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412210 */

/* merge_units: begin func_00412220 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int strlen(const char *);

typedef struct Sub412220 {
    char pad00[0x50];
    void* src;          /* 0x50 */
    char pad54[0x60 - 0x54];
    char* lines[3];     /* 0x60 */
    int pos[3];         /* 0x6C */
    int count;          /* 0x78 */
    char pad7C[4];
    SubVec4 color;      /* 0x80 */
    int lens[3];        /* 0x90 */
    float f9C;          /* 0x9C */
    float fA0;          /* 0xA0 */
    int iA4;            /* 0xA4 */
    int iA8;            /* 0xA8 */
    char padAC[0xB4 - 0xAC];
    int iB4;            /* 0xB4 */
} Sub412220;

#if 0 /* merge_units */
extern int cSubtitleFeed_ItemPending(void* src);
#endif /* merge_units */
#define cSubtitleFeed_ItemPending(a0) (cSubtitleFeed_ItemPending((SubtitleBlock *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cSubtitleFeed_GetDisplayFlags(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetDisplayFlags(a0) (cSubtitleFeed_GetDisplayFlags((EntryTable_004121F0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cSubtitleFeed_GetNumLines(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetNumLines(a0) (cSubtitleFeed_GetNumLines((Obj004121D0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char* cSubtitleFeed_GetText(void* src, int col);
#endif /* merge_units */
#define cSubtitleFeed_GetText(a0, a1) ((char *)cSubtitleFeed_GetText((SubtitleBlock *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern SubVec4* cSubtitleFeed_GetColor(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetColor(a0) ((SubVec4 *)cSubtitleFeed_GetColor((SubtitleBlock *)(a0))) /* merge_units */

extern SubVec4* tRGBA_opAssign(SubVec4* dst, SubVec4* src);
#if 0 /* merge_units */
extern float cSubtitleFeed_GetStartTime(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetStartTime(a0) (cSubtitleFeed_GetStartTime((EntryTable *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern float cSubtitleFeed_GetEndTime(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetEndTime(a0) (cSubtitleFeed_GetEndTime((SubtitleTransformTable *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cSubtitleFeed_GetLanguage(void* src);
#endif /* merge_units */
#define cSubtitleFeed_GetLanguage(a0) (cSubtitleFeed_GetLanguage((Table *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cSubtitleFeed_NextItem(void* src);
#endif /* merge_units */
#define cSubtitleFeed_NextItem(a0) (cSubtitleFeed_NextItem((Cursor *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cMovieSubtitles_ResetText(Sub412220* self);
#endif /* merge_units */
#define cMovieSubtitles_ResetText(a0) (cMovieSubtitles_ResetText((SubtitleBlock *)(a0))) /* merge_units */


void cMovieSubtitles_FirstFrame(Sub412220* self) {
    int i;
    self->iB4 = 0;
    if (cSubtitleFeed_ItemPending(self->src)) {
        self->iA4 = cSubtitleFeed_GetDisplayFlags(self->src);
        self->count = cSubtitleFeed_GetNumLines(self->src);
        for (i = 0; i < self->count; i++) {
            self->lines[i] = cSubtitleFeed_GetText(self->src, i);
            self->lens[i] = strlen(self->lines[i]);
            self->pos[i] = 0;
        }
        tRGBA_opAssign(&self->color, cSubtitleFeed_GetColor(self->src));
        self->f9C = cSubtitleFeed_GetStartTime(self->src);
        self->fA0 = cSubtitleFeed_GetEndTime(self->src);
        self->iA8 = cSubtitleFeed_GetLanguage(self->src);
        cSubtitleFeed_NextItem(self->src);
    } else {
        cMovieSubtitles_ResetText(self);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412220(void) {}
#undef cSubtitleFeed_ItemPending /* merge_units */
#undef cSubtitleFeed_GetDisplayFlags /* merge_units */
#undef cSubtitleFeed_GetNumLines /* merge_units */
#undef cSubtitleFeed_GetText /* merge_units */
#undef cSubtitleFeed_GetColor /* merge_units */
#undef cSubtitleFeed_GetStartTime /* merge_units */
#undef cSubtitleFeed_GetEndTime /* merge_units */
#undef cSubtitleFeed_GetLanguage /* merge_units */
#undef cSubtitleFeed_NextItem /* merge_units */
#undef cMovieSubtitles_ResetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00412220 */

/* merge_units: begin func_00412320 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

struct VBig_412320 { char pad[0x8A74]; virtual void dtor(int f); };
typedef struct { void* buf; int n; int cap; } Buf_412320;
typedef struct { char pad[0x60]; void* p60; } Sub_412320;
typedef struct { char pad[0x110]; } Slot_412320;
typedef struct { char pad[0x2F6]; char f2F6; } Row_412320;
typedef struct {
    Buf_412320 bufs[2]; char pad18[0x1C - 0x18]; int f1C; int f20; char pad24[0x34 - 0x24];
    unsigned char f34; char pad35[0x50 - 0x35]; Sub_412320* p50; VBig_412320* p54;
} Self_412320;
extern "C" {
extern char D_004BEE90[];
extern Slot_412320 g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
void sceGsSyncPath(int a, int b, int c, int d);
}
static inline void Free_412320(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BEE90, line); }
static inline void SubDtor_412320(Sub_412320* s) { if (s) { if (s->p60) Free_412320(s->p60, 0x29A); } }

extern "C" void cMovieSubtitles_Purge(Self_412320* self)
{
    int i;
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    {
        int idx = D_00538C60;
        ((Row_412320*)&g_Video[idx])->f2F6 = 1;
        sceGsSyncPath(0, 0, idx, 1);
    }
    for (i = 0; i < 2; i++) {
        Free_412320(self->bufs[i].buf, 0x94);
        self->bufs[i].buf = 0;
        self->bufs[i].n = 0;
        self->bufs[i].cap = 0;
    }
    {
        Sub_412320* p = self->p50;
        if (p) {
            { AllocGuard g; SubDtor_412320(p); cMemMan_Deallocate(0, p, D_004BEE90, 0x9C); }
            self->p50 = 0;
        }
    }
    {
        VBig_412320* q = self->p54;
        if (q) {
            { AllocGuard g; q->dtor(-1); cMemMan_Deallocate(0, q, D_004BEE90, 0xA2); }
            self->p54 = 0;
        }
    }
    self->f1C = 0;
    self->f20 = 0;
    self->f34 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00412320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00412320 */
