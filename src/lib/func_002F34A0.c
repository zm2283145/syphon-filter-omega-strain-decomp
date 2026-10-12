typedef struct { unsigned char b[0x80]; } Blk2F34A0;

extern Blk2F34A0 D_0048C780;
extern int D_00490800;
extern unsigned short D_0048C800[];

extern void func_00302088(unsigned int seed);
extern unsigned int func_00301F40(void);
extern void func_002EFE18(Blk2F34A0* b, int sum);

Blk2F34A0 func_002F34A0(void)
{
    Blk2F34A0 t = D_0048C780;
    unsigned int n;
    int sum;

    if (!D_00490800) {
        D_00490800 = 1;
        func_00302088(0x5BEF6DF9);
    }
    n = (func_00301F40() >> 5) & 0x1FFF;
    sum = 0;
    while (n) {
        sum += D_0048C800[n];
        n--;
    }
    func_002EFE18(&t, sum);
    return t;
}
