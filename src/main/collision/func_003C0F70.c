#include "types.h"
typedef struct { unsigned char b0, b1, b2, type; char pad[0x14]; int m18; } H0F70;
typedef struct { H0F70* h; } P20F70;
typedef struct { int m0; P20F70* q; } P10F70;
typedef struct { int idx; P10F70* p; } T0F70;
extern char* func_00183B20(H0F70* h, int* x);
char* func_003C0F70(T0F70* t)
{
    int i = t->idx;
    H0F70* h = t->p->q->h;
    if (h->type < 4) {
        int x = h->m18;
        return func_00183B20(h, &x) + i * 64;
    } else if (h->type < 5) {
        int x = h->m18;
        return func_00183B20(h, &x) + i * 32;
    } else {
        int x = h->m18;
        return func_00183B20(h, &x) + i * 16;
    }
}
