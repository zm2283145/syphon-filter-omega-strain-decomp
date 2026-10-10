#include "types.h"
typedef struct { signed char a, b, c, d; } E3328;
typedef struct { char pad[0xD8]; int count; E3328 ent[(0xB72 - 0xDC) / 4]; char pad2[2]; unsigned char dirty; } H3328;
void func_003328D0(H3328* h, int a, int b, int c, int v)
{
    int i;
    for (i = 0; i < h->count; i++) {
        E3328* e = &h->ent[i];
        if (e->a == a && e->b == b && e->c == c) {
            if (e->d != (unsigned char)v) {
                e->d = v;
                h->dirty = 1;
            }
            return;
        }
    }
}