/*
 * Libs/SFOLib/Source/xdrawprim: 3 files, 00371110-00371200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00371110 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x1030]; int n; int pad1034; int base; int* arr; int pend; } S371110;
int XLib_ValidateBatch(S371110* o)
{
    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    return o->arr[o->n - o->base] > 0;
}
static inline void merge_flush_func_00371110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371110 */

/* merge_units: begin func_00371170 */
#pragma push /* merge_units */
typedef struct { int pad[0x3F6]; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E371170;
typedef struct { char pad[0x1020]; int cur; char pad1024[0xBC]; unsigned int a10E0; } S371170;
#if 0 /* merge_units */
extern int XLib_ValidateBatch(S371170* o);
#endif /* merge_units */
#define XLib_ValidateBatch(a0) (XLib_ValidateBatch((S371110 *)(a0))) /* merge_units */

extern void XLib_ApplyContext(S371170* o, unsigned int flags);
extern void XLib_DrawDma(S371170* o, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void XLib_DrawSprites(S371170* o)
{
    if (XLib_ValidateBatch(o)) {
        E371170* e;
        XLib_ApplyContext(o, o->a10E0 | 0x40000);
        e = (E371170*)((char*)o + o->cur * 56);
        XLib_DrawDma(o, e->aFD8, e->aFE0, e->aFE4, 0, 2, 6, 0x412412, 6, 0x14);
    }
}
#undef XLib_ValidateBatch /* merge_units */
static inline void merge_flush_func_00371170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371170 */

/* merge_units: begin func_00371200 */
#pragma push /* merge_units */
typedef unsigned long long u64_t;
typedef struct { char pad[0xB0]; u64_t tag; u64_t regs; } Pkt;
typedef struct { u64_t a; u64_t b; } QW;
typedef struct { char pad[0x24]; Pkt* pk; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E;
typedef struct { char pad[8]; u64_t f8; char pad10[0xFA0]; E ents[1]; } Hdr;
typedef struct { char pad[8]; u64_t f8; char pad10[0x1010]; int cur; char pad1024[0xC]; int n; int pad1034; int base; int* arr; int pend; char pad1044[0x9C]; unsigned int a10E0; } S;
#if 0 /* merge_units */
extern void XLib_ApplyContext(S* o, unsigned int flags);
#endif /* merge_units */
#define XLib_ApplyContext(a0, a1) (XLib_ApplyContext((S371170 *)(a0), (a1))) /* merge_units */

extern char D_00538080[];
extern char D_00537F80[];
extern int D_00492F70;
extern void cVU1Man_NewProgBatch(void*);
extern void cVU1Man_RequestProg(void*, int);
extern void cDmaMan_RegisterModel(void*, int);
extern int cDmaMan_BeginChain_eDmaChannel_int(void*, unsigned char, int);
extern void cDmaMan_EndChain_int_ulongP(void*, unsigned char, void*);
extern long long DMATAG3(int a, int b, int c);
extern int cVU1Man_GetMSCAL(void* table, int index);

static inline QW* Emit(QW* p, int num, int addr, int src)
{
    p->a = DMATAG3(num, 3, src);
    p->b = (u64_t)(unsigned int)(addr | 0x8000 | (num << 16) | 0x6C000000) << 32;
    return p + 1;
}


#define EMIT_BODY(TAG, REGS, MC, NQ)                                                   \
    cVU1Man_NewProgBatch(D_00538080);                                                        \
    cVU1Man_RequestProg(D_00538080, MC);                                              \
    ep = (E*)((char*)o + o->cur * 56 + 0xFB0);                                        \
    cDmaMan_RegisterModel(D_00537F80, D_00492F70);                                            \
    p = (QW*)cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, o->base * NQ);                              \
    for (i = 0; i < o->base; i++) {                                                   \
        int k = i + (o->n - o->base);                                                 \
        m = o->arr[k];                                                                \
        if (m != 0) {                                                                 \
            ep->pk[k].tag = (long long)m | (0x8000 | ((u64_t)TAG << 32));            \
            ep->pk[k].regs = o->f8 | REGS;                                            \
            addr = 0;                                                                 \
            p = Emit(p, 0xC, addr, (int)&ep->pk[k]);                                  \
            addr += 0xC;                                                              \
            p->a = DMATAG3(m, 3, b);                                            \
            p->b = (u64_t)(unsigned int)(addr | 0x8000 | (m << 16) | 0x6C000000) << 32; \
            addr += m;                                                                \
            b += m * 16;                                                              \
            p++;                                                                      \
            if (c) {                                                                  \
                p = Emit(p, m, addr, c);                                              \
                c += m * 16;                                                          \
                addr += m;                                                            \
            }                                                                         \
            if (d) {                                                                  \
                p = Emit(p, m, addr, d);                                              \
                d += m * 16;                                                          \
                addr += m;                                                            \
            }                                                                         \
            if (f) {                                                                  \
                p = Emit(p, m, addr, f);                                              \
                f += m * 16;                                                          \
            }                                                                         \
            p->a = 0x10000000;                                                        \
            p->b = (u64_t)(unsigned int)cVU1Man_GetMSCAL(D_00538080, MC) << 32;          \
            p++;                                                                      \
        }                                                                             \
    }                                                                                 \
    cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p);

static inline void Draw3_1200(S* o, E* e)
{
    int b;
    E* ep;
    int i;
    QW* p;
    int m;
    int addr;
    int c;
    int f;
    int d;
    f = e->aFE4;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x30024000, 0x412, 2, 5)
}

static inline void Draw2_1200(S* o, E* e)
{
    int b;
    E* ep;
    int i;
    QW* p;
    int m;
    int addr;
    int c;
    int f;
    int d;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    f = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x20024000, 0x41, 1, 4)
}

void XLib_DrawStrip(S* o)
{
    E* e;

    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    if (o->arr[o->n - o->base] > 0) {
        if ((o->a10E0 & 0x400) || (o->a10E0 & 0x1000)) return;
        XLib_ApplyContext(o, o->a10E0 | 0x40000);
        e = (E*)((char*)o + 0xFB0 + o->cur * 56);
        if (o->a10E0 & 1) {
            Draw3_1200(o, e);
        } else {
            Draw2_1200(o, e);
        }
    }
}
#undef XLib_ApplyContext /* merge_units */
static inline void merge_flush_func_00371200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371200 */
