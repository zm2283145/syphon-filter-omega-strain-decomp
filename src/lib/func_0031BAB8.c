void func_0031BAB8(float *c, int n, float *out)
{
    for (; n > 0; n--) {
        *out++ = c[0] * c[0] + c[1] * c[1];
        c += 2;
    }
}