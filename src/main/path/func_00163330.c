#include "types.h"
typedef struct { int n; int a[64]; } FA_00163330;
extern int D_0048A000;
static inline void fill_00163330(FA_00163330 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void func_00163330(FA_00163330 *s, unsigned int n, int *v) {
    if (n < 65U) {
        fill_00163330(s, n, v);
        return;
    }
    fill_00163330(s, 64, &D_0048A000);
}