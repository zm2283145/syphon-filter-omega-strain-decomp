extern void func_0010D210(void *);
extern int func_003260F0(void);
extern unsigned char D_004914A4;
int func_00326130(void)
{
    unsigned int c;
    int r;
    func_0010D210(&c);
    if (func_003260F0()) {
        r = D_004914A4;
    } else {
        func_0010D210(&c);
        if (((c >> 13) & 7) == 0) r = (c >> 4) & 1;
        else r = (c >> 16) & 0x1F;
    }
    return r;
}
