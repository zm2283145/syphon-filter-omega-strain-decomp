#include "types.h"


#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)

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

extern void DIntr(void);
extern void EIntr(void);
extern void WaitSema(int sema);
extern void SignalSema(int sema);

int func_003F5050(IpuRing* s)
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




