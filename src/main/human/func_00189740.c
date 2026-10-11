#include "types.h"
typedef struct { int pad0; int cur[2]; int dirty[2]; } Bits_189740;
static inline int Get_189740(int* a, int bit) { return (a[bit/32] >> (bit&31)) & 1; }
static inline void Set_189740(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
void AnimPriority_Helper0(Bits_189740* b, int bit, unsigned char on) { if (on != (Get_189740(b->cur, bit) != 0)) Set_189740(b->dirty, bit); }
