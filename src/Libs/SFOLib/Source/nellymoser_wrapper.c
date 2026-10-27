/*
 * Libs/SFOLib/Source/nellymoser_wrapper: 6 files, 0042BA00-0042C1E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042BA00 */
#pragma push /* merge_units */
#include "types.h"

/* cNellyMoser_nmsAddBlockToBuffer: append an 8-byte entry to the first of three fixed queues (80 entries each);
 * returns the entry size, or 0 when the queue is full. */

typedef struct { int a; int b; } Item;

extern Item* D_00582628;
extern unsigned char D_00582630;
extern Item* D_00582638;
extern unsigned char D_00582640;
extern Item* D_00582648;
extern unsigned char D_00582650;

/* 8-byte copy macro, hand-written asm in the original (every branch delay slot of the function
 * stays unfilled, which MW only does when an asm block is present) */
static inline void Copy8(void* d, const void* s) { long long t; asm volatile { ld t, 0(s) } asm volatile { sd t, 0(d) } }

/* keeps the switch on the overwritten argument unfolded (retail: li a0,1 and a 3/2/1 compare chain) */
#pragma opt_propagation off
int cNellyMoser_nmsAddBlockToBuffer(int queue, Item* it)
{
    queue = 1;
    switch (queue) {
    case 1:
        if (D_00582630 <= 80) {
            Copy8(&D_00582628[D_00582630], it);
            D_00582630++;
            return 8;
        }
        return 0;
    case 2:
        if (D_00582640 <= 80) {
            Copy8(&D_00582638[D_00582640], it);
            D_00582640++;
            return 8;
        }
        return 0;
    case 3:
        if (D_00582650 <= 80) {
            Copy8(&D_00582648[D_00582650], it);
            D_00582650++;
            return 8;
        }
        return 0;
    }
    return 0;
}
static inline void merge_flush_func_0042BA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042BA00 */

/* merge_units: begin func_0042BB50 */
#pragma push /* merge_units */
#pragma inline_depth(10)
#pragma opt_propagation off
#pragma opt_common_subs off

extern int D_00582668;
extern int D_00582670;
extern int D_00582678;
extern long* D_005825D8;
extern long* D_005825F8;
extern long* D_00582618;
#if 0 /* merge_units */
extern long* D_00582628;
#endif /* merge_units */
#define D_00582628 (*(long **)&D_00582628) /* merge_units */

#if 0 /* merge_units */
extern long* D_00582638;
#endif /* merge_units */
#define D_00582638 (*(long **)&D_00582638) /* merge_units */

#if 0 /* merge_units */
extern long* D_00582648;
#endif /* merge_units */
#define D_00582648 (*(long **)&D_00582648) /* merge_units */

extern short D_005825DE;
extern short D_005825FE;
extern short D_0058261E;
extern int D_00542D48;
extern int D_00582578;
extern char* D_005825D0;
extern unsigned short D_005825D4;
int nciDecodeSase3200(int h, char** io);
void nciDecodeNeedsInputSase3200(int h, unsigned char* done);

/* inline-asm block copy (hand-written in the original) */
static inline void Copy_BB50(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

/* inline-asm doubleword move (hand-written in the original) */
static inline void Move_BB50(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
    loop:
        ld t, 0(s)
        addiu d, d, 8
        addi n, n, -1
        addiu s, s, 8
        bgtz n, loop
        sd t, -8(d)
        .set reorder
    }
}

static inline void Pop_BB50(unsigned char* cnt, int* act, long** out, long** q)
{
    if (*cnt >= 8 || *act == 1) {
        if (*cnt <= 0) {
            *act = 0;
            **out = 0;
        } else {
            *act = 1;
            {
                long* o;
                long v;
                v = **q;
                o = *out;
                *o = v;
            }
            (*cnt)--;
            Move_BB50(*q, *q + 1, 0x4F);
        }
    } else {
        **out = 0;
    }
}
int cNellyMoser_nmsMultiDecode(char* buf)
{
    int total = 0;
    unsigned char done;
    unsigned short len;
    if (D_00582630 <= 16 && !D_00582668 && D_00582640 <= 16 && !D_00582670 &&
        D_00582650 <= 16 && !D_00582678)
        return 0;
    Pop_BB50(&D_00582630, &D_00582668, &D_005825D8, &D_00582628);
    Pop_BB50(&D_00582640, &D_00582670, &D_005825F8, &D_00582638);
    Pop_BB50(&D_00582650, &D_00582678, &D_00582618, &D_00582648);
    if (!D_00582668 && !D_00582670 && !D_00582678)
        return 0;
    D_005825DE = 0;
    D_005825FE = 0;
    D_00542D48 = -1;
    D_0058261E = 0;
    for (;;) {
        if ((unsigned short)nciDecodeSase3200(D_00582578, &D_005825D0))
            return 0;
        len = D_005825D4;
        if (len) {
            Copy_BB50(buf + total, D_005825D0, len * 2);
            total += D_005825D4 * 2;
        }
        nciDecodeNeedsInputSase3200(D_00582578, &done);
        if (done)
            return total;
    }
}
#undef D_00582628 /* merge_units */
#undef D_00582638 /* merge_units */
#undef D_00582648 /* merge_units */
static inline void merge_flush_func_0042BB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042BB50 */

/* merge_units: begin func_0042BF90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc and nellymoser_wrapper.c (starts 0x0042C1E0).
 */


#if 0 /* merge_units */
extern char D_00582630;
#endif /* merge_units */
#define D_00582630 (*(char*)&D_00582630) /* merge_units */

#if 0 /* merge_units */
extern char D_00582640;
#endif /* merge_units */
#define D_00582640 (*(char*)&D_00582640) /* merge_units */

#if 0 /* merge_units */
extern char D_00582650;
#endif /* merge_units */
#define D_00582650 (*(char*)&D_00582650) /* merge_units */


/* Clears three flags and three counters. */
void func_0042BF90(void) {
    D_00582630 = 0;
    D_00582640 = 0;
    D_00582650 = 0;
    D_00582668 = 0;
    D_00582670 = 0;
    D_00582678 = 0;
}
#undef D_00582630 /* merge_units */
#undef D_00582640 /* merge_units */
#undef D_00582650 /* merge_units */
static inline void merge_flush_func_0042BF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042BF90 */

/* merge_units: begin func_0042BFD0 */
#pragma push /* merge_units */
#pragma opt_propagation off
extern short D_005825BE;
extern char D_005825C0;
extern unsigned short D_005825C2;
extern unsigned char D_005825C4;
extern char* D_005825B0;
extern unsigned char* D_005825B8;
extern int D_00582570;
void nciGetVADVoiceActivity(int h, unsigned short* out);
void nciEncodeSase3200(int h, char** io);

static inline void Copy_BFD0(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

static inline void Clear_BFD0(void* d0, int n0)
{
    int n = n0;
    int m;
    int q;
    void* d = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi m, d, 0xF
        andi q, n, 0xF
        or m, m, q
        nop
        bgtz m, bytes
        srl q, n, 4
        nop
        blez q, bytes
        nop
    quads:
        addi q, q, -1
        sq $zero, 0(d)
        bgtz q, quads
        addiu d, d, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(d)
        bgtz n, bytes
        addiu d, d, 1
    done:
        .set reorder
    }
}

int cNellyMoser_nmsEncode(char* in, char* out, char* flag)
{
    int n;
    unsigned short got;
    D_005825BE = 0;
    D_005825C0 = 0;
    D_005825C2 = 0;
    D_005825C4 = 0;
    Copy_BFD0(D_005825B0, in, 0x140);
    D_00542D48 = -1;
    nciEncodeSase3200(D_00582570, &D_005825B0);
    n = D_005825C2;
    nciGetVADVoiceActivity(D_00582570, &got);
    *flag = got != 0;
    if (got)
        Copy_BFD0(out, D_005825B8, n);
    else
        Clear_BFD0(out, n);
    if (D_005825C4 > 0)
        *D_005825B8 = D_005825B8[n];
    D_005825C2 = 0;
    return n;
}
static inline void merge_flush_func_0042BFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042BFD0 */

/* merge_units: begin func_0042C1D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after DME.cc (ends 0x0042ACD0),
 * before nellymoser_wrapper.c (starts 0x0042C1E0).
 */


void cNellyMoser_nmsDestroy(void) {
}
static inline void merge_flush_func_0042C1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042C1D0 */

/* merge_units: begin func_0042C1E0 */
#pragma push /* merge_units */
/* Codec parameters filled in by nciGetInfoSase3200. */
typedef struct NellyInfo {
    char pad00[0x3C];
    unsigned short frameSamples; /* 0x3C */
    char pad3E[0x22];
    unsigned long frameBits;     /* 0x60 */
    char pad68[0x38];
} NellyInfo;

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004BFA40[]; /* "nellymoser_wrapper.c" */
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void* memset(void* d, int c, unsigned int n);

extern int D_00582660;
extern int D_00582658;
extern int D_00582580;
extern int D_00582588;

/* Four 0x18-byte frame buffers: pcm, pcmLen, data, dataCap, dataLen, flags. */

extern unsigned short D_005825B4;
#if 0 /* merge_units */
extern char* D_005825B8;
#endif /* merge_units */
#define D_005825B8 (*(char **)&D_005825B8) /* merge_units */

extern unsigned short D_005825BC;
#if 0 /* merge_units */
extern char* D_005825D8;
#endif /* merge_units */
#define D_005825D8 (*(char **)&D_005825D8) /* merge_units */

extern unsigned short D_005825DC;
extern char D_005825E0;
extern unsigned short D_005825E2;
extern unsigned char D_005825E4;
extern char* D_005825F0;
#if 0 /* merge_units */
extern char* D_005825F8;
#endif /* merge_units */
#define D_005825F8 (*(char **)&D_005825F8) /* merge_units */

extern unsigned short D_005825FC;
extern char D_00582600;
extern unsigned short D_00582602;
extern unsigned char D_00582604;
extern char* D_00582610;
#if 0 /* merge_units */
extern char* D_00582618;
#endif /* merge_units */
#define D_00582618 (*(char **)&D_00582618) /* merge_units */

extern unsigned short D_0058261C;
extern char D_00582620;
extern unsigned short D_00582622;
extern unsigned char D_00582624;
#if 0 /* merge_units */
extern char* D_00582628;
#endif /* merge_units */
#define D_00582628 (*(char **)&D_00582628) /* merge_units */

#if 0 /* merge_units */
extern char* D_00582638;
#endif /* merge_units */
#define D_00582638 (*(char **)&D_00582638) /* merge_units */

#if 0 /* merge_units */
extern char* D_00582648;
#endif /* merge_units */
#define D_00582648 (*(char **)&D_00582648) /* merge_units */


extern void* sfo_calloc();
extern void* sfo_free();
void nciSetCallocFunction(void* fn);
void nciSetFreeFunction(void* fn);
void nciEnableVu0Optimizations(int n);
void nciGetInfoSase3200(NellyInfo* info);
void nciInitDecodeSase3200(int* h);
void nciInitEncodeSase3200(int* h);
void nciEnableVAD(int h);
void nciSetVADSilenceDuration(int h, int n);
void nciSetVADEnergyTrigLevel(int h, int n);
void nciDisableVoiceFontsSase3200(int h);

static inline void* nm_alloc(unsigned int size, int line)
{
    void* p;
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, size, D_004BFA40, line);
    if (g_ProfileLockEnabled)
        EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}

/* Initialise the Nellymoser codec wrapper once: hooks, buffers and streams. */
void cNellyMoser_nmsCreate(void)
{
    NellyInfo info;
    int n;
    if (D_00582660)
        return;
    nciSetCallocFunction(sfo_calloc);
    nciSetFreeFunction(sfo_free);
    nciEnableVu0Optimizations(1);
    memset(&D_005825B0, 0, 0x18);
    memset(&D_005825D0, 0, 0x18);
    memset(&D_005825F0, 0, 0x18);
    memset(&D_00582610, 0, 0x18);
    D_00582570 = 0;
    D_00582578 = 0;
    D_00582580 = 0;
    D_00582588 = 0;
    nciGetInfoSase3200(&info);
    n = info.frameBits >> 3;
    if (info.frameBits & 7)
        n++;
    D_005825B0 = nm_alloc(info.frameSamples * 2, 0x93);
    memset(D_005825B0, 0, info.frameSamples * 2);
    D_005825B4 = info.frameSamples;
    D_005825B8 = nm_alloc(n + 2, 0x99);
    memset(D_005825B8, 0, n + 2);
    D_005825BE = 0;
    D_005825BC = n + 2;
    D_005825C0 = 0;
    D_005825C2 = 0;
    D_005825C4 = 0;
    D_005825D0 = nm_alloc(info.frameSamples * 2, 0xA7);
    memset(D_005825D0, 0, info.frameSamples * 2);
    D_005825D8 = nm_alloc(n + 2, 0xAC);
    memset(D_005825D8, 0, n + 2);
    D_005825DE = 0;
    D_005825DC = n + 2;
    D_005825E0 = 0;
    D_005825E2 = 0;
    D_005825E4 = 0;
    D_005825F0 = D_005825D0;
    D_005825F8 = nm_alloc(n + 2, 0xBD);
    memset(D_005825F8, 0, n + 2);
    D_005825FE = 0;
    D_005825FC = n + 2;
    D_00582600 = 0;
    D_00582602 = 0;
    D_00582604 = 0;
    D_00582610 = D_005825D0;
    D_00582618 = nm_alloc(n + 2, 0xCC);
    memset(D_00582618, 0, n + 2);
    D_0058261E = 0;
    D_0058261C = n + 2;
    D_00582620 = 0;
    D_00582622 = 0;
    D_00582624 = 0;
    nciInitDecodeSase3200(&D_00582578);
    nciInitDecodeSase3200(&D_00582580);
    nciInitDecodeSase3200(&D_00582588);
    nciInitEncodeSase3200(&D_00582570);
    D_00582628 = nm_alloc(0x280, 0xDF);
    D_00582638 = nm_alloc(0x280, 0xE0);
    D_00582648 = nm_alloc(0x280, 0xE1);
    memset(D_00582628, 0, 0x280);
    memset(D_00582638, 0, 0x280);
    memset(D_00582648, 0, 0x280);
    nciEnableVAD(D_00582570);
    {
        int h = D_00582570;
        nciSetVADSilenceDuration(h, 100);
        nciSetVADEnergyTrigLevel(h, 100);
    }
    nciDisableVoiceFontsSase3200(D_00582570);
    D_00582658 = 0;
    D_00582660 = 1;
}
#undef D_005825B8 /* merge_units */
#undef D_005825D8 /* merge_units */
#undef D_005825F8 /* merge_units */
#undef D_00582618 /* merge_units */
#undef D_00582628 /* merge_units */
#undef D_00582638 /* merge_units */
#undef D_00582648 /* merge_units */
static inline void merge_flush_func_0042C1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042C1E0 */
