#include "types.h"
extern void cArray_cCollisionEdgePtr_opAssign(void*, int);
typedef struct { int a[4]; } G6E1E;
void std_fill_n_cEdgeGroup_int_fill_n(G6E1E* p, int n, int x)
{
    while (n != 0) {
        cArray_cCollisionEdgePtr_opAssign(p, x);
        n--;
        p++;
    }
}