#include "types.h"
typedef struct { char p[0x5C]; int f5C; } E279;
typedef struct { E279 **a; E279 **b; int p8[2]; int na; int nb; } L279;
void func_002795A0(L279 *l) {
    int i;
    int j;
    for (i = 0; i < l->na; i++) l->a[i]->f5C = 0xC0000000;
    for (j = 0; j < l->nb; j++) l->b[j]->f5C = 0xC0000000;
}
