/*
 * Libs/SFOLib/Source/mp_vibuf: 3 files, 003F4EF0-003F5350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F4EF0 */
#pragma push /* merge_units */
#pragma opt_common_subs off

#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D3_CHCR      (*(volatile unsigned int*)0x1000B000)
#define D3_MADR      (*(volatile unsigned int*)0x1000B010)
#define D3_QWC       (*(volatile unsigned int*)0x1000B020)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)
#define D4_QWC       (*(volatile unsigned int*)0x1000B420)
#define D4_TADR      (*(volatile unsigned int*)0x1000B430)
#define IPU_CTRL     (*(volatile unsigned int*)0x10002010)
#define IPU_BP       (*(volatile unsigned int*)0x10002020)

typedef struct {
    char pad0[0x1C];
    unsigned int d4madr;
    unsigned int d4tadr;
    unsigned int d4qwc;
    unsigned int d4chcr;
    unsigned int d3madr;
    unsigned int d3qwc;
    unsigned int d3chcr;
    unsigned int ipubp;
    unsigned int ipuctrl;
    int sema;
    int active;
} IpuState;

extern void DIntr(void);
extern void EIntr(void);
extern void WaitSema(int sema);
extern void SignalSema(int sema);

int viBufStopDMA(IpuState* s)
{
    WaitSema(s->sema);
    s->active = 0;
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    s->d4madr = D4_MADR;
    s->d4tadr = D4_TADR;
    s->d4qwc = D4_QWC;
    s->d4chcr = D4_CHCR;
    while (IPU_CTRL & 0xF0)
        ;
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D3_CHCR = 0;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    s->d3madr = D3_MADR;
    s->d3qwc = D3_QWC;
    s->d3chcr = D3_CHCR;
    s->ipubp = IPU_BP;
    s->ipuctrl = IPU_CTRL;
    SignalSema(s->sema);
    return 1;
}
static inline void merge_flush_func_003F4EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4EF0 */

/* merge_units: begin func_003F5050 */
#pragma push /* merge_units */
#include "types.h"

typedef unsigned long u_long64;

typedef struct {
    u_long64 tag;
    u_long64 pad;
} DmaTag;

typedef struct {
    unsigned int base;  /* 0x00 */
    DmaTag* tags;       /* 0x04 */
    int n;              /* 0x08 */
    int head;           /* 0x0C */
    int used;           /* 0x10 */
    int bytes;          /* 0x14 */
    char pad18[0x28];
    int sema;           /* 0x40 */
    int active;         /* 0x44 */
} IpuRing;

int viBufAddDMA(IpuRing* s)
{
    unsigned int chcr;
    int started = 0;
    unsigned int madr;
    int n;
    int done;
    int tail;
    int cnt;
    int i;

    WaitSema(s->sema);
    if (!s->active) {
        SignalSema(s->sema);
        return 0;
    }
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    chcr = D4_CHCR;
    madr = D4_MADR;
    n = s->n;
    if (madr == ((unsigned int)&s->tags[n + 1] & 0x0FFFFFFF)) {
        done = 0;
    } else {
        done = (madr - s->base) >> 11;
    }
    {
        int k;
        k = (done + n - s->head) % n;
        s->head = (s->head + k) % s->n;
        s->used -= k;
    }
    tail = (s->head + s->used) % s->n;
    cnt = s->bytes / 2048;
    s->bytes = s->bytes % 2048;
    if (cnt > 0) {
        int last;
        started = 1;
        last = (s->head + s->used - 1 + s->n) % s->n;
        s->tags[last].tag = ((u_long64)(s->base + last * 2048) << 32) | 0x30000080;
    }
    for (i = 0; i < cnt; i++) {
        u_long64 addr = (u_long64)(unsigned int)(s->base + tail * 2048) << 32;
        u_long64 id = (unsigned int)(i == cnt - 1 ? 0 : 3);
        s->tags[tail].tag = addr | (id << 28) | 0x80;
        tail = (tail + 1) % s->n;
    }
    s->used += cnt;
    if (s->used != 0) {
        if (started) {
            chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        }
        DIntr();
        DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
        D4_CHCR = chcr | 0x100;
        DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
        EIntr();
    }
    SignalSema(s->sema);
    return 1;
}
static inline void merge_flush_func_003F5050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5050 */

/* merge_units: begin func_003F5350 */
#pragma push /* merge_units */
typedef struct Counter48 {
    char pad00[0x14];
    int count;          /* 0x14 */
    char pad18[0x28];
    void* lock;         /* 0x40 */
    char pad44[4];
    long long total;    /* 0x48 */
} Counter48;

#if 0 /* merge_units */
extern void WaitSema(void* lock);
#endif /* merge_units */
#define WaitSema(a0) (WaitSema((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void SignalSema(void* lock);
#endif /* merge_units */
#define SignalSema(a0) (SignalSema((int)(a0))) /* merge_units */


/* Under the lock, adds n to both counters. */
void viBufEndPut(Counter48* c, int n) {
    WaitSema(c->lock);
    c->count += n;
    c->total += n;
    SignalSema(c->lock);
}
#undef WaitSema /* merge_units */
#undef SignalSema /* merge_units */
static inline void merge_flush_func_003F5350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5350 */
