typedef struct { unsigned int sec; unsigned int usec; } ScfTime;
int func_00306440(ScfTime *tv, unsigned int *out)
{
    int ret = 2;
    if (tv == 0) return ret;
    if (out == 0) return ret;
    if (tv->sec >= 0x10C5) return 3;
    *out = tv->sec * 1000000 + tv->usec;
    return 0;
}