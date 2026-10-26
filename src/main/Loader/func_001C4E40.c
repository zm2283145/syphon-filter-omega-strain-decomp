#include "types.h"
typedef struct { int a[3]; unsigned char c; char pad[3]; } E1C4;
extern void std_vector_pod_int_opAssign(E1C4* d, E1C4* s);
void std_fill_n_cArray_int_int_fill_n(E1C4* d, int n, E1C4* s)
{
    while (n != 0) {
        std_vector_pod_int_opAssign(d, s);
        d->c = s->c;
        n--;
        d++;
    }
}