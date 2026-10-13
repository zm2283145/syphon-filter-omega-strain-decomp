extern void func_00322630(float *re, float *im, int n);
void func_00322518(float *src, int n, int shift, float *re, float *im)
{
    int q = n >> 2;
    int half = n >> 1;
    int m = 1 << shift;
    float *pr = re + (256 - q);
    float *pi = im + (256 - q);
    int i, cnt;
    for (i = 0; i < q; i++) {
        *pr++ = *src++;
        *pi++ = *src++;
    }
    pr = re;
    pi = im;
    cnt = (n - q * 2) >> 1;
    for (i = 0; i < cnt; i++) {
        *pr++ = *src++;
        *pi++ = *src++;
    }
    if (n != half * 2) {
        *pr++ = *src++;
        i++;
        *pi++ = 0;
    }
    for (; i < 256 - q; i++) {
        *pr++ = 0;
        *pi++ = 0;
    }
    func_00322630(re, im, m);
}
