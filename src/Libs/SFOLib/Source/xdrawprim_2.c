/*
 * Libs/SFOLib/Source/xdrawprim: 2 files, 003701B0-00370550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003701B0 */
#pragma push /* merge_units */
#include "types.h"
typedef unsigned long long u64_t;
typedef struct { char pad[0xB0]; u64_t tag; u64_t regs; } Pkt;
typedef struct { u64_t a; u64_t b; } QW;
typedef struct { char pad[0x24]; Pkt* pk; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E;
typedef struct { char pad[8]; u64_t f8; char pad10[0xFA0]; E ents[1]; } Hdr;
typedef struct { char pad[8]; u64_t f8; char pad10[0x1010]; int cur; char pad1024[0xC]; int n; int pad1034; int base; int* arr; int pend; char pad1044[0x9C]; unsigned int a10E0; } S;
extern void XLib_ApplyContext(S* o, unsigned int flags);
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

void XLib_DrawLines(S* o)
{
    int b;
    int i;
    E* ep;
    QW* p;
    int m;
    int addr;
    int c;
    int f;
    int d;

    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    if (o->arr[o->n - o->base] > 0) {
        XLib_ApplyContext(o, o->a10E0 | 0x40000);
        d = 0;
        f = 0;
        ep = (E*)((char*)o + 0xFB0 + o->cur * 56);
        c = ep->aFE0;
        b = ep->aFD8;
        if (o->base == 0) return;
        {
        E* ep; int i;
        cVU1Man_NewProgBatch(D_00538080);
        cVU1Man_RequestProg(D_00538080, 1);
        ep = (E*)((char*)o + o->cur * 56 + 0xFB0);
        cDmaMan_RegisterModel(D_00537F80, D_00492F70);
        p = (QW*)cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, o->base * 4);
        for (i = 0; i < o->base; i++) {
            int k = i + (o->n - o->base);
            m = o->arr[k];
            if (m != 0) {
                ep->pk[k].tag = (long long)m | (0x8000 | ((u64_t)0x20014000 << 32));
                ep->pk[k].regs = o->f8 | 0x41;
                addr = 0;
                p = Emit(p, 0xC, addr, (int)&ep->pk[k]);
                addr += 0xC;
                p->a = DMATAG3(m, 3, b);
                p->b = (u64_t)(unsigned int)(addr | 0x8000 | (m << 16) | 0x6C000000) << 32;
                addr += m;
                b += m * 16;
                p++;
                if (c) {
                    p = Emit(p, m, addr, c);
                    c += m * 16;
                    addr += m;
                }
                if (d) {
                    p = Emit(p, m, addr, d);
                    d += m * 16;
                    addr += m;
                }
                if (f) {
                    p = Emit(p, m, addr, f);
                    f += m * 16;
                }
                p->a = 0x10000000;
                p->b = (u64_t)(unsigned int)cVU1Man_GetMSCAL(D_00538080, 1) << 32;
                p++;
            }
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p);
        }
    }
}
static inline void merge_flush_func_003701B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003701B0 */

/* merge_units: begin func_00370550 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; int f80; int f84; char pad88[0x28]; u64_t tag; u64_t regs; } Pkt_00370550;
typedef struct { char pad[0x24]; Pkt_00370550* pk; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E_00370550;
typedef struct { char pad[8]; u64_t f8; char pad10[0xFA0]; E_00370550 ents[1]; } Hdr_00370550;
typedef struct { char pad[8]; u64_t f8; char pad10[0x1010]; int cur; char pad1024[0xC]; int n; int pad1034; int base; int* arr; int pend; char pad1044[4]; int n1048; char pad104C[0x94]; unsigned int a10E0; } S_00370550;
#if 0 /* merge_units */
extern void XLib_ApplyContext(S_00370550* o, unsigned int flags);
#endif /* merge_units */
#define XLib_ApplyContext(a0, a1) (XLib_ApplyContext((S *)(a0), (a1))) /* merge_units */



#define EMIT_BODY(TAG, REGS, MC, NQ)                                                   \
    cVU1Man_NewProgBatch(D_00538080);                                                        \
    cVU1Man_RequestProg(D_00538080, MC);                                              \
    ep = (E_00370550*)((char*)o + o->cur * 56 + 0xFB0);                                        \
    for (j = 1; j < o->base; j++) {                                                   \
        int k = j + (o->n - o->base);                                                 \
        ep->pk[k].f80 = o->n1048 + o->n1048 - 1;                                      \
        ep->pk[k].f84 = o->n1048 - 1;                                                 \
    }                                                                                 \
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

static inline void Draw3_0550(S_00370550* o, E_00370550* e)
{
    int b;
    E_00370550* ep;
    int i;
    QW* p;
    int m;
    int addr;
    int c;
    int f;
    int d;
    int j;
    f = e->aFE4;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x30034000, 0x412, 2, 5)
}

static inline void Draw2_0550(S_00370550* o, E_00370550* e)
{
    int b;
    E_00370550* ep;
    int i;
    QW* p;
    int m;
    int addr;
    int c;
    int f;
    int d;
    int j;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    f = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x20034000, 0x41, 1, 4)
}

void XLib_DrawSprites2(S_00370550* o)
{
    E_00370550* e;

    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    if (o->arr[o->n - o->base] > 0) {
        XLib_ApplyContext(o, o->a10E0 | 0x40000);
        e = (E_00370550*)((char*)o + 0xFB0 + o->cur * 56);
        if (o->a10E0 & 1) {
            Draw3_0550(o, e);
        } else {
            Draw2_0550(o, e);
        }
    }
}
#undef XLib_ApplyContext /* merge_units */
static inline void merge_flush_func_00370550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370550 */
