#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_0043BA00;
extern void func_0043B410(R1Tree_0043BA00* t, void* n);
extern void operator_delete(void* p);
R1Tree_0043BA00* func_0043BA00(R1Tree_0043BA00* t, short del)
{
    if (t) {
        if (t->m4)
            func_0043B410(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}