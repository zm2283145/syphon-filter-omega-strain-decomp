#include "types.h"
typedef unsigned long u64;


#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)
#define D4_QWC       (*(volatile unsigned int*)0x1000B420)
#define D4_TADR      (*(volatile unsigned int*)0x1000B430)

typedef struct { long a; long b; int c; int d; } Slot18;
typedef struct { u64 tag; u64 pad; } DmaTag;

typedef struct IpuFeed {
    char* buf;      /* 0x00 */
    DmaTag* tags;   /* 0x04 */
    int ntags;      /* 0x08 */
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x2C];
    int unk44;
    char pad48[8];
    Slot18* slots;  /* 0x50 */
    int nslots;     /* 0x54 */
    int unk58;
    int unk5C;
} IpuFeed;

extern void DIntr(void);
extern void EIntr(void);

#define PADDR(p) ((u64)(p) & 0x0FFFFFFF)

int viBufReset(IpuFeed* f) {
    int i;
    f->unkC = 0;
    f->unk10 = 0;
    f->unk14 = 0;
    f->unk44 = 1;
    f->unk58 = 0;
    f->unk5C = 0;
    for (i = 0; i < f->nslots; i++) {
        f->slots[i].a = -1;
        f->slots[i].b = -1;
        f->slots[i].c = 0;
        f->slots[i].d = 0;
    }
    for (i = 0; i < f->ntags; i++) {
        f->tags[i].tag = (PADDR(f->buf + i * 0x800) << 32) | 0x30000080;
    }
    f->tags[i].tag = (PADDR(f->tags) << 32) | 0x20000000;
    D4_QWC = 0;
    D4_MADR = (unsigned int)f->buf & 0x0FFFFFFF;
    D4_TADR = (unsigned int)f->tags & 0x0FFFFFFF;
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    return 1;
}
