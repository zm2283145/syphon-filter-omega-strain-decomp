/*
 * Libs/SFOLib/Source/mp_vibuf: 4 files, 003F48B0-003F4AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F48B0 */
#pragma push /* merge_units */
typedef struct {
    long a;
    long b;
    int pos;
    int len;
} Req;

typedef struct {
    char pad0[8];
    int sectors;
    char padC[0x44];
    Req* reqs;
    int cap;
    int count;
    int head;
} ReqQueue;

int viBufModifyPts(ReqQueue* q, Req* r)
{
    int i;
    int size;
    int more;
    more = 1;
    i = (q->cap + (q->head - q->count)) % q->cap;
    size = q->sectors << 11;
    if (q->count > 0) {
        do {
            Req* e = &q->reqs[i];
            if (e->len == 0)
                break;
            if (r->len == 0)
                break;
            if ((int)((e->pos + size - r->pos) % size < r->len) != 0) {
                int n = r->pos + r->len - e->pos;
                n = n < e->len ? n : e->len;
                e->pos = (e->pos + n) % size;
                e->len -= n;
                if (e->len == 0) {
                    if (e->a >= 0) {
                        e->a = -1;
                        e->b = -1;
                        e->pos = 0;
                        e->len = 0;
                    }
                    {
                        int c = q->count - 1;
                        q->count = c > 0 ? c : 0;
                    }
                }
            } else {
                more = 0;
            }
            i = (i + 1) % q->cap;
        } while (more);
    }
    return 0;
}
static inline void merge_flush_func_003F48B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F48B0 */

/* merge_units: begin func_003F4A10 */
#pragma push /* merge_units */
#include "types.h"

typedef struct LockedBuf {
    char pad00[0x14];
    int size;   /* 0x14 */
    char pad18[0x28];
    void* lock; /* 0x40 */
} LockedBuf;

extern void WaitSema(void* lock);
extern void SignalSema(void* lock);

/* Under the lock, rounds the size up to a multiple of 0x800. */
void viBufFlush(LockedBuf* buf) {
    WaitSema(buf->lock);
    buf->size = (buf->size + 0x7FF) / 0x800 * 0x800;
    SignalSema(buf->lock);
}
static inline void merge_flush_func_003F4A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4A10 */

/* merge_units: begin func_003F4A60 */
#pragma push /* merge_units */
typedef struct LockedBuf_003F4A60 {
    char pad00[0x10];
    int index;  /* 0x10 */
    int base;   /* 0x14 */
    char pad18[0x28];
    void* lock; /* 0x40 */
} LockedBuf_003F4A60;

/* Under the lock, returns base + index * 0x800. */
int viBufCount(LockedBuf_003F4A60* buf) {
    int addr;
    WaitSema(buf->lock);
    addr = buf->base + (buf->index << 11);
    SignalSema(buf->lock);
    return addr;
}
static inline void merge_flush_func_003F4A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4A60 */

/* merge_units: begin func_003F4AB0 */
#pragma push /* merge_units */
/* Retail code re-materializes each register address (no common-subexpression elimination). */
#pragma opt_common_subs off

#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)
#define D4_QWC       (*(volatile unsigned int*)0x1000B420)
#define D4_TADR      (*(volatile unsigned int*)0x1000B430)

typedef struct { char pad[0x40]; int sema; } Dev40;
extern void DIntr(void); /* DI */
extern void EIntr(void); /* EI */
extern void DeleteSema(int sema);

/* Stops DMA channel 4 (with the DMAC suspended), clears its registers and signals the semaphore. */
int viBufDelete(Dev40* self)
{
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    D4_QWC = 0;
    D4_MADR = 0;
    D4_TADR = 0;
    DeleteSema(self->sema);
    return 1;
}
static inline void merge_flush_func_003F4AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4AB0 */
