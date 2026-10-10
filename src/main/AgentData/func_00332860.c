#include "types.h"
typedef struct { signed char a, b, c, d; } E332;
typedef struct { char pad[0xD8]; int count; E332 ent[1]; } H332;
int func_00332860(H332* h, int a, int b)
{
    int i;
    for (i = 0; i < h->count; i++) {
        E332* e = &h->ent[i];
        if (e->d == 0 && e->a == a && (b == -1 || e->b == b))
            return 1;
    }
    return 0;
}