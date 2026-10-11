#include "types.h"
typedef struct { int m0; void* m4; } T8FB0;
extern void func_0040A380(T8FB0* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a nested tree owner: erase the root, then delete. */
T8FB0* func_00408FB0(T8FB0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_0040A380(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}