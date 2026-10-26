#include "types.h"
typedef struct { int* p; } It_183270;
typedef struct { int cap; int count; int* data; } V_183270;
void std_vector_cGOBJPtr_rbegin(It_183270* out, V_183270* v)
{
    It_183270 a;
    It_183270 b;
    a.p = v->data + v->count;
    b = a;
    out->p = b.p;
}
