#include "types.h"
typedef struct {
    char pad[0x28];
    unsigned int t0, t1;
    unsigned int n0, n1;
    unsigned int t2, t3;
    unsigned int n2, n3;
} S_002DAD10;
void func_002DAD10(S_002DAD10* s, float* a, float* b, float* c, float* d)
{
    if (s->t0 != 0) *a = ((float)s->n0 * 1600.0f) / (float)s->t0;
    else *a = 0;
    if (s->t1 != 0) *b = ((float)s->n1 * 1600.0f) / (float)s->t1;
    else *b = 0;
    if (s->t2 != 0) *c = (float)s->n2 / (float)s->t2;
    else *c = 0;
    if (s->t3 != 0) *d = (float)s->n3 / (float)s->t3;
    else *d = 0;
}