#define F(p, o, T) (*(T *)((char *)(p) + (o)))
extern long UInt64_Multiply(long, long);

void func_00109150(void *m, void *pic, long *pts, long *dts, long *flags)
{
    int base, n, f, odd;

    if (F(m, 0x8C, int)) {
        if (F(pic, 0x18, long) < 0 && (base = F(m, 0x98, int)) >= 0) {
            n = F(m, 0xA0, long);
            f = F(m, 0xA8, int);
            odd = (n & 1) & ((f & 1) & (F(m, 0x90, long) & 1));
            *pts = base + ((int)(UInt64_Multiply(F(m, 0x90, long), n) >> 1) + odd);
            if ((n & 1) & F(m, 0x90, long))
                F(m, 0xA8, int) = f + 1;
        } else {
            *pts = F(pic, 0x18, long);
        }
    } else {
        *pts = F(pic, 0x18, long);
    }
    if (F(m, 0x110, int) == 2 && F(m, 0x108, long) >= 0) {
        *pts = F(m, 0x108, long);
        F(m, 0x110, int) = 0;
        F(m, 0x108, long) = -1;
    }
    *dts = F(pic, 0x20, long);
    *flags = (((long)F(pic, 0x34, int) << 8 | (long)F(pic, 0x40, int) << 5)
              | ((long)F(pic, 0x30, int) << 3 | (long)F(pic, 0x38, int) << 7))
             | ((long)F(pic, 0x2C, int) | (long)F(pic, 0x3C, int) << 6);
}



