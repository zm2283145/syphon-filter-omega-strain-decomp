typedef int u_long128 __attribute__((mode(TI)));
#define REG(a) (*(volatile unsigned int *)(a))
#define REGI(a) (*(volatile int *)(a))
#define FIFO (*(volatile u_long128 *)0x10007010)
extern void setD4_CHCR_void_2(int x);
extern volatile u_long128 D_00486110[5];
extern u_long128 D_00486160[2];

void sceIpuInit(void)
{
    setD4_CHCR_void_2(1);
    REG(0x10002010) = 0x40000000;
    while (REGI(0x10002010) < 0)
        ;
    REG(0x10002000) = 0;
    while (REGI(0x10002010) < 0)
        ;
    FIFO = D_00486110[0];
    FIFO = D_00486110[1];
    FIFO = D_00486110[2];
    FIFO = D_00486110[3];
    FIFO = D_00486110[4];
    FIFO = D_00486110[4];
    FIFO = D_00486110[4];
    FIFO = D_00486110[4];
    REG(0x10002000) = 0x50000000;
    while (REGI(0x10002010) < 0)
        ;
    REG(0x10002000) = 0x58000000;
    while (REGI(0x10002010) < 0)
        ;
    FIFO = D_00486160[0];
    FIFO = D_00486160[1];
    REG(0x10002000) = 0x60000000;
    while (REGI(0x10002010) < 0)
        ;
    REG(0x10002000) = 0x90000000;
    while (REGI(0x10002010) < 0)
        ;
    REG(0x10002010) = 0x40000000;
    while (REGI(0x10002010) < 0)
        ;
    REG(0x10002000) = 0;
    while (REGI(0x10002010) < 0)
        ;
}
