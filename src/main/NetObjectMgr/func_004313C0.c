#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_313C0;
extern void func_0042F970(R1Tree_313C0* t, void* n);
extern void operator_delete(void* p);
R1Tree_313C0* func_004313C0(R1Tree_313C0* t, short del)
{
    if (t) {
        if (t->m4)
            func_0042F970(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}