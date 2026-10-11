#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_00431600;
typedef struct { R1Tree_00431600 tree; } R1Own_00431600;
extern void func_00431480(R1Tree_00431600* t, short del);
extern void operator_delete(void* p);
R1Own_00431600* func_00431600(R1Own_00431600* o, short del)
{
    if (o) {
        R1Tree_00431600* t = &o->tree;
        if (t)
            func_00431480(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}