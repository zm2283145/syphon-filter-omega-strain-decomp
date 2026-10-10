#include "types.h"

typedef struct { void* p; } Iter4;
typedef struct { int unk0; int data[1]; } Seq;

/* Writes an iterator pointing at the sequence's data at +4 to *out. */
void func_00234090(Iter4* out, Seq* s)
{
    Iter4 it;
    Iter4 tmp;
    tmp.p = s->data;
    it = tmp;
    out->p = it.p;
}
