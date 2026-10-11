#include "types.h"
typedef struct { int m0; void* m4; } TD300;
extern void func_0040CD10(TD300* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a tree owner: erase the root, then delete. */
TD300* func_0040D300(TD300* t, short del)
{
    if (t) {
        if (t->m4)
            func_0040CD10(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}