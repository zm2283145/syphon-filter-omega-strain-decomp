#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_004314E0;
extern void func_00430210(R1Tree_004314E0* t, void* n);
extern void operator_delete(void* p);
R1Tree_004314E0* func_004314E0(R1Tree_004314E0* t, short del)
{
    if (t) {
        if (t->m4)
            func_00430210(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}