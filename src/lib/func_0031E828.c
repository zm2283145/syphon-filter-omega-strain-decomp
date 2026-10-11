#include "types.h"
typedef struct { float* hist; float mean; short flag; } H_0031E828;
extern void* (*D_004E1D34)(int n, int size);
int func_0031E828(H_0031E828** pp)
{
    H_0031E828* p;
    if (!pp) return 1;
    *pp = 0;
    p = D_004E1D34(1, sizeof(H_0031E828));
    if (!p) return 1;
    *pp = p;
    p->hist = D_004E1D34(33, sizeof(float));
    if (!p->hist) return 1;
    p->mean = 0;
    p->flag = 0;
    return 0;
}
