#pragma opt_common_subs off

#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D3_CHCR      (*(volatile unsigned int*)0x1000B000)
#define D3_MADR      (*(volatile unsigned int*)0x1000B010)
#define D3_QWC       (*(volatile unsigned int*)0x1000B020)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)
#define D4_QWC       (*(volatile unsigned int*)0x1000B420)
#define D4_TADR      (*(volatile unsigned int*)0x1000B430)
#define IPU_CTRL     (*(volatile unsigned int*)0x10002010)
#define IPU_BP       (*(volatile unsigned int*)0x10002020)

typedef struct {
    char pad0[0x1C];
    unsigned int d4madr;
    unsigned int d4tadr;
    unsigned int d4qwc;
    unsigned int d4chcr;
    unsigned int d3madr;
    unsigned int d3qwc;
    unsigned int d3chcr;
    unsigned int ipubp;
    unsigned int ipuctrl;
    int sema;
    int active;
} IpuState;

extern void func_001161A0(void);
extern void func_001161F8(void);
extern void func_0010D1A0(int sema);
extern void func_0010D180(int sema);

int func_003F4EF0(IpuState* s)
{
    func_0010D1A0(s->sema);
    s->active = 0;
    func_001161A0();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    func_001161F8();
    s->d4madr = D4_MADR;
    s->d4tadr = D4_TADR;
    s->d4qwc = D4_QWC;
    s->d4chcr = D4_CHCR;
    while (IPU_CTRL & 0xF0)
        ;
    func_001161A0();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D3_CHCR = 0;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    func_001161F8();
    s->d3madr = D3_MADR;
    s->d3qwc = D3_QWC;
    s->d3chcr = D3_CHCR;
    s->ipubp = IPU_BP;
    s->ipuctrl = IPU_CTRL;
    func_0010D180(s->sema);
    return 1;
}
