extern void setD4_CHCR_void(int);
extern void setD3_CHCR(int);
#define R(a) (*(volatile unsigned int *)(a))
void sceIpuStopDMA(unsigned int *o)
{
    setD4_CHCR_void(1);
    o[0] = R(0x1000B410);
    o[1] = R(0x1000B430);
    o[2] = R(0x1000B420);
    o[3] = R(0x1000B400);
    while (R(0x10002010) & 0xF0) ;
    setD3_CHCR(0);
    o[4] = R(0x1000B010);
    o[5] = R(0x1000B020);
    o[6] = R(0x1000B000);
    o[7] = R(0x10002020);
    o[8] = R(0x10002010);
}