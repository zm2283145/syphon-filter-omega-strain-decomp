#include "types.h"
typedef unsigned long long u64_t;
typedef struct { char pad[0x80]; int f80; int f84; char pad88[0x28]; u64_t tag; u64_t regs; } Pkt;
typedef struct { u64_t a; u64_t b; } QW;
typedef struct { char pad[0x24]; Pkt* pk; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E;
typedef struct { char pad[8]; u64_t f8; char pad10[0xFA0]; E ents[1]; } Hdr;
typedef struct { char pad[8]; u64_t f8; char pad10[0x1010]; int cur; char pad1024[0xC]; int n; int pad1034; int base; int* arr; int pend; char pad1044[4]; int n1048; char pad104C[0x94]; unsigned int a10E0; } S;
extern void Renderer_SetReceiverConsts(S* o, unsigned int flags);
extern char D_00538080[];
extern char D_00537F80[];
extern int D_00492F70;
extern void func_003701A0(void*);
extern void Vu1_UploadMicrocode(void*, int);
extern void func_00370110(void*, int);
extern int func_00375B40(void*, unsigned char, int);
extern void DmaPacket_Close(void*, unsigned char, void*);
extern long long func_003700F0(int a, int b, int c);
extern int func_003700D0(void* table, int index);

static inline QW* Emit(QW* p, int num, int addr, int src)
{
    p->a = func_003700F0(num, 3, src);
    p->b = (u64_t)(unsigned int)(addr | 0x8000 | (num << 16) | 0x6C000000) << 32;
    return p + 1;
}


#define EMIT_BODY(TAG, REGS, MC, NQ)                                                   \
    func_003701A0(D_00538080);                                                        \
    Vu1_UploadMicrocode(D_00538080, MC);                                              \
    ep = (E*)((char*)o + o->cur * 56 + 0xFB0);                                        \
    for (j = 1; j < o->base; j++) {                                                   \
        int k = j + (o->n - o->base);                                                 \
        ep->pk[k].f80 = o->n1048 + o->n1048 - 1;                                      \
        ep->pk[k].f84 = o->n1048 - 1;                                                 \
    }                                                                                 \
    func_00370110(D_00537F80, D_00492F70);                                            \
    p = (QW*)func_00375B40(D_00537F80, 1, o->base * NQ);                              \
    for (i = 0; i < o->base; i++) {                                                   \
        int k = i + (o->n - o->base);                                                 \
        m = o->arr[k];                                                                \
        if (m != 0) {                                                                 \
            ep->pk[k].tag = (long long)m | (0x8000 | ((u64_t)TAG << 32));            \
            ep->pk[k].regs = o->f8 | REGS;                                            \
            addr = 0;                                                                 \
            p = Emit(p, 0xC, addr, (int)&ep->pk[k]);                                  \
            addr += 0xC;                                                              \
            p->a = func_003700F0(m, 3, b);                                            \
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
            p->b = (u64_t)(unsigned int)func_003700D0(D_00538080, MC) << 32;          \
            p++;                                                                      \
        }                                                                             \
    }                                                                                 \
    DmaPacket_Close(D_00537F80, 1, p);

static inline void Draw3_0550(S* o, E* e)
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
    int j;
    f = e->aFE4;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x30034000, 0x412, 2, 5)
}

static inline void Draw2_0550(S* o, E* e)
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
    int j;
    c = e->aFE0;
    b = e->aFD8;
    d = 0;
    f = 0;
    if (o->base == 0) return;
    EMIT_BODY(0x20034000, 0x41, 1, 4)
}

void Renderer_FlushPrimitives(S* o)
{
    E* e;

    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    if (o->arr[o->n - o->base] > 0) {
        Renderer_SetReceiverConsts(o, o->a10E0 | 0x40000);
        e = (E*)((char*)o + 0xFB0 + o->cur * 56);
        if (o->a10E0 & 1) {
            Draw3_0550(o, e);
        } else {
            Draw2_0550(o, e);
        }
    }
}
