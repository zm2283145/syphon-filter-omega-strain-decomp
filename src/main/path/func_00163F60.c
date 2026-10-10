#include "types.h"
typedef struct { int unk0; int items[1]; } Arr4;
static inline Iter Iter_Make(int* p) { Iter it; it.p = p; return it; }
/* Stores an iterator to the first element (at +4) into out. */
void func_00163F60(Iter* out, Arr4* a) { Iter it = Iter_Make(a->items); out->p = it.p; }
