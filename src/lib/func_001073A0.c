void func_001073A0(int *p, int shift, int n, int off, int half)
{
    int lim = 16 << shift;
    int v = *p;
    if (half) v >>= 1;
    if (n > 0) {
        v += ((n - 1) << shift) + off + 1;
        if (v >= lim) v -= lim * 2;
    } else if (n < 0) {
        v -= ((-n - 1) << shift) + off + 1;
        if (v < -lim) v += lim * 2;
    }
    *p = half ? v << 1 : v;
}
