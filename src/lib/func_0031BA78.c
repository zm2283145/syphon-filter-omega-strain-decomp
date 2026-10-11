void func_0031BA78(float *re, float *im, int n, float *out)
{
    for (; n > 0; n--) {
        *out++ = *re * *re + *im * *im;
        re++;
        im++;
    }
}