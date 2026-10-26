/*
 * main/xlib: range (2 files, 0037E0D0-0037E210)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0037E0D0 */
#pragma push /* merge_units */
typedef unsigned long u64;
typedef long s64;

typedef struct GsCtx37E0D0 {
    char p0[0x1C];
    unsigned int w;       /* 0x1C */
    unsigned int h;       /* 0x20 */
    char p24[0x8];
    unsigned int psm;     /* 0x2C */
    unsigned int zpsm;    /* 0x30 */
    char p34[0x30];
    unsigned char field;  /* 0x64 */
    char p65[0x2B];
    u64 frame;            /* 0x90 */
    u64 frame2;           /* 0x98 */
    u64 zbuf;             /* 0xA0 */
    u64 xyoffset;         /* 0xA8 */
    char pB0[0x20];
    unsigned char dirty;  /* 0xD0 */
    char pD1[0x27];
    unsigned int fbmsk;   /* 0xF8 */
    unsigned int zmsk;    /* 0xFC */
    char p100[0x2C];
    unsigned int fbp[2];  /* 0x12C */
    unsigned int zbp;     /* 0x134 */
    char p138[0x8];
    int buf;              /* 0x140 */
    char p144[0x94];
    int frames;           /* 0x1D8 */
    char p1DC[0xA70 - 0x1DC];
    int slot;             /* 0xA70 */
    char pA74[0x1058 - 0xA74];
    int dev;              /* 0x1058 */
} GsCtx37E0D0;

typedef struct Slot37E0D0 { char p0[0x110]; } Slot37E0D0;


#define GS_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

static inline void GsCtx_SetBufferRegs(GsCtx37E0D0* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64*)0x12001000 >> 13) & 1) << 3;
    }
    c->frame = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->dirty = 1;
}
void XLib_RestoreFrameEnv(GsCtx37E0D0* c)
{
    GsCtx_SetBufferRegs(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037E0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037E0D0 */

/* merge_units: begin func_0037E210 */
#pragma push /* merge_units */
typedef unsigned long long u64_f4;
typedef struct { char pad[0x90]; u64_f4 frame; u64_f4 frameNoMask; u64_f4 zbuf; u64_f4 xyoffset; char padB0[0x20]; unsigned char dirty; } GsTarget_f4;
void Renderer_BindTarget(GsTarget_f4* t, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp,
                   unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx = (2048 - (w >> 1)) << 4;
    unsigned int ofy = (2048 - (h >> 1)) << 4;
    u64_f4 lo;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64_f4*)0x12001000 >> 13) & 1) << 3;
    }
    lo = (u64_f4)fbp | ((u64_f4)(w >> 6) << 16) | ((u64_f4)psm << 24);
    t->frame = ((u64_f4)fbmsk << 32) | lo;
    t->frameNoMask = lo | ((u64_f4)0xFFFFFF << 32);
    t->zbuf = (u64_f4)zbp | ((u64_f4)zpsm << 24) | ((u64_f4)zmsk << 32);
    t->xyoffset = (u64_f4)ofx | ((u64_f4)ofy << 32);
    t->dirty = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037E210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037E210 */
