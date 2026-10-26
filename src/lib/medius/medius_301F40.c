typedef struct { unsigned int mt[625]; int idx; } Mt1F40;
extern Mt1F40 D_00490910;
static unsigned int D_004912D8 = 0x98765431;static unsigned int D_004912DC = 0x12345679;static unsigned int D_004912E0 = 0x13579BDF;
extern void reloadMT(void);
unsigned int randomMT(void)
{
    unsigned int a, b, c;
    if (++D_00490910.idx >= 624) reloadMT();
    a = D_004912E0 ^ D_00490910.mt[D_00490910.idx];
    b = ((D_004912D8 << 25) | (D_004912D8 >> 7)) ^ a;
    c = ((a << 7) | (a >> 25)) ^ D_004912DC;
    D_004912D8 = b;
    D_004912DC = c;
    D_004912E0 = (b & a) | (c & ~a);
    return D_004912E0;
}
