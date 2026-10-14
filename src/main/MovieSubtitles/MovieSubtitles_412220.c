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

extern int func_00412210(void* src);
extern int func_004121F0(void* src);
extern int func_004121D0(void* src);
extern char* func_00412190(void* src, int col);
extern SubVec4* func_00412180(void* src);
extern SubVec4* func_00412150(SubVec4* dst, SubVec4* src);
extern float func_00412130(void* src);
extern float func_00412110(void* src);
extern int func_004120F0(void* src);
extern void func_004120C0(void* src);
extern void func_00412050(Sub412220* self);

void MovieSubtitles_Start(Sub412220* self) {
    int i;
    self->iB4 = 0;
    if (func_00412210(self->src)) {
        self->iA4 = func_004121F0(self->src);
        self->count = func_004121D0(self->src);
        for (i = 0; i < self->count; i++) {
            self->lines[i] = func_00412190(self->src, i);
            self->lens[i] = strlen(self->lines[i]);
            self->pos[i] = 0;
        }
        func_00412150(&self->color, func_00412180(self->src));
        self->f9C = func_00412130(self->src);
        self->fA0 = func_00412110(self->src);
        self->iA8 = func_004120F0(self->src);
        func_004120C0(self->src);
    } else {
        func_00412050(self);
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
extern Slot_412320 D_005381F0[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
void sceGsSyncPath(int a, int b, int c, int d);
}
static inline void Free_412320(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BEE90, line); }
static inline void SubDtor_412320(Sub_412320* s) { if (s) { if (s->p60) Free_412320(s->p60, 0x29A); } }

extern "C" void func_00412320(Self_412320* self)
{
    int i;
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    {
        int idx = D_00538C60;
        ((Row_412320*)&D_005381F0[idx])->f2F6 = 1;
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
