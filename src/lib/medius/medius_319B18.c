#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { float re; float im; } Complex;

/* out = conj(table[index]) * a  (complex multiply by the conjugate of a table entry). */
void func_00319B18(Complex* a, Complex* table, int index, Complex* out)
{
    Complex* b = &table[index];
    out->re = b->re * a->re + b->im * a->im;
    out->im = -b->im * a->re + b->re * a->im;
}
