#include "types.h"
extern void* Ptr_Identity(void* p);
extern void* func_0013B0D0(void* p);
extern void* func_0013B0C0(void* p);

typedef struct Hit13B {
    Q m[3];                 /* 0x00 */
    Q t;                    /* 0x30 */
    unsigned char b[0x10];  /* 0x40 */
    unsigned char f, g, h;  /* 0x50 */
    char pad53[0xD];
    int ip[2];              /* 0x60 */
    char pad68[8];
} Hit13B;

typedef struct R13B {
    unsigned char status;   /* 0x00 */
    Q point;                /* 0x10 */
    Hit13B hit;             /* 0x20 */
    int unk90;              /* 0x90 */
} R13B;

extern Hit13B* func_0013B0E0(Hit13B* d, Hit13B* s);

/* lq/sq quad copy halves (128-bit GPR load/store; no C equivalent) */
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=&r"(q) : "r"(s) : "memory"); return q; }
static inline void GS(void* d, __int128 q) { __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(d) : "memory"); }
R13B* func_0013B010(R13B* d, R13B* s)
{
    Hit13B* h;
    Q* p;

    {
        Q* dp = &d->point;
        d->status = s->status;
        GS(dp, GL(&s->point));
    }
    h = &d->hit;
    p = h->m;
    do {
        Ptr_Identity(p);
        p++;
    } while (p != &h->m[3]);
    Ptr_Identity(&h->t);
    func_0013B0D0(h->b);
    func_0013B0C0(h->ip);
    func_0013B0E0(h, &s->hit);
    d->unk90 = s->unk90;
    return d;
}



