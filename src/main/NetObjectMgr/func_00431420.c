#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_00431420;
extern void func_0042FC50(R1Tree_00431420* t, void* n);
extern void operator_delete(void* p);
R1Tree_00431420* func_00431420(R1Tree_00431420* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042FC50(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}