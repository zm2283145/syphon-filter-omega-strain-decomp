#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_00437490;
extern void func_00436EA0(R1Tree_00437490* t, void* n);
extern void operator_delete(void* p);
R1Tree_00437490* func_00437490(R1Tree_00437490* t, short del)
{
    if (t) {
        if (t->m4)
            func_00436EA0(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}