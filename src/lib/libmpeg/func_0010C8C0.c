#define R(a) (*(volatile unsigned int *)(a))
typedef struct { int x0; int x4; int x8; unsigned int xC; int x10; int x14; unsigned int x18; unsigned int x1C; } IpuStateC8C0;
extern void setD3_CHCR(unsigned int);
extern void setD4_CHCR_void(unsigned int);
void sceIpuRestartDMA(IpuStateC8C0 *p)
{
    unsigned int cmd = p->x1C & 0x7F;
    unsigned int n = ((p->x1C >> 16) & 3) + ((p->x1C >> 8) & 0xF);
    int madr = p->x0 - n * 16;
    int qwc = p->x8 + n;
    if (p->x10 && p->x14) {
        R(0x1000B010) = p->x10;
        R(0x1000B020) = p->x14;
        setD3_CHCR(p->x18 | 0x100);
    }
    while ((int)R(0x10002010) < 0)
        ;
    R(0x10002000) = cmd;
    while ((int)R(0x10002010) < 0)
        ;
    if (madr && qwc) {
        R(0x1000B410) = madr;
        R(0x1000B430) = p->x4;
        R(0x1000B420) = qwc;
        setD4_CHCR_void(p->xC | 0x100);
    }
}

