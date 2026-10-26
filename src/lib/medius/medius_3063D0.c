typedef struct { unsigned int sec; unsigned int usec; } TimeD4;
int rt_time_timestamp_to_msecs(TimeD4* t, unsigned int* out)
{
    if (t == 0) return 2;
    if (out == 0) return 2;
    if (t->sec > 0x418935) return 3;
    *out = t->sec * 1000 + t->usec / 1000;
    return 0;
}