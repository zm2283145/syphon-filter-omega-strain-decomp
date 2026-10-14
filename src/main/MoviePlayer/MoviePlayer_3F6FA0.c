/*
 * main/MoviePlayer: 23 files, 003F6FA0-003F8220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F6FA0 */
#pragma push /* merge_units */
#include "types.h"
extern unsigned char D_0055C740;
extern volatile int D_0055C210;
extern volatile int D_0055C218;
extern int sceGsSyncV(int);

void func_003F6FA0(int id)
{
    if (!D_0055C740) {
        while (sceGsSyncV(0) == id) {
        }
    }
    D_0055C210 = 1;
    D_0055C218 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F6FA0 */

/* merge_units: begin func_003F7010 */
#pragma push /* merge_units */
extern volatile int D_0055C220;
extern char D_0055C460[];
extern void func_003F5E80(void* p);
/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI3F7010(void) { asm { sync }
    asm { ei } }
#pragma push
#pragma optimization_level 3
int func_003F7010(void)
{
    if (D_0055C220) {
        func_003F5E80(D_0055C460);
        D_0055C220 = 0;
    }
    asm { .set reorder } /* scheduling barrier: keeps the beqz delay slot empty and the label padded */
    EI3F7010();
    return 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003F7010 */

/* merge_units: begin func_003F7060 */
#pragma push /* merge_units */
typedef struct { int m0; void* base; int head; int count; int size; } T5EA0;
extern volatile int D_0055C228;
extern char D_0055C230[];
extern char D_0055C290[];
extern char D_0055C380[];
#if 0 /* merge_units */
extern T5EA0 D_0055C460;
#endif /* merge_units */
#define D_0055C460 (*(T5EA0*)&D_0055C460) /* merge_units */

extern volatile int D_0055C5A8;
#if 0 /* merge_units */
extern volatile unsigned char D_0055C740;
#endif /* merge_units */
#define D_0055C740 (*(volatile unsigned char*)&D_0055C740) /* merge_units */

extern char D_00571CF0[];
extern int sceGsSyncPath(int, int);
extern void func_00103B60(unsigned long draw, short cx, short cy, short half);
extern void* func_00103D40(int);
extern void func_00104070(void* d, void* tag);
extern int* func_003F5EA0(T5EA0* q);
extern void func_00411860(void* db, int i, int j);
extern void func_001036B0(void* p, int);

/* sync + ei (enable interrupts) have no C equivalent */
static inline void EI3F7060(void) { asm { sync }
    asm { ei } }

#pragma opt_propagation off
int MoviePlayer_PresentVblank(void)
{
    volatile int field;
    volatile int r;
    field = (int)((*(volatile unsigned long*)0x12001000 >> 13) & 1);
    if (D_0055C210) {
        D_0055C218++;
        r = sceGsSyncPath(1, 0);
        if (r == 0) {
            int* buf = func_003F5EA0(&D_0055C460);
            unsigned long dma;
            T5EA0* q;
            void* d;
            int idx;
            if (!buf) {
                EI3F7060();
                return 0;
            }
            if (D_0055C740) {
                field = D_0055C228;
                D_0055C228 ^= 1;
            }
            if (field & 1)
                dma = ((unsigned long)D_0055C380 & 0x0FFFFFFF) | 0x20000000;
            else {
                unsigned long a = (unsigned long)D_0055C290;
                dma = (a & 0x0FFFFFFF) | 0x20000000;
            }
            if (!D_0055C740)
                func_00103B60(dma, 0x800, 0x800, field ^ 1);
            d = func_00103D40(2);
            q = &D_0055C460;
            { int h = q->head; idx = (q->size + (h - q->count)) % q->size; }
            if (field == 0 && *buf == 2) {
                func_00411860(D_00571CF0, idx, 0);
                func_001036B0(D_0055C230, 0);
                sceGsSyncPath(0, 0);
                func_00104070(d, (char*)buf + 0x40);
                *buf = 1;
            } else if (field == 1 && *buf == 1) {
                func_00411860(D_00571CF0, idx, 1);
                func_001036B0(D_0055C230, 1);
                sceGsSyncPath(0, 0);
                func_00104070(d, (char*)buf + 0x26740);
                *buf = 0;
                D_0055C220 = 1;
            }
        }
        D_0055C5A8++;
    }
    EI3F7060();
    return 0;
}
#undef D_0055C460 /* merge_units */
#undef D_0055C740 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F7060 */

/* merge_units: begin func_003F72D0 */
#pragma push /* merge_units */
typedef unsigned long u_long64;
typedef unsigned int u_int;
typedef __int128 u_long128;
typedef struct { u_long128 q; } GTag;
typedef struct { u_long128* cur; int a; int b; int c; } VifPk;
extern int D_0053820C;
extern int D_00538210;
extern GTag D_004939F0;
extern GTag D_00493A00;
extern void func_00104430(VifPk* pk, u_int base);
extern void func_00104440(VifPk* pk);
extern void func_001044A8(VifPk* pk, int a, int b, int c);
extern void func_001045B8(VifPk* pk, int a, int b, int c);
extern void func_00104648(VifPk* pk, u_long128 tag);
extern void func_00104708(VifPk* pk, int reg, u_long64 data);
extern void func_00104660(VifPk* pk);
extern u_long64* func_00104630(VifPk* pk, int n);
extern void func_00104520(VifPk* pk, u_int addr, int size, int a, int b, int c);
extern void func_00104450(VifPk* pk);
u_long128* func_003F72D0(void* buf, u_long128* tex, int skip, int w, int h)
{
    GTag tagA;
    GTag tagB;
    VifPk pk;
    int tw;
    int th;
    u_long128* ret;
    int x1, y1, x0, y0, dx, dy;
    tw = D_0053820C;
    th = D_00538210;
    tagA = D_004939F0;
    tagB = D_00493A00;
    func_00104430(&pk, ((u_int)buf & 0x0FFFFFFF) | 0x20000000);
    func_00104440(&pk);
    if (!skip) {
        int i, j;
        int nx, ny;
        func_001044A8(&pk, 0, 0, 0);
        func_00104648(&pk, tagA.q);
        func_00104708(&pk, 0x50, ((u_long64)(((tw + 63) & ~63) * ((th + 31) & ~31) * sizeof(short) / 64) << 32) | ((u_long64)12 << 48));
        func_00104708(&pk, 0x52, (u_long64)16 | ((u_long64)16 << 32));
        func_00104660(&pk);
        nx = w >> 4;
        ny = h >> 4;
        for (i = 0; i < nx; i++) {
            for (j = 0; j < ny; j++) {
                u_long64* p;
                func_001044A8(&pk, 0, 0, 0);
                func_00104648(&pk, tagA.q);
                func_00104708(&pk, 0x51, ((u_long64)(u_int)(i * 16) << 32) | ((u_long64)(u_int)(j * 16) << 48));
                func_00104708(&pk, 0x53, 0);
                func_00104660(&pk);
                p = func_00104630(&pk, 4);
                p[0] = 0x40 | ((u_long64)2 << 58);
                p[1] = 0;
                func_00104520(&pk, (u_int)tex & 0x0FFFFFFF, 0x40, 0, 0, 0);
                tex += 0x40;
            }
        }
    }
    y1 = h << 4;
    x1 = w << 4;
    if (D_0055C740) {
        x0 = 0x6C00; y0 = 0x7100; dx = 0x2800; dy = 0x1E00;
    } else {
        x0 = 0x6C00; y0 = 0x7880; dx = 0x2800; dy = 0xF00;
    }
    func_001045B8(&pk, 0, 0, 0);
    ret = pk.cur - 1;
    func_00104648(&pk, tagB.q);
    func_00104708(&pk, 0x3F, 0);
    func_00104708(&pk, 0x14, 0x60);
    func_00104708(&pk, 0x06, (u_long64)(((tw + 63) & ~63) * ((th + 31) & ~31) * sizeof(short) / 64) | ((u_long64)12 << 14) | ((u_long64)10 << 26) | ((u_long64)10 << 30) | ((u_long64)1 << 35));
    func_00104708(&pk, 0x00, 0x116);
    func_00104708(&pk, 0x03, 0x80008);
    func_00104708(&pk, 0x05, (u_long64)x0 | ((u_long64)y0 << 16));
    func_00104708(&pk, 0x03, (u_long64)(x1 + 8) | ((u_long64)(y1 + 8) << 16));
    func_00104708(&pk, 0x05, (u_long64)(x0 + dx) | ((u_long64)(y0 + dy) << 16));
    func_00104660(&pk);
    func_00104450(&pk);
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F72D0 */

/* merge_units: begin func_003F76C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x50004]; int count; } T76C0;
int func_003F76C0(T76C0* t, int n)
{
    int k = t->count < n ? t->count : n;
    t->count -= k;
    return k;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F76C0 */

/* merge_units: begin func_003F7710 */
#pragma push /* merge_units */
typedef struct { char data[0x50000]; int head; int count; int size; } T7710;
int func_003F7710(T7710* t, char** out)
{
    int c = t->count;
    if (c)
        *out = t->data + (t->size + (t->head - c)) % t->size;
    return t->count;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7710 */

/* merge_units: begin func_003F7770 */
#pragma push /* merge_units */
typedef struct { char data[0x50000]; int head; int count; int size; } T7770;
int func_003F7770(T7770* t, int n)
{
    int size = t->size;
    int k = size - t->count < n ? size - t->count : n;
    t->head = (t->head + k) % size;
    t->count += k;
    return k;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7770 */

/* merge_units: begin func_003F77F0 */
#pragma push /* merge_units */
typedef struct { char data[0x50000]; int head; int count; int size; } T77F0;
int func_003F77F0(T77F0* t, char** out)
{
    int f = t->size - t->count;
    if (f)
        *out = t->data + t->head;
    return f;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F77F0 */

/* merge_units: begin func_003F7830 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003F7830(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7830 */

/* merge_units: begin func_003F7840 */
#pragma push /* merge_units */
typedef struct { char pad[0x50000]; int unk50000; int unk50004; int capacity; } BigBuf;

/* Resets the large buffer's counters and sets its capacity to 0x50000. */
void func_003F7840(BigBuf* self)
{
    self->unk50004 = 0;
    self->unk50000 = 0;
    self->capacity = 0x50000;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7840 */

/* merge_units: begin func_003F7870 */
#pragma push /* merge_units */
typedef struct { unsigned char volume; unsigned char a; unsigned char b; } PlayParams;
typedef struct { int unk0; int active; char pad[8]; int cursor; } Stream3F7;
extern void Cd_Read(int pos, int blocks, void* data, PlayParams* params);
extern void Cd_Sync(int a);

/* Submits size bytes (in 2 KB blocks) of data to the active stream and advances its cursor; returns size or 0. */
int func_003F7870(Stream3F7* s, void* data, int size)
{
    int result = 0;
    if (s->active) {
        PlayParams params;
        int blocks;
        params.volume = 100;
        params.a = 0;
        params.b = 0;
        blocks = size >> 11;
        Cd_Read(s->cursor, blocks, data, &params);
        s->cursor += blocks;
        Cd_Sync(0);
        result = size;
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7870 */

/* merge_units: begin func_003F78F0 */
#pragma push /* merge_units */
typedef struct { unsigned char active; char pad1[3]; int f4; int pad8; void* handle; int pad10; char sub[4]; } S78F0;
extern void func_00114558(void* h);
extern void func_0036DEC0(void* p);
int func_003F78F0(S78F0* s) {
    if (s->active) {
        if (s->f4 && s->handle) {
            func_00114558(s->handle);
            s->handle = 0;
        }
        func_0036DEC0(s->sub);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F78F0 */

/* merge_units: begin func_003F7950 */
#pragma push /* merge_units */
typedef struct FileInfo {
    unsigned char ok;
    char pad[3];
    int open;
    int size;
    int buffer;
    int handle;
    char file[4];
} FileInfo;

extern void func_0036DFB0(void* file, char* name, char* src);
extern int func_0036DEF0(void* file);
extern int FileMan_GetSize(void* file);
extern int func_001143F0(int size);
extern int func_0036DDC0(void* file);

/* Opens the file named at src+4 and caches its size/buffer/handle; returns success. */
unsigned char func_003F7950(FileInfo* self, char* src) {
    func_0036DFB0(self->file, src + 4, src);
    self->ok = (unsigned char)func_0036DEF0(self->file) == 0;
    if (self->ok) {
        self->size = FileMan_GetSize(self->file);
        self->open = 1;
        self->buffer = func_001143F0(0x40010);
        self->handle = func_0036DDC0(self->file);
    } else {
        self->open = 0;
        self->buffer = 0;
        self->size = 0;
        self->handle = 0;
    }
    return self->ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7950 */

/* merge_units: begin func_003F79F0 */
#pragma push /* merge_units */
extern unsigned char D_005382C0;
void FlushCache(int a);
static inline void Kick_3F79F0(void* tag, int qwc)
{
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
    *(volatile int*)0x1000A020 = qwc;
    *(volatile int*)0x1000E010 = 4;
    if (((unsigned int)tag & 0x70000000) == 0x70000000) {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag | 0x80000000;
    } else {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag;
        FlushCache(0);
    }
    asm volatile ("sync");
    *(volatile int*)0x1000A000 = 0x181;
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
}void func_003F79F0(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned long* p = (unsigned long*)0x70000000;
    *p++ = 0x8009 | ((unsigned long)0x10000000 << 32);
    *p++ = 0xE;
    *p++ = 1;
    *p++ = 0x1A;
    *p++ = 0x100000;
    *p++ = 0x4C;
    *p++ = 0;
    *p++ = 0x18;
    *p++ = 0x04000000 | ((unsigned long)0x04000000 << 32);
    *p++ = 0x40;
    *p++ = 0;
    *p++ = 0x47;
    *p++ = 6;
    *p++ = 0;
    *p++ = (unsigned long)r | ((unsigned long)g << 8) | ((unsigned long)b << 16) | ((unsigned long)a << 24) | ((unsigned long)0x3F800000 << 32);
    *p++ = 1;
    *p++ = 0;
    *p++ = 4;
    *p++ = 0x40004000;
    *p++ = 4;
    Kick_3F79F0((void*)0x70000000, 0xA);
    D_005382C0 = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F79F0 */

/* merge_units: begin func_003F7BD0 */
#pragma push /* merge_units */
typedef unsigned int u32;
extern char D_0055C540;
void func_003F6BE0(void* q, char** p1, int* n1, char** p2, int* n2);
void func_003F6B00(void* q, int n);
void* memcpy(void* d, const void* s, unsigned int n);

struct Hdr_F7BD0 {
    int pad0;
    int pad4;
    char* pos;
    int size;
};

int func_003F7BD0(void* self, struct Hdr_F7BD0* h, char* ring)
{
    char* p1;
    char* p2;
    int n1;
    int n2;
    int len;
    int rest;
    int cap;
    char* src;
    int total;
    int a;
    int second;
    char* d1;
    char* d2;
    int first;
    char* end;

    src = h->pos + 4;
    cap = *(int*)(ring + 0x50008);
    end = ring + cap;
    if (src >= end) {
        src -= cap;
    }
    first = end - src;
    len = h->size - 4;
    first = (first < len) ? first : len;
    second = len - first;
    func_003F6BE0(&D_0055C540, &p1, &n1, &p2, &n2);
    {
        a = n1;
        d2 = p2;
        d1 = p1;
        total = first + second;
        if (a + n2 < total) {
            total = 0;
        } else if (first >= a) {
            memcpy(d1, src, a);
            memcpy(d2, src + a, first - a);
            memcpy(d2 + first - a, ring, second);
        } else {
            rest = a - first;
            if (second >= rest) {
                memcpy(d1, src, first);
                memcpy(d1 + first, ring, rest);
                memcpy(d2, ring + a - first, second - rest);
            } else {
                memcpy(d1, src, first);
                memcpy(d1 + first, ring, second);
            }
        }
    }
    func_003F6B00(&D_0055C540, total);
    return total > 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7BD0 */

/* merge_units: begin func_003F7D90 */
#pragma push /* merge_units */
typedef unsigned long u64_7D90;
typedef struct { char pad[8]; char* src; unsigned int len; long f10; long f18; } Pkt_7D90;
typedef struct { char data[0x50008]; int end; } Ring_7D90;
extern char D_0055C480[];
extern void func_003F5D50(void* s, int* a, int* sz, int* b, int* bsz);
extern void func_003F5C90(void* s, long a, long b, int c, int n);
extern void func_003F5D40(void* s, int n);
extern void* memcpy(void* d, const void* s, unsigned int n);
int func_003F7D90(void* self, Pkt_7D90* p, Ring_7D90* r)
{
    int sz;
    unsigned int n1;
    int n2;
    char* d1;
    int total;
    char* src;
    char* d2;
    unsigned int len;
    int a, b, asz, bsz;
    src = p->src;
    len = p->len;
    n1 = (unsigned int)((char*)r + r->end - src);
    n1 = n1 < len ? n1 : len;
    n2 = len - n1;
    func_003F5D50(D_0055C480, &a, &asz, &b, &bsz);
    total = n1 + n2;
    sz = asz;
    d1 = (char*)(((unsigned int)a & 0x0FFFFFFF) | 0x20000000);
    d2 = (char*)(((unsigned int)b & 0x0FFFFFFF) | 0x20000000);
    if (sz + bsz < total) {
        total = 0;
    } else if ((int)n1 >= sz) {
        memcpy(d1, src, sz);
        memcpy(d2, src + sz, n1 - sz);
        memcpy(d2 + n1 - sz, r, n2);
    } else {
        int rest = sz - n1;
        if (n2 >= rest) {
            memcpy(d1, src, n1);
            memcpy(d1 + n1, r, rest);
            memcpy(d2, (char*)r + sz - n1, n2 - rest);
        } else {
            memcpy(d1, src, n1);
            memcpy(d1 + n1, r, n2);
        }
    }
    if (total > 0)
        func_003F5C90(D_0055C480, p->f10, p->f18, a, total);
    func_003F5D40(D_0055C480, total);
    return total > 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7D90 */

/* merge_units: begin func_003F7F80 */
#pragma push /* merge_units */
extern void func_0010D010(int code);

/* Never returns: repeatedly calls func_0010D010(5) (halt/exit loop). */
void func_003F7F80(void) {
    for (;;) {
        func_0010D010(5);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7F80 */

/* merge_units: begin func_003F7FA0 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern int D_0055C748;

void func_003F7FA0(int value) {
    D_0055C748 = value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7FA0 */

/* merge_units: begin func_003F7FB0 */
#pragma push /* merge_units */
extern int D_0055C750;
/* Set a global setting if it is in range 1..6. */
void func_003F7FB0(int value)
{
    if (value > 0 && value < 7) {
        D_0055C750 = value;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7FB0 */

/* merge_units: begin func_003F7FD0 */
#pragma push /* merge_units */
extern int D_0055C5B0;
extern int D_0055C5B8;

void func_003F7FD0(int a, int b) {
    D_0055C5B0 = a;
    D_0055C5B8 = b;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7FD0 */

/* merge_units: begin func_003F7FF0 */
#pragma push /* merge_units */
extern void func_0010D010();
void func_003F7FF0(void)
{
    func_0010D010(5);
}
#pragma pop /* merge_units */
/* merge_units: end func_003F7FF0 */

/* merge_units: begin func_003F8000 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x188];
    int f188;
    int f18C;
    char p190[0xA0];
    unsigned char f230;
    unsigned char f231;
    unsigned char f232;
    unsigned char f233;
    unsigned char f234;
    unsigned char f235;
    unsigned char f236;
} Ply3F8000;
typedef struct { char pad[8]; int f8; } Hdr3F8000;
typedef struct { char pad[0x50008]; int f50008; } Buf3F8000;
#if 0 /* merge_units */
extern char D_0055C540[];
#endif /* merge_units */
#define D_0055C540 ((char*)&D_0055C540) /* merge_units */

int func_0010A3B0(Hdr3F8000* h, int p, int n, Buf3F8000* b, int x);
#if 0 /* merge_units */
void func_0010D010(int n);
#endif /* merge_units */
#define func_0010D010(a0) (func_0010D010((a0))) /* merge_units */

void func_003F5CD0(char* p, int n);
void func_003F5CF0(char* p);
int func_003F6000(char* p);
void func_003F6A20(char* p);
int func_003F6A90(char* p);
void func_003F6D20(char* p);
void func_003F6DC0(char* p);
void func_003F6E60(char* p);
void func_003F6F90(void);
#if 0 /* merge_units */
void func_003F6FA0(int n);
#endif /* merge_units */
#define func_003F6FA0(a0) (func_003F6FA0((a0))) /* merge_units */

#if 0 /* merge_units */
void func_003F76C0(Buf3F8000* b, int n);
#endif /* merge_units */
#define func_003F76C0(a0, a1) ((void)func_003F76C0((T76C0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int func_003F7710(Buf3F8000* b, int* out);
#endif /* merge_units */
#define func_003F7710(a0, a1) (func_003F7710((T7710 *)(a0), (char * *)(a1))) /* merge_units */

#if 0 /* merge_units */
void func_003F7770(Buf3F8000* b, int n);
#endif /* merge_units */
#define func_003F7770(a0, a1) ((void)func_003F7770((T7770 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int func_003F77F0(Buf3F8000* b, int* out);
#endif /* merge_units */
#define func_003F77F0(a0, a1) (func_003F77F0((T77F0 *)(a0), (char * *)(a1))) /* merge_units */

#if 0 /* merge_units */
int func_003F7870(void* s, int p, int n);
#endif /* merge_units */
#define func_003F7870(a0, a1, a2) (func_003F7870((Stream3F7 *)(a0), (void *)(a1), (a2))) /* merge_units */

void func_003F8000(Ply3F8000* self, Hdr3F8000* hdr, Buf3F8000* buf, void* strm)
{
    int p1;
    int p2;
    int n;
    if (self->f18C > 0x800) {
        if (hdr->f8 > 10) {
            if (self->f232) {
                func_003F6F90();
                if (self->f236) func_003F6E60(D_0055C540);
                self->f232 = 0;
                self->f231 = 1;
            }
            if (self->f233) {
                func_003F6FA0(1);
                if (self->f236) func_003F6DC0(D_0055C540);
                self->f233 = 0;
                self->f231 = 0;
            }
            if (self->f235) func_003F5CF0(D_0055C480);
        }
        n = func_003F77F0(buf, &p1);
        if (self->f188 > 0 && n >= 0x10000) {
            n = func_003F7870(strm, p1, 0x10000);
            func_003F7770(buf, n);
            self->f188 -= n;
        }
        func_0010D010(5);
        n = func_003F7710(buf, &p2);
        if (n > 0) {
            n = func_0010A3B0(hdr, p2, n, buf, buf->f50008);
            func_003F76C0(buf, n);
            self->f18C -= n;
        }
        func_003F6A20(D_0055C540);
        if (!self->f230 && func_003F6000(D_0055C460)) {
            int ok = self->f236 ? func_003F6A90(D_0055C540) : 1;
            if (ok) {
                func_003F6FA0(1);
                if (self->f236) func_003F6D20(D_0055C540);
                self->f230 = 1;
            }
        }
    } else {
        func_003F5CD0(D_0055C480, 3);
    }
}
#undef D_0055C540 /* merge_units */
#undef func_0010D010 /* merge_units */
#undef func_003F6FA0 /* merge_units */
#undef func_003F76C0 /* merge_units */
#undef func_003F7710 /* merge_units */
#undef func_003F7770 /* merge_units */
#undef func_003F77F0 /* merge_units */
#undef func_003F7870 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F8000 */

/* merge_units: begin func_003F8220 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Sys3F82 {
    char pad00[0x30];
    int f30;
    char pad34[0x24];
    char part58[0x1D9];
    bool f231;
    char pad232[2];
    bool f234;
    bool done;
    bool f236;
} Sys3F82;
#if 0 /* merge_units */
extern char D_0055C540[];
#endif /* merge_units */
#define D_0055C540 ((char*)&D_0055C540) /* merge_units */

extern "C" {
extern void MovieSubtitles_Update(void* p);
extern int func_003F5CE0(void* p);
#if 0 /* merge_units */
extern void func_003F8000(Sys3F82* s, void* r, int a, void* b);
#endif /* merge_units */
#define func_003F8000(a0, a1, a2, a3) (func_003F8000((Ply3F8000 *)(a0), (Hdr3F8000 *)(a1), (Buf3F8000 *)(a2), (a3))) /* merge_units */

extern bool func_003F5AE0(void* p);
extern bool func_003F5A80(void* p);
#if 0 /* merge_units */
extern void func_0010D010(int n);
#endif /* merge_units */
#define func_0010D010(a0) (func_0010D010((a0))) /* merge_units */

extern void func_003F6F90(void);
extern void func_003F6CD0(void* p);
extern void func_003F8390(Sys3F82* s);
extern void func_003F8450(Sys3F82* s);
bool MoviePlayer_Update(Sys3F82* s);
}

bool MoviePlayer_Update(Sys3F82* s)
{
    MovieSubtitles_Update(D_00571CF0);
    if (!s->done) {
        if (s->f234) {
            s->done = 1;
        }
        if (func_003F5CE0(D_0055C480) != 3) {
            func_003F8000(s, D_0055C480, s->f30, s->part58);
        } else if (!s->f231) {
            s->done = 1;
        }
        if (s->done) {
            while (!func_003F5AE0(D_0055C480)) {
                func_0010D010(5);
            }
            while (!func_003F5A80(D_0055C480) && func_003F5CE0(D_0055C480) != 3) {
                func_0010D010(5);
            }
            func_003F6F90();
            if (s->f236) {
                func_003F6CD0(D_0055C540);
            }
        }
        if (s->f234) {
            func_003F8390(s);
            func_003F8450(s);
            s->f234 = 0;
            s->done = 0;
        }
    }
    return !s->done;
}
#undef D_0055C540 /* merge_units */
#undef func_003F8000 /* merge_units */
#undef func_0010D010 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F8220 */
