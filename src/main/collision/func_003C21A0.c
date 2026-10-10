#include "types.h"

/* Retail loads the byte fields before storing them (copy propagation off). */
#pragma opt_propagation off

typedef struct { unsigned char c[4]; } Bytes4;

/* Copies four bytes (e.g. an RGBA color) and returns the destination. */
Bytes4* func_003C21A0(Bytes4* dst, Bytes4* src)
{
    unsigned char g, b, a;
    dst->c[0] = src->c[0];
    g = src->c[1];
    b = src->c[2];
    a = src->c[3];
    dst->c[1] = g;
    dst->c[2] = b;
    dst->c[3] = a;
    return dst;
}
