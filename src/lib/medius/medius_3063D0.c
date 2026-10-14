typedef struct { unsigned int sec; unsigned int usec; } TimeD4;
int func_003063D0(TimeD4* t, unsigned int* out)
{
    if (t == 0) return 2;
    if (out == 0) return 2;
    if (t->sec > 0x418935) return 3;
    *out = t->sec * 1000 + t->usec / 1000;
    return 0;
}