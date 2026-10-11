#include "types.h"
typedef struct { int pad0; int pad4; int bits[1]; } Bits_19D6E0;
static inline void Set_19D6E0(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
static inline void Clr_19D6E0(int* a, int bit) { a[bit/32] &= ~(1 << (bit&31)); }
void func_0019D6E0(Bits_19D6E0* b, int bit, int on)
{
    if (on) Set_19D6E0(b->bits, bit);
    else Clr_19D6E0(b->bits, bit);
}