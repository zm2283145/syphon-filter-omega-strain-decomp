/*
 * Libs/SFOLib/Source/mp_vibuf: 5 files, 003F48B0-003F4B40
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

/* merge_units: begin func_003F4B40 */
#pragma push /* merge_units */
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef int u_long128 __attribute__((mode(TI)));

#define D_ENABLER ((volatile u_int *)0x1000F520)
#define D_ENABLEW ((volatile u_int *)0x1000F590)
#define D3_CHCR ((volatile u_int *)0x1000B000)
#define D3_MADR ((volatile u_int *)0x1000B010)
#define D3_QWC ((volatile u_int *)0x1000B020)
#undef D4_CHCR /* merge_units */
#define D4_CHCR ((volatile u_int *)0x1000B400)
#undef D4_MADR /* merge_units */
#define D4_MADR ((volatile u_int *)0x1000B410)
#undef D4_QWC /* merge_units */
#define D4_QWC ((volatile u_int *)0x1000B420)
#undef D4_TADR /* merge_units */
#define D4_TADR ((volatile u_int *)0x1000B430)
#define IPU_CMD ((volatile u_int *)0x10002000)
#define IPU_CTRL ((volatile u_int *)0x10002010)

typedef struct {
    u_int d4madr;
    u_int d4tadr;
    u_int d4qwc;
    u_int d4chcr;
    u_int d3madr;
    u_int d3qwc;
    u_int d3chcr;
    u_int ipubp;
    u_int ipuctrl;
} sceIpuDmaEnv;

typedef struct TimeStamp TimeStamp;

typedef struct {
    u_long128 *data;
    u_long128 *tag;
    int n;
    int dmaStart;
    int dmaN;
    int readBytes;
    int buffSize;
    sceIpuDmaEnv env;
    int sema;
    int isActive;
    long totalBytes;
    TimeStamp *ts;
    int n_ts;
    int count_ts;
    int wt_ts;
} ViBuf;

#if 0 /* merge_units */
extern void WaitSema(int sema);
#endif /* merge_units */
#define WaitSema(a0) (WaitSema((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void SignalSema(int sema);
#endif /* merge_units */
#define SignalSema(a0) (SignalSema((void *)(a0))) /* merge_units */


#define VIBUF_ELM_SIZE 2048
#define DmaAddr(val) ((u_int)(val) & 0x0FFFFFFF)
#define IsInRegion(i, s, l, n) (!(0 > ((i) + (n) - (s)) % (n) || ((i) + (n) - (s)) % (n) >= (l)))

int viBufRestartDMA(ViBuf *f)
{
    int bp;
    u_int d4madr_next;
    u_int d4qwc_next;
    u_int d4tadr_next;
    u_int d4chcr_next;

    WaitSema(f->sema);
    bp = f->env.ipubp & 0x7F;
    d4madr_next = f->env.d4madr - ((((f->env.ipubp >> 16) & 0x3) + ((f->env.ipubp >> 8) & 0xF)) << 4);
    d4qwc_next = f->env.d4qwc + (((f->env.ipubp >> 16) & 0x3) + ((f->env.ipubp >> 8) & 0xF));
    d4tadr_next = f->env.d4tadr;
    d4chcr_next = f->env.d4chcr | 0x100;

    if (d4madr_next < (u_int)f->data) {
        int id;
        d4qwc_next = ((u_int)f->data - d4madr_next) >> 4;
        d4madr_next += f->n * VIBUF_ELM_SIZE;
        d4tadr_next = DmaAddr(f->tag);
        id = (f->env.d4madr == (u_int)f->data || f->env.d4madr == (u_int)f->data + f->n * VIBUF_ELM_SIZE) ? 0 : 3;
        d4chcr_next = (DmaAddr(f->env.d4chcr) | (id << 28)) | 0x100;
        if (!IsInRegion(0, f->dmaStart, f->dmaN, f->n)) {
            f->dmaStart = f->n - 1;
            f->dmaN++;
        }
    } else {
        int ptr;
        int ptr_next;
        if (f->env.d4madr == DmaAddr(f->tag + (f->n + 1)))
            ptr = 0;
        else
            ptr = (f->env.d4madr - (u_int)f->data) / VIBUF_ELM_SIZE;
        if (d4madr_next == DmaAddr(f->tag + (f->n + 1)))
            ptr_next = 0;
        else
            ptr_next = (d4madr_next - (u_int)f->data) / VIBUF_ELM_SIZE;
        if (ptr != ptr_next) {
            int id;
            d4tadr_next = DmaAddr(f->tag + ptr);
            d4qwc_next = ((u_int)f->data + ptr * VIBUF_ELM_SIZE - d4madr_next) >> 4;
            if ((u_int)f->data + (f->env.d4madr - (u_int)f->data) % (f->n * VIBUF_ELM_SIZE)
                == (u_int)f->data + ((f->dmaStart + f->dmaN) % f->n) * VIBUF_ELM_SIZE)
                id = 0;
            else
                id = 3;
            d4chcr_next = (DmaAddr(f->env.d4chcr) | (id << 28)) | 0x100;
            if (!IsInRegion(ptr_next, f->dmaStart, f->dmaN, f->n)) {
                f->dmaStart = ptr_next;
                f->dmaN++;
            }
        }
    }

    if (f->env.d3madr && f->env.d3qwc) {
        *D3_MADR = f->env.d3madr;
        *D3_QWC = f->env.d3qwc;
        {
            u_int val = f->env.d3chcr | 0x100;
            DIntr();
            *D_ENABLEW = *D_ENABLER | 0x10000;
            *D3_CHCR = val;
            *D_ENABLEW = *D_ENABLER & ~0x10000;
            EIntr();
        }
    }
    if (f->dmaN) {
        while ((int)*IPU_CTRL < 0)
            ;
        *IPU_CMD = bp;
        while ((int)*IPU_CTRL < 0)
            ;
    }
    *D4_MADR = d4madr_next;
    *D4_TADR = d4tadr_next;
    *D4_QWC = d4qwc_next;
    if (f->dmaN) {
        DIntr();
        *D_ENABLEW = *D_ENABLER | 0x10000;
        *D4_CHCR = d4chcr_next;
        *D_ENABLEW = *D_ENABLER & ~0x10000;
        EIntr();
    }
    *IPU_CTRL = f->env.ipuctrl;
    f->isActive = 1;
    SignalSema(f->sema);
    return 1;
}
#undef WaitSema /* merge_units */
#undef SignalSema /* merge_units */
static inline void merge_flush_func_003F4B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4B40 */
