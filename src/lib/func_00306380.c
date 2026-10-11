typedef struct { unsigned int sec; unsigned int usec; } ScfTime;
int TimeVal_ToSeconds(ScfTime *tv, unsigned int *out)
{
    int ret = 2;
    if (tv == 0) return ret;
    if (out == 0) return ret;
    *out = tv->sec;
    *out += tv->usec / 1000000;
    return 0;
}