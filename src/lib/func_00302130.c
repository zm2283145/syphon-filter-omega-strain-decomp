extern void func_003020A8(unsigned int *key);
extern void func_00301D58(unsigned int *key, int n);
static __inline__ long rd(unsigned int a) { return *(volatile unsigned int *)a; }
void func_00302130(long seed)
{
    unsigned int key[64];
    func_003020A8(key);
    key[13] = seed;
    key[14] = rd(0x10000000);
    key[15] = rd(0x10000800);
    key[16] = rd(0x10001000);
    key[17] = rd(0x10001800);
    func_00301D58(key, 0x40);
}
