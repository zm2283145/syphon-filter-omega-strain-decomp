#include "types.h"
int func_00329930(void *, void *);
int func_003517B0(void *, void *);
typedef struct { int w[15]; } W15;
typedef struct { char p0[0xC]; unsigned char fC; char pD[3]; W15 f10; char f4C[0x10]; } E351;
static inline void asg351(E351 *d, E351 *s) { func_00329930(d, s); d->fC = s->fC; d->f10 = s->f10; func_003517B0(d->f4C, s->f4C); }
E351 *func_00351DA0(E351 *first, E351 *last, E351 *dest) {
    while (first < last) {
        --last; --dest;
        asg351(dest, last);
    }
    return dest;
}