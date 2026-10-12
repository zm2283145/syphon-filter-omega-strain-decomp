typedef unsigned char u8;
extern unsigned int D_0055CA90;
extern unsigned char D_0055D450;
extern int strlen(const char*);

int func_003FD380(const unsigned char* in, char* out, int* digit, int max)
{
    int len, n, i, d;
    if (!D_0055D450 || !D_0055CA90)
        return 0;
    if (!in || !out || !digit)
        return 0;
    len = strlen((const char*)in);
    if (len > 1) {
        n = (len - 1) / 2;
        if (n < max && (len & 1))
            goto ok;
    }
    return 0;
ok:
    for (i = 0; i < n; i++) {
        int c0 = in[0];
        u8 c1 = in[1];
        u8 hi, lo;
        unsigned int idx;
        in += 2;
        if (c0 < 0x30 || c0 > 0x34)
            return 0;
        if (c1 < 0x40)
            return 0;
        lo = c1 - 0x40;
        if (lo >= 0x3E)
            return 0;
        hi = c0 - 0x30;
        idx = lo + hi * 0x3E;
        if (idx >= D_0055CA90)
            return 0;
        *out++ = idx + 0x20;
    }
    *out = 0;
    d = *in - 0x30;
    if (d < 0 || d > 9)
        return 0;
    *digit = d;
    return 1;
}


