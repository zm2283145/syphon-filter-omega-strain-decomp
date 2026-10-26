/*
 * main/MoviePlayer: 13 files, 003F6630-003F6F90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F6630 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* src; void* dest; int size; int attr; } Dma3F6630;
extern "C" {
void FlushCache(int);
int sceSifSetDma(Dma3F6630*, int);
}
static inline void Send3F6630(void* src, void* dest, int size)
{
    Dma3F6630 t;
    FlushCache(0);
    t.src = src;
    t.dest = dest;
    t.size = size;
    t.attr = 0;
    while (sceSifSetDma(&t, 1) == 0) {
    }
}
extern "C" int sendToIOP2area(void* self, char* dst, int len, char* dst2, int len2, char* src, int n1, char* src2, int n2)
{
    if (len + len2 < n1 + n2) {
        int over = (n1 + n2) - (len + len2);
        if (over >= n2) {
            n1 -= over - n2;
            n2 = 0;
        } else {
            n2 -= over;
        }
    }
    if (n1 >= len) {
        int r;
        if (len > 0) Send3F6630(src, dst, len);
        r = n1 - len;
        if (r > 0) Send3F6630(src + len, dst2, r);
        if (n2 > 0) Send3F6630(src2, dst2 + n1 - len, n2);
    } else {
        int r = len - n1;
        if (n2 >= r) {
            int r2;
            if (n1 > 0) Send3F6630(src, dst, n1);
            if (r > 0) Send3F6630(src2, dst + n1, r);
            r2 = n2 - r;
            if (r2 > 0) Send3F6630(src2 + len - n1, dst2, r2);
        } else {
            if (n1 > 0) Send3F6630(src, dst, n1);
            if (n2 > 0) Send3F6630(src2, dst + n1, n2);
        }
    }
    return n1 + n2;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6630 */

/* merge_units: begin func_003F6940 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x48]; int base; int size; char pad2[8]; int off; } T6940;
void func_003F6940(int* p1, int* n1, int* p2, int* n2, T6940* t, int x)
{
    int r;
    int d;
    int size = t->size;
    int off = t->off;
    r = (x + size - off - 0x400) % size;
    d = x - off;
    if (d >= 0 && d < 0x400) {
        *p1 = t->base;
        *n1 = 0;
        *p2 = t->base;
        *n2 = 0;
        return;
    }
    r = (r / 1024) * 1024;
    if (!(size - off < r)) {
        *p1 = t->base + off;
        *n1 = r;
        *p2 = 0;
        *n2 = 0;
    } else {
        *p1 = t->base + off;
        *n1 = t->size - t->off;
        *p2 = t->base;
        *n2 = r - (t->size - t->off);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6940 */

/* merge_units: begin func_003F6A20 */
#pragma push /* merge_units */
extern int func_003F6180(int, int);
extern int func_003F6480(int);

void func_003F6A20(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = *(int*)(char*)a0;
    cond = v1 == 0;
    if (cond) goto L003F6A78;
    a1 = *(unsigned char*)((char*)a0 + 4);
    v1 = 0 + 4;
    cond = a1 == v1;
    v1 = 0 + 2;
    if (cond) goto L003F6A78;
    cond = a1 != v1;
    if (cond) goto L003F6A60;
    v0 = func_003F6480(a0);
    goto L003F6A78;
L003F6A60:;
    v1 = 0 + 3;
    cond = a1 != v1;
    if (cond) goto L003F6A78;
    v0 = func_003F6180(a0, a1);
L003F6A78:;
    goto ret;
ret:;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6A20 */

/* merge_units: begin func_003F6A90 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003F6A90(char * arg0) {
    unsigned char temp_v1;

    temp_v1 = F_(arg0, 0x4, unsigned char);
    switch (temp_v1) {                              
    case 4:
    case 2:
        return F_(arg0, 0x50, int) >= F_(arg0, 0x4C, int);
    case 3:
        return (F_(arg0, 0x50, int) >= 0x1000) & 0xFF;
    default:
        return 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6A90 */

/* merge_units: begin func_003F6B00 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char kind; char pad[0x2B]; unsigned int m30; int m34; int m38; int m3C; int m40; int m44; } T6B00;
void audioDecEndPut(T6B00* t, int n)
{
    if (t->state == 0) {
        if (t->kind != 4) {
            unsigned int k = 0x28 - t->m30;
            if (n < k)
                k = n;
            t->m30 += k;
            if (!(t->m30 < 0x28))
                t->state = 1;
            n -= k;
        } else {
            t->state = 1;
        }
    }
    if (t->kind == 3)
        t->m40 = (t->m40 / 256) * 256;
    t->m38 = (t->m38 + n) % t->m40;
    t->m3C += n;
    t->m44 += n;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6B00 */

/* merge_units: begin func_003F6BE0 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char kind; char pad[3]; char buf[0x28]; int m30; int m34; int m38; int m3C; int m40; } T6BE0;
void audioDecBeginPut(T6BE0* t, int* p1, int* n1, int* p2, int* n2)
{
    if (t->state == 0) {
        if (t->kind != 4) {
            *p1 = (int)(t->m30 + (int)t + 8);
            *n1 = 0x28 - t->m30;
            *p2 = t->m34;
            *n2 = t->m40;
        } else {
            *p1 = t->m34;
            *n1 = t->m40;
            *p2 = 0;
            *n2 = 0;
        }
    } else {
        int len;
        int size = t->m40;
        int pos;
        len = size - t->m3C;
        pos = t->m38;
        if (!(size - pos < len)) {
            *p1 = t->m34 + pos;
            *n1 = len;
            *p2 = 0;
            *n2 = 0;
        } else {
            *p1 = t->m34 + pos;
            *n1 = t->m40 - t->m38;
            *p2 = t->m34;
            *n2 = len - (t->m40 - t->m38);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6BE0 */

/* merge_units: begin func_003F6CD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int snd_ResetMovieSound(void);

void audioDecReset(Unk3F6CD0* self) {
    snd_ResetMovieSound();
    self->unk00 = 0;
    self->unk30 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk44 = 0;
    self->unk50 = 0;
    self->unk58 = 0;
    self->unk5C = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6CD0 */

/* merge_units: begin func_003F6D20 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char mode; char p5[0xF]; int f14; int f18; char p1C[0x2C]; char* buf; int pos; char p50[0xC]; int size; } S3F6D20;
extern void snd_StartMovieSoundEx(char* buf, int pos, char* end, unsigned int a, int b);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void audioDecStart(S3F6D20* s)
{
    if (s->mode != 3) {
        char* b = s->buf;
        snd_StartMovieSoundEx(b, s->pos / 1024 * 1024, b + s->size, 0, 0);
    } else {
        snd_StartMovieSoundEx(s->buf, s->pos / 1024 * 1024, (char*)s->size, s->f14, s->f18);
    }
    s->state = 2;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003F6D20 */

/* merge_units: begin func_003F6DC0 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char mode; char p5[0xF]; int f14; int f18; char p1C[0x2C]; char* buf; int pos; char p50[0xC]; int size; } S3F6DC0;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void audioDecResume(S3F6DC0* s)
{
    if (s->mode != 3) {
        char* b = s->buf;
        snd_StartMovieSoundEx(b, s->pos / 1024 * 1024, b + s->size, 0, 0);
    } else {
        snd_StartMovieSoundEx(s->buf, s->pos / 1024 * 1024, (char*)s->size, s->f14, s->f18);
    }
    s->state = 2;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003F6DC0 */

/* merge_units: begin func_003F6E60 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char mode; char pad[0x43]; int offset; char pad2[0x10]; int time; } Timer3F6;

extern int snd_PauseMovieSound(Timer3F6* self);

/* Resets the timer state and computes its time, minus the offset unless in mode 3. */
void audioDecPause(Timer3F6* self)
{
    self->state = 3;
    self->time = snd_PauseMovieSound(self);
    if (self->mode != 3)
        self->time -= self->offset;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6E60 */

/* merge_units: begin func_003F6EB0 */
#pragma push /* merge_units */
extern int snd_CloseMovieSound(void);

int audioDecDelete(void) {
    snd_CloseMovieSound();
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6EB0 */

/* merge_units: begin func_003F6ED0 */
#pragma push /* merge_units */
typedef struct { int state; unsigned char kind; char pad[0x2B]; unsigned int m30; int m34; int m38; int m3C; int m40; int m44; int m48; int m4C; int m50; int m54; int m58; int m5C; } T6ED0;
extern int snd_InitMovieSoundEx(int size, int a, int b, int c, int d, int kind);
int func_003F6ED0(T6ED0* t, int a, int b, unsigned char kind)
{
    t->state = 0;
    t->kind = kind;
    t->m30 = 0;
    t->m34 = a;
    t->m38 = 0;
    t->m3C = 0;
    t->m40 = b;
    t->m44 = 0;
    t->m50 = 0;
    t->m58 = 0;
    t->m5C = 0;
    t->m58 = 0;
    t->m5C = 0;
    if (kind == 2)
        t->m4C = 0x6000;
    else if (kind == 3)
        t->m4C = 0x400;
    else
        t->m4C = 0xC000;
    t->m48 = snd_InitMovieSoundEx(t->m4C, 0x1000, 0x400, 0, 2, t->kind);
    return t->m48 >= 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6ED0 */

/* merge_units: begin func_003F6F90 */
#pragma push /* merge_units */
extern int D_0055C210;

void endDisplay(void) {
    D_0055C210 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6F90 */
