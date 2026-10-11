#include "types.h"
typedef struct { int m0; void* m4; } TF5E0;
extern void func_0040F710(TF5E0* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a nested tree owner: erase the root, then delete. */
TF5E0* func_0040F5E0(TF5E0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_0040F710(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
