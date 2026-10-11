#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_004374F0;
typedef struct { R1Tree_004374F0 tree; } R1Own_004374F0;
extern void func_00437490(R1Tree_004374F0* t, short del);
extern void operator_delete(void* p);
R1Own_004374F0* func_004374F0(R1Own_004374F0* o, short del)
{
    if (o) {
        R1Tree_004374F0* t = &o->tree;
        if (t)
            func_00437490(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}