union double_union { double d; unsigned int i[2]; };
#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
double func_00126D68(double _x)
{
    int L;
    union double_union x, a;
    x.d = _x;
    L = (word0(x) & 0x7ff00000) - (53 - 1) * 0x100000;
    if (L > 0) {
        word0(a) = L;
        word1(a) = 0;
    } else {
        L = -L >> 20;
        if (L < 20) {
            word0(a) = 0x80000 >> L;
            word1(a) = 0;
        } else {
            word0(a) = 0;
            L -= 20;
            word1(a) = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    {
        /* asm label only (no instruction): stops delay-slot filling of the return move, as retail line notes did */
        register double r __asm__("$2") = a.d;
        __asm__ __volatile__("1:" : "+r"(r));
        return r;
    }
}