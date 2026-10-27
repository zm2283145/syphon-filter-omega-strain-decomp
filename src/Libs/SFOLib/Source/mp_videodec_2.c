/*
 * Libs/SFOLib/Source/mp_videodec: 7 files, 003F57E0-003F5D00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F57E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char* base; char* y; int pad8; int padC; int count; } MovieBufs;
typedef struct { int a; int b; int stopped; char pad[0xA8 - 0xC]; int state; } MovieCtx;
typedef struct { int y; int uv; } Frame;
extern "C" {
int sceMpegIsEnd(MovieCtx*);
void sceMpegReset(MovieCtx*);
void sceMpegGetPicture(MovieCtx*, int, int);
void printf(char*);
int voBufGetData(MovieBufs*);
void voBufIncCount(MovieBufs*);
int setImageTag(char*, char*, int, int, int);
void cMoviePlayer_SetMovieDims(int, int);
void cMoviePlayer_SwitchThread(void);
void cMovieSubtitles_GraftDma(char*, int, int, int, int);
void cMovieSubtitles_Render(char*);
void cMovieSubtitles_FirstFrame(char*);
}
extern char D_004BE1C0[];
extern MovieBufs D_0055C460;
extern int D_0055C5A8;
extern char D_00571CF0[];

extern "C" int decBs0(MovieCtx* self)
{
    int ret = 1;
    Frame f[2];
    while (!sceMpegIsEnd(self)) {
        int buf;
        if (self->state == 1) {
            ret = -1;
            printf(D_004BE1C0);
            break;
        }
        while (!(buf = voBufGetData(&D_0055C460)))
            cMoviePlayer_SwitchThread();
        sceMpegGetPicture(self, buf, 0x654);
        if (self->stopped == 0) {
            int a = self->a;
            int b = self->b;
            int i;
            for (i = 0; i < D_0055C460.count; i++) {
                f[i].y = setImageTag(D_0055C460.y + i * 0x4CE40 + 0x40, D_0055C460.base + i * 0x195000, 0, a, b);
                f[i].uv = setImageTag(D_0055C460.y + i * 0x4CE40 + 0x26740, D_0055C460.base + i * 0x195000, 1, a, b);
            }
            cMoviePlayer_SetMovieDims(a, b);
            D_0055C5A8 = 0;
            cMovieSubtitles_GraftDma(D_00571CF0, f[0].y, f[0].uv, f[1].y, f[1].uv);
            cMovieSubtitles_FirstFrame(D_00571CF0);
        }
        cMovieSubtitles_Render(D_00571CF0);
        voBufIncCount(&D_0055C460);
        cMoviePlayer_SwitchThread();
    }
    sceMpegReset(self);
    return ret;
}
static inline void merge_flush_func_003F57E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F57E0 */

/* merge_units: begin func_003F5A10 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; char x48[0x60]; int xA8; } G3S_003F5A10;
extern void viBufReset(void* p);
extern void voBufReset(void* p);
#if 0 /* merge_units */
extern void decBs0(G3S_003F5A10* s);
#endif /* merge_units */
#define decBs0(a0) ((void)decBs0((MovieCtx *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char D_0055C460[];
#endif /* merge_units */
#define D_0055C460 ((char*)&D_0055C460) /* merge_units */

extern volatile int D_0055C46C;
void videoDecMain(G3S_003F5A10* s) {
    viBufReset(s->x48);
    voBufReset(D_0055C460);
    decBs0(s);
    while (D_0055C46C) {
    }
    s->xA8 = 3;
}
#undef decBs0 /* merge_units */
#undef D_0055C460 /* merge_units */
static inline void merge_flush_func_003F5A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5A10 */

/* merge_units: begin func_003F5A80 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; int m48; } T5A80;
extern int viBufCount(void* p);
extern int sceMpegIsRefBuffEmpty(T5A80* t);
unsigned char videoDecIsFlushed(T5A80* t)
{
    unsigned char r = 0;
    if (!viBufCount(&t->m48)) {
        if (sceMpegIsRefBuffEmpty(t))
            r = 1;
    }
    return (unsigned char)(r & 0xFF);
}
static inline void merge_flush_func_003F5A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5A80 */

/* merge_units: begin func_003F5AE0 */
#pragma push /* merge_units */
typedef struct Ring3F5 {
    char pad[0x48];
    char ring[0x60]; /* 0x48 */
    int state;       /* 0xA8 */
} Ring3F5;

extern void viBufBeginPut(void* ring, unsigned int* p1, int* n1, unsigned int* p2, int* n2);
extern void viBufEndPut(void* ring, int n);
extern void viBufFlush(void* ring);
extern void* memcpy(void* d, const void* s, unsigned int n);
typedef struct { float f; } F4; extern F4 D_004939E8;

static inline int Ring_Write2(void* ring, char* d1, int n1, char* d2, int n2,
                              const char* a, int alen, const char* b, int blen)
{
    int written;
    if (n1 + n2 < alen + blen) {
        written = 0;
    } else {
        if (n1 <= alen) {
            memcpy(d1, a, n1);
            memcpy(d2, a + n1, alen - n1);
            memcpy(d2 + alen - n1, b, blen);
        } else if (!(blen < n1 - alen)) {
            memcpy(d1, a, alen);
            memcpy(d1 + alen, b, n1 - alen);
            memcpy(d2, b + n1 - alen, blen - (n1 - alen));
        } else {
            memcpy(d1, a, alen);
            memcpy(d1 + alen, b, blen);
        }
        written = alen + blen;
    }
    viBufEndPut(ring, written);
    return written;
}

int videoDecFlush(Ring3F5* self)
{
    unsigned int p1;
    unsigned int p2;
    F4 val;
    int n1;
    int n2;
    char* d1;
    char* d2;

    val = D_004939E8;
    viBufBeginPut(self->ring, &p1, &n1, &p2, &n2);
    if (n1 + n2 < 4) {
        return 0;
    }
    d1 = (char*)((p1 & 0x0FFFFFFF) | 0x20000000);
    d2 = (char*)((p2 & 0x0FFFFFFF) | 0x20000000);
    Ring_Write2(self->ring, d1, n1, d2, n2, (const char*)&val, 4, 0, 0);
    viBufFlush(self->ring);
    if (self->state == 0) {
        self->state = 2;
    }
    return 1;
}
static inline void merge_flush_func_003F5AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5AE0 */

/* merge_units: begin func_003F5C90 */
#pragma push /* merge_units */
typedef struct { long a; long b; int rel; int extra; } Req;
extern void viBufPutTs(void* list, Req* req);

typedef struct { char pad[0x48]; int base; } Obj;

/* Builds a request (offset relative to +0x48) and submits it. */
void videoDecPutTs(Obj* self, long a, long b, int pos, int extra)
{
    Req req;
    req.a = a;
    req.b = b;
    req.rel = pos - self->base;
    req.extra = extra;
    viBufPutTs(&self->base, &req);
}
static inline void merge_flush_func_003F5C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5C90 */

/* merge_units: begin func_003F5CD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

/* Swaps in a new value and returns the old one. */
int videoDecSetState(Unk3F5CD0* self, int value) {
    int old = self->unkA8;

    self->unkA8 = value;
    return old;
}

int videoDecGetState(Unk3F5CD0* self) {
    return self->unkA8;
}

void videoDecAbort(Unk3F5CD0* self) {
    self->unkA8 = 1;
}
static inline void merge_flush_func_003F5CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5CD0 */

/* merge_units: begin func_003F5D00 */
#pragma push /* merge_units */
extern void viBufDelete(void* member);
extern void sceMpegDelete(void* self);

/* Releases the member at +0x48, then the object itself; returns 1. */
int videoDecDelete(char* self) {
    viBufDelete(self + 0x48);
    sceMpegDelete(self);
    return 1;
}
static inline void merge_flush_func_003F5D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5D00 */
