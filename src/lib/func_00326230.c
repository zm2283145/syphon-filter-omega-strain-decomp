extern void func_0010D210(void *);
extern int func_003260F0(void);
extern short D_004914A0;
int func_00326230(void)
{
    int c;
    int r;
    if (func_003260F0()) {
        r = D_004914A0;
    } else {
        func_0010D210(&c);
        r = c >> 21; if (!(((unsigned int)c >> 13) & 7)) r = 0x21C;
    }
    return r;
}
