extern void func_0010C760(int);
extern void func_0010C6E8(int);
#define R(a) (*(volatile unsigned int *)(a))
void func_0010C7D8(unsigned int *o)
{
    func_0010C760(1);
    o[0] = R(0x1000B410);
    o[1] = R(0x1000B430);
    o[2] = R(0x1000B420);
    o[3] = R(0x1000B400);
    while (R(0x10002010) & 0xF0) ;
    func_0010C6E8(0);
    o[4] = R(0x1000B010);
    o[5] = R(0x1000B020);
    o[6] = R(0x1000B000);
    o[7] = R(0x10002020);
    o[8] = R(0x10002010);
}