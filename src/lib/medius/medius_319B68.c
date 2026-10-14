#include "types.h"
typedef struct { float re; float im; } C319B68;
void func_00319B68(C319B68* a, C319B68* tab, int idx, C319B68* out)
{
    C319B68* b = &tab[idx];
    float d = b->re * b->re + b->im * b->im;
    d = 1.0f / d;
    out->re = d * (a->re * b->re - a->im * b->im);
    out->im = d * (a->im * b->re + a->re * b->im);
}