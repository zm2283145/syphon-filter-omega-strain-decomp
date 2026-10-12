#include "types.h"
extern void SyncDCache(char* a, char* b);
typedef struct { char pad[0x54]; int v; } F_00380570;
typedef struct { int a[5]; int b[1]; int o0; int o1; } T_00380570;
void Tdx_RelocateFrames(T_00380570* t, char* base, int n1, int n2, int x, int y) {
    int i, j;
    t->o0 = (int)((int)base + (int)t->o0);
    for (i = 0; i < n1; i++) {
        t->a[i] = (int)((int)t->o0 + (int)t->a[i]);
        ((F_00380570*)t->a[i])->v += (int)t->o0 + x;
    }
    if (n2) {
        t->o1 = (int)((int)base + (int)t->o1);
        for (j = 0; j < n2; j++) {
            t->b[j] = (int)((int)t->o1 + (int)t->b[j]);
            ((F_00380570*)t->b[j])->v += (int)t->o1 + y;
        }
    } else {
        t->o1 = 0;
    }
    SyncDCache(base, base + 0x300);
}
