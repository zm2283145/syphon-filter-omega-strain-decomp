#include "types.h"
typedef struct { unsigned char m; unsigned char t; unsigned char f; unsigned char p3; int v; char pad[0x18]; } Light;
typedef struct { int v; int z; } Cor;
typedef struct { Light l[256]; Cor c[1]; } Big;
typedef struct { char pad[0x4C]; int n; int nc; char* buf; char pad58[8]; char d[1]; } LightMgr;
static inline void Dma_StartToSpr(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void Dma_WaitToSpr(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
void LightMgr_CollectCoronas(LightMgr* m, int a, int b, int c)
{
    int i;
    Light* l;
    Dma_StartToSpr((int)m->buf, (int)m->d, m->n * 2);
    Dma_WaitToSpr();
    m->nc = 0;
    for (i = 0; i < m->n; i++) {
        l = (Light*)(m->buf + i * 32);
        if (!(l->m & a)) continue;
        if (b != 0xFF && !(l->t & b)) continue;
        if (!(l->f & c)) continue;
        ((Cor*)(m->buf + 0x2000))[m->nc].z = 0;
        ((Cor*)(m->buf + 0x2000))[m->nc].v = l->v;
        m->nc++;
    }
}

