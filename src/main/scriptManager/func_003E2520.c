#include "types.h"
typedef struct { int n; int a[5000]; } FA_003E2520;
extern int D_004938E0;
static inline void fill_003E2520(FA_003E2520 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void func_003E2520(FA_003E2520 *s, unsigned int n, int *v) {
    if (n < 5001U) {
        fill_003E2520(s, n, v);
        return;
    }
    fill_003E2520(s, 5000, &D_004938E0);
}