#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_004315A0;
typedef struct { R1Tree_004315A0 tree; } R1Own_004315A0;
extern void func_00431420(R1Tree_004315A0* t, short del);
extern void operator_delete(void* p);
R1Own_004315A0* func_004315A0(R1Own_004315A0* o, short del)
{
    if (o) {
        R1Tree_004315A0* t = &o->tree;
        if (t)
            func_00431420(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}