/*
 * main/MovieSubtitles: range (2 files, 00412220-00412320)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int strlen(const char *);

/* merge_units: begin func_00412220 */
#pragma push /* merge_units */
typedef struct SubVec4 { float x, y, z, w; } SubVec4;

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

extern int cSubtitleFeed_ItemPending(void* src);
extern int cSubtitleFeed_GetDisplayFlags(void* src);
extern int cSubtitleFeed_GetNumLines(void* src);
extern char* cSubtitleFeed_GetText(void* src, int col);
extern SubVec4* cSubtitleFeed_GetColor(void* src);
extern SubVec4* SubtitleTrack_LoadCue(SubVec4* dst, SubVec4* src);
extern float cSubtitleFeed_GetStartTime(void* src);
extern float cSubtitleFeed_GetEndTime(void* src);
extern int cSubtitleFeed_GetLanguage(void* src);
extern void cSubtitleFeed_NextItem(void* src);
extern void cMovieSubtitles_ResetText(Sub412220* self);

void MovieSubtitles_Start(Sub412220* self) {
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
        SubtitleTrack_LoadCue(&self->color, cSubtitleFeed_GetColor(self->src));
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
static inline void Free_412320(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BEE90, line); }
static inline void SubDtor_412320(Sub_412320* s) { if (s) { if (s->p60) Free_412320(s->p60, 0x29A); } }

extern "C" void SubtitleTrack_Destroy(Self_412320* self)
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
            { AllocGuard g; SubDtor_412320(p); Mem_Free(0, p, D_004BEE90, 0x9C); }
            self->p50 = 0;
        }
    }
    {
        VBig_412320* q = self->p54;
        if (q) {
            { AllocGuard g; q->dtor(-1); Mem_Free(0, q, D_004BEE90, 0xA2); }
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
