extern void func_00322FC0(float *re, float *im, int n);

void func_00323330(float *in, int n, int bits, float *re, float *im)
{
    int q = n >> 2;
    int h = n >> 1;
    int size = 1 << bits;
    float *pr = re + (256 - q);
    float *pi = im + (256 - q);
    int i, m;

    for (i = 0; i < q; i++) {
        *pr++ = *in++;
        *pi++ = *in++;
    }
    pr = re;
    pi = im;
    m = (n - q * 2) >> 1;
    for (i = 0; i < m; i++) {
        *pr++ = *in++;
        *pi++ = *in++;
    }
    if (n != h * 2) {
        *pr++ = *in++;
        *pi++ = 0;
        i++;
    }
    for (; i < 256 - q; i++) {
        *pr++ = 0;
        *pi++ = 0;
    }
    func_00322FC0(re, im, size / 2);
}
