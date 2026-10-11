#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_00431480;
extern void func_0042FF30(R1Tree_00431480* t, void* n);
extern void operator_delete(void* p);
R1Tree_00431480* func_00431480(R1Tree_00431480* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042FF30(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}