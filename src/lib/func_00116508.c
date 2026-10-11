extern void func_0010D210(unsigned int *);
extern void func_0010D200(unsigned int *);

int func_00116508(void)
{
    unsigned int cfg[2];
    func_0010D210(&cfg[0]);
    cfg[1] = (cfg[0] & ~0xE000) | 0x2000;
    func_0010D200(&cfg[1]);
    func_0010D210(&cfg[1]);
    func_0010D200(&cfg[0]);
    return ((cfg[1] >> 13) & 7) == 0;
}