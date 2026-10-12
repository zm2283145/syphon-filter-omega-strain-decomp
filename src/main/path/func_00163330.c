#include "types.h"
typedef struct { int n; int a[64]; } FA_00163330;
static const unsigned int dat_0048A000[2] = { 0x0, 0x0 };
static inline void fill_00163330(FA_00163330 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void NpcRoute_ClearRegionCandidates(FA_00163330 *s, unsigned int n, int *v) {
    if (n < 65U) {
        fill_00163330(s, n, v);
        return;
    }
    fill_00163330(s, 64, &(*(int*)dat_0048A000));
}