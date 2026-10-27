/*
 * Libs/SFOLib/Source/xlib: 5 files, 0037A370-0037B000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037A370 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
/* XLib_ClearActiveBuffer: queues a GS packet that clears a w x h rectangle of the
 * renderer's frame/z buffers with the given RGBA colour (z test off when
 * flag is set). Same packet builder shape as XLib_ClearZBuffer/XLib_ClearScreen_void. */
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x90];
    u64_t frame;
    char pad98[0xA0 - 0x98];
    u64_t zbuf;
    u64_t test;
    char padB0[0xD0 - 0xB0];
    unsigned char ready;
} R370;
extern "C" {
extern char D_00537F80[];
extern u64_t D_004BC1B0[];
extern u64_t* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
}

extern "C" void XLib_ClearActiveBuffer(R370* o, int w, int h, int* rgba, int flag, int idx)
{
    GsQ* q = (GsQ*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 12, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x5000000C << 32);
    q->hi = 0x800BULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = o->frame; q++; q->lo = 0x4C;
    q->hi = o->zbuf; q++; q->lo = 0x4E;
    q->hi = o->test; q++; q->lo = 0x18;
    q->hi = ((u64_t)(unsigned int)(w - 1) << 16) | ((u64_t)(unsigned int)(h - 1) << 48); q++; q->lo = 0x40;
    q->hi = (u64_t)!(bool)flag | 0x31000; q++; q->lo = 0x47;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = 0x4E; q++; q->lo = 0;
    q->hi = (u64_t)rgba[0] | ((u64_t)rgba[1] << 8) | ((u64_t)rgba[2] << 16) | ((u64_t)rgba[3] << 24) | ((u64_t)0x3F800000 << 32); q++; q->lo = 1;
    q->hi = D_004BC1B0[idx]; q++; q->lo = 0x42;
    q->hi = (u64_t)((0x800 - ((unsigned int)w >> 1)) << 4) | ((u64_t)((0x800 - ((unsigned int)h >> 1)) << 4) << 16); q++; q->lo = 5;
    q->hi = (u64_t)((((unsigned int)w >> 1) + 0x800) << 4) | ((u64_t)((((unsigned int)h >> 1) + 0x800) << 4) << 16); q++; q->lo = 5;
    o->ready = 1;
}
static inline void merge_flush_func_0037A370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A370 */

/* merge_units: begin func_0037A5C0 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0x2C - 0x24];
    int psm;
    char pad30[0xC8 - 0x30];
    u64_t alpha;
    unsigned char ready;
    char padD1[0x12C - 0xD1];
    unsigned int tbp[5];
    int cur;
} R5C0;

void XLib_ClearScreen_void(R5C0* o)
{
    unsigned int tbp = o->tbp[o->cur];
    GsQ* q = (GsQ*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 8, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x50000008 << 32);
    q->hi = 0x8007ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = (u64_t)tbp | ((u64_t)(o->w >> 6) << 16) | ((u64_t)o->psm << 24); q++; q->lo = 0x4C;
    q->hi = 0x30000; q++; q->lo = 0x47;
    q->hi = 6; q++; q->lo = 0;
    q->hi = o->alpha; q++; q->lo = 1;
    q->hi = ((0x800 - (o->w >> 1)) << 4) | ((u64_t)((0x800 - (o->h >> 1)) << 4) << 16); q++; q->lo = 5;
    q->hi = (((o->w >> 1) + 0x800) << 4) | ((u64_t)(((o->h >> 1) + 0x800) << 4) << 16); q++; q->lo = 5;
    o->ready = 1;
}
static inline void merge_flush_func_0037A5C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A5C0 */

/* merge_units: begin func_0037A750 */
#pragma push /* merge_units */
typedef unsigned long u64;
typedef long s64;

typedef struct GsCtx37A750 {
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
} GsCtx37A750;

typedef struct Slot37A750 { char p0[0x110]; } Slot37A750;

extern void cTexMan_TermTextureStream(int);
extern void cDmaMan_NextFrame(void*);
extern void XLib_DeferDeleteDmaData(GsCtx37A750*, int);
#if 0 /* merge_units */
extern void XLib_NextPrimFrame(GsCtx37A750*);
#endif /* merge_units */
void XLib_NextPrimFrame(); /* merge_units */

extern void cTexMan_StartFrame(int);
extern int g_TimerAccum;
extern s64 g_TickCounter64;

#define GS_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

static inline void GsCtx_SetBufferRegs(GsCtx37A750* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
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
void XLib_NextFrameSlave(GsCtx37A750* c)
{
    unsigned int t;
    while ((*(volatile int*)0x10009000 & 0x100) || (*(volatile int*)0x10003C00 & 3) ||
           (*(volatile int*)0x10003C00 & 0x1F000000))
        ;
    while ((*(volatile int*)0x1000A000 & 0x100) || (*(volatile int*)0x10003020 & 0xC00))
        ;
    cTexMan_TermTextureStream(c->dev);
    cDmaMan_NextFrame(D_00537F80);
    XLib_DeferDeleteDmaData(c, 0);
    c->buf ^= 1;
    XLib_NextPrimFrame(c);
    c->frames++;
    GsCtx_SetBufferRegs(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
    cTexMan_StartFrame(c->dev);
    t = *(volatile int*)0x10000800 + g_TimerAccum;
    g_TickCounter64 += (int)((float)t / 5.76f);
    *(volatile int*)0x10000800 = 0;
    *(volatile int*)0x10000810 = 0x82;
    g_TimerAccum = 0;
}
static inline void merge_flush_func_0037A750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A750 */

/* merge_units: begin func_0037A9F0 */
#pragma push /* merge_units */
typedef struct Rt37A9F0 { char p0[0x14]; } Rt37A9F0;

typedef struct GsCtx37A9F0 {
    unsigned int flags;   /* 0x00 */
    char p4[0x18];
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
    char p144[0x8C];
    int clear0;           /* 0x1D0 */
    int clear1;           /* 0x1D4 */
    int frames;           /* 0x1D8 */
    char p1DC[0x4];
    float dt;             /* 0x1E0 */
    unsigned int maxRate; /* 0x1E4 */
    float rate;           /* 0x1E8 */
    char p1EC[0xA70 - 0x1EC];
    int slot;             /* 0xA70 */
    char pA74[0x1058 - 0xA74];
    int dev;              /* 0x1058 */
    void* listeners;      /* 0x105C */
    char p1060[0x8];
    Rt37A9F0 rt[6];       /* 0x1068 */
} GsCtx37A9F0;

#if 0 /* merge_units */
extern void XLib_NextFrameSlave(GsCtx37A9F0*);
#endif /* merge_units */
#define XLib_NextFrameSlave(a0) (XLib_NextFrameSlave((GsCtx37A750 *)(a0))) /* merge_units */

extern void cUserFrameEnv_ReleaseVram(Rt37A9F0*);
#if 0 /* merge_units */
extern void XLib_ClearActiveBuffer(GsCtx37A9F0*, int, int, int*, int, int);
#endif /* merge_units */
#define XLib_ClearActiveBuffer(a0, a1, a2, a3, a4, a5) ((void)XLib_ClearActiveBuffer((R370 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

extern void XLib_DisplayLastFrame(GsCtx37A9F0*);
#if 0 /* merge_units */
extern void XLib_DeferDeleteDmaData(GsCtx37A9F0*, int);
#endif /* merge_units */
#define XLib_DeferDeleteDmaData(a0, a1) (XLib_DeferDeleteDmaData((GsCtx37A750 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void XLib_NextPrimFrame(GsCtx37A9F0*);
#endif /* merge_units */
void XLib_NextPrimFrame(); /* merge_units */

#if 0 /* merge_units */
extern void XLib_ClearScreen_void(GsCtx37A9F0*);
#endif /* merge_units */
#define XLib_ClearScreen_void(a0) (XLib_ClearScreen_void((R5C0 *)(a0))) /* merge_units */

extern void cAnimTexMan_NextFrame(void*, float);

#define GS_CSR (*(volatile u64*)0x12001000)
#define T0_COUNT (*(volatile int*)0x10000800)

static inline void GsCtx_SetBufferRegs_0037A9F0(GsCtx37A9F0* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((GS_CSR >> 13) & 1) << 3;
    }
    c->frame = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->dirty = 1;
}

void XLib_NextFrame(GsCtx37A9F0* c)
{
    int i;
    unsigned int t;
    if (c->flags & 8) {
        XLib_NextFrameSlave(c);
        return;
    }
    for (i = 0; i < 6; i++) {
        cUserFrameEnv_ReleaseVram(&c->rt[i]);
    }
    if (c->clear0) {
        int col[4];
        col[3] = c->clear0;
        col[0] = 0x80;
        col[1] = 0x80;
        col[2] = 0x80;
        XLib_ClearActiveBuffer(c, c->w, c->h, col, 0, 2);
    }
    if (c->clear1) {
        int col[4];
        col[3] = c->clear1;
        col[0] = 0x80;
        col[1] = 0x80;
        col[2] = 0x80;
        XLib_ClearActiveBuffer(c, c->w, c->h, col, 0, 3);
    }
    while ((*(volatile int*)0x10009000 & 0x100) || (*(volatile int*)0x10003C00 & 3) ||
           (*(volatile int*)0x10003C00 & 0x1F000000))
        ;
    while ((*(volatile int*)0x1000A000 & 0x100) || (*(volatile int*)0x10003020 & 0xC00))
        ;
    if (c->frames > 1) {
        unsigned char waited;
        c->rate = 576000.0f / (float)(int)(T0_COUNT + g_TimerAccum);
        waited = 0;
        if (c->maxRate) {
            while (576000.0f / (float)(int)(T0_COUNT + g_TimerAccum) > (float)c->maxRate) {
                waited = 1;
                GS_CSR = 8;
                while (!(GS_CSR & 8))
                    ;
            }
        }
        if ((c->clear0 || c->clear1) && !waited) {
            GS_CSR = 8;
            while (!(GS_CSR & 8))
                ;
        }
        c->dt = (float)(int)(T0_COUNT + g_TimerAccum) / 576000.0f;
        t = T0_COUNT + g_TimerAccum;
        g_TickCounter64 += (int)((float)t / 5.76f);
        T0_COUNT = 0;
        *(volatile int*)0x10000810 = 0x82;
        g_TimerAccum = 0;
        XLib_DisplayLastFrame(c);
    } else {
        t = T0_COUNT + g_TimerAccum;
        g_TickCounter64 += (int)((float)t / 5.76f);
        T0_COUNT = 0;
        *(volatile int*)0x10000810 = 0x82;
        g_TimerAccum = 0;
    }
    cTexMan_TermTextureStream(c->dev);
    cDmaMan_NextFrame(D_00537F80);
    XLib_DeferDeleteDmaData(c, 0);
    XLib_NextPrimFrame(c);
    c->buf ^= 1;
    c->frames++;
    GsCtx_SetBufferRegs_0037A9F0(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
    XLib_ClearScreen_void(c);
    cAnimTexMan_NextFrame(c->listeners, c->dt);
    cTexMan_StartFrame(c->dev);
}
#undef XLib_NextFrameSlave /* merge_units */
#undef XLib_ClearActiveBuffer /* merge_units */
#undef XLib_DeferDeleteDmaData /* merge_units */
#undef XLib_ClearScreen_void /* merge_units */
static inline void merge_flush_func_0037A9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A9F0 */

/* merge_units: begin func_0037B000 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a, b, c, d; } Q37B000;
typedef struct { char p0[0xFC4]; Q37B000 cur; char pD4[4]; Q37B000 prev; char pE8[0x10]; } H37B000;
typedef struct {
    H37B000 h; /* 0x000 */
    char pad[0x1020 - sizeof(H37B000)];
    int buf; int p1024; int count; int f102C; int f1030; int f1034; int f1038; int* arr; int f1040;
    char p1044[0xC]; int max1050; int max1054; char p1058[8]; int f1060;
} R37B000;
/* Frame flip: keeps the peaks, swaps buffers, snapshots the current quad and clears the counters. */
void XLib_NextPrimFrame(R37B000* r)
{
    int i;
    r->max1050 = r->max1050 > r->f102C ? r->max1050 : r->f102C;
    r->max1054 = r->max1054 > r->f1030 ? r->max1054 : r->f1030;
    r->buf ^= 1;
    {
        H37B000* e = (H37B000*)((char*)r + r->buf * 56);
        e->prev.a = e->cur.a; e->prev.b = e->cur.b; e->prev.c = e->cur.c; e->prev.d = e->cur.d;
    }
    r->f1040 = 0;
    r->f1034 = 0;
    r->f102C = 0;
    r->f1038 = 0;
    r->f1030 = 0;
    for (i = 0; i < r->count; i++) r->arr[i] = 0;
    r->f1060 = -1;
}
static inline void merge_flush_func_0037B000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037B000 */
