#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_00431540;
typedef struct { R1Tree_00431540 tree; } R1Own_00431540;
extern void func_004313C0(R1Tree_00431540* t, short del);
extern void operator_delete(void* p);
R1Own_00431540* func_00431540(R1Own_00431540* o, short del)
{
    if (o) {
        R1Tree_00431540* t = &o->tree;
        if (t)
            func_004313C0(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}