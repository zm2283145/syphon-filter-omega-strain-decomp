#include "types.h"
typedef struct { int m0; void* m4; } T8D80;
extern void func_0040A9C0(T8D80* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a tree owner: erase the root, then delete. */
T8D80* func_00408D80(T8D80* t, short del)
{
    if (t) {
        if (t) {
            if (t->m4)
                func_0040A9C0(t, t->m4);
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}