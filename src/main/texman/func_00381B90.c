#include "types.h"
typedef struct { char pad[0x54]; int v; } F_00381B90;
typedef struct { F_00381B90* a[5]; F_00381B90* b[1]; int o0; int o1; } T_00381B90;
void Tdx_Unrelocate(T_00381B90* t, int base, int n1, int n2, int x, int y) {
    int i, j;
    for (i = 0; i < n1; i++) {
        t->a[i]->v -= t->o0 + x;
        t->a[i] = (F_00381B90*)((char*)t->a[i] - t->o0);
    }
    t->o0 -= base;
    if (n2) {
        for (j = 0; j < n2; j++) {
            t->b[j]->v -= t->o1 + y;
            t->b[j] = (F_00381B90*)((char*)t->b[j] - t->o1);
        }
        t->o1 -= base;
    }
}