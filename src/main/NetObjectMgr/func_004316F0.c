#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_004316F0;
typedef struct { R1Tree_004316F0 tree; } R1Own_004316F0;
extern void func_004314E0(R1Tree_004316F0* t, short del);
extern void operator_delete(void* p);
R1Own_004316F0* func_004316F0(R1Own_004316F0* o, short del)
{
    if (o) {
        R1Tree_004316F0* t = &o->tree;
        if (t)
            func_004314E0(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}