/*
 * Libs/SFOLib/Source/mp_vibuf: 3 files, 003F53B0-003F5650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F53B0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int SignalSema(int, int, int);
int WaitSema(int);

typedef struct { int f0; char p4[4]; int f8; int fC; int f10; int f14; int f18; char p1C[36]; int f40; } PS0_003F53B0;
#pragma push

void viBufBeginPut(PS0_003F53B0 *arg0, int *arg1, int *arg2, int *arg3, char * arg4) {
    int *temp_s0;
int temp_a1;
int temp_a0;
int temp_a2;
int temp_hi;
int temp_v1;

    temp_s0 = arg4;
    WaitSema(arg0->f40);
    temp_a1 = arg0->f10;
    temp_a2 = arg0->f14;
    temp_a0 = arg0->f18;
    temp_hi = (arg0->fC + temp_a1) << 0xB; temp_hi = (temp_hi + temp_a2) % temp_a0;
    temp_v1 = (((arg0->f8 - 2) - temp_a1) << 0xB) - temp_a2;
    if ((temp_a0 - temp_hi) >= temp_v1) {
        *arg1 = arg0->f0 + temp_hi;
        *arg2 = temp_v1;
        *arg3 = 0;
        *temp_s0 = 0;
    } else {
        *arg1 = arg0->f0 + temp_hi;
        *arg2 = arg0->f18 - temp_hi;
        *arg3 = arg0->f0;
        *temp_s0 = temp_v1 - (arg0->f18 - temp_hi);
    }
    SignalSema(arg0->f40, temp_hi, temp_a2);
}
#pragma pop
static inline void merge_flush_func_003F53B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F53B0 */

/* merge_units: begin func_003F54B0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003F54B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F54B0 */

/* merge_units: begin func_003F5650 */
#pragma push /* merge_units */
/* EE kernel semaphore parameters (ee_sema_t). */
typedef struct SemaParam {
    int count;
    int maxCount;
    int initCount;
    int waitThreads;
    unsigned int attr;
    unsigned int option;
} SemaParam;

typedef struct Stream3F5 {
    int id;
    unsigned int addr;  /* low 28 bits of the address, mode 2 in the top nibble */
    int size;
    char pad[0xC];
    int sizeShifted;    /* size << 11 */
    char pad2[0x24];
    int sema;
    char pad3[4];
    long position;
    int user0;
    int user1;
} Stream3F5;

extern int CreateSema(SemaParam* param); /* CreateSema */
#if 0 /* merge_units */
extern void viBufReset(Stream3F5* self);
#endif /* merge_units */
#define viBufReset(a0) ((void)viBufReset((IpuFeed *)(a0))) /* merge_units */


/* Initializes a stream: address/size fields, a binary semaphore, then resets it. Returns 1. */
int viBufCreate(Stream3F5* self, int id, unsigned int addr, int size, int user0, int user1) {
    SemaParam param;
    self->id = id;
    self->addr = (addr & 0x0FFFFFFF) | 0x20000000;
    self->size = size;
    self->sizeShifted = size << 11;
    self->user0 = user0;
    self->user1 = user1;
    param.initCount = 1;
    param.maxCount = 1;
    self->sema = CreateSema(&param);
    viBufReset(self);
    self->position = 0;
    return 1;
}
#undef viBufReset /* merge_units */
static inline void merge_flush_func_003F5650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5650 */
