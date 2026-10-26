#include "types.h"
typedef struct { int n; int a[2]; } FA13A;
void cArray_FixedCapacity_cGOBJPtr_2_ResizeActual(FA13A *s, unsigned int n, int *v) {
    int i;
    if (n < 3U) {
        for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
        s->n = n;
        return;
    }
    for (i = s->n; i <= 1; i++) *(int *)((char *)s->a + (i << 2)) = 0;
    s->n = 2;
}