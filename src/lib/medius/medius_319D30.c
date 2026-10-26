void SymWindowSignal(float *in, float *win, float *out, int n)
{
    int i = n >> 1;
    float *ie = in + n - 1;
    float *oe = out + n - 1;
    while (i-- > 0) {
        *out++ = *in++ * *win;
        *oe-- = *ie-- * *win++;
    }
    if (n & 1) *out = *in * *win;
}