#include "types.h"
typedef struct { int m0; void* m4; } TCD20;
extern void func_003FC240(TCD20* t, void* n);
extern void operator_delete(void* p);
TCD20* func_003FCD20(TCD20* t, short del)
{
    if (t) {
        if (t->m4)
            func_003FC240(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
