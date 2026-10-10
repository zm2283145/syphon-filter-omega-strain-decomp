#include "types.h"
static inline Iter Iter_Make(int* p) { Iter it; it.p = p; return it; }
/* Stores an iterator to the end of the vector into out. */
void func_0040BC10(Iter* out, PtrVec* v) { Iter it = Iter_Make(v->data + v->count); out->p = it.p; }
