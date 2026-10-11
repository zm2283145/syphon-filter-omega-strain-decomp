#include "types.h"
typedef struct { int m0; void* m4; } TCCC0;
extern void func_003FC820(TCCC0* t, void* n);
extern void operator_delete(void* p);
TCCC0* func_003FCCC0(TCCC0* t, short del)
{
    if (t) {
        if (t->m4)
            func_003FC820(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
