#include "types.h"
typedef struct { int m0; void* m4; } R1Tree_0043BA60;
typedef struct { R1Tree_0043BA60 tree; } R1Own_0043BA60;
extern void func_0043BA00(R1Tree_0043BA60* t, short del);
extern void operator_delete(void* p);
R1Own_0043BA60* func_0043BA60(R1Own_0043BA60* o, short del)
{
    if (o) {
        R1Tree_0043BA60* t = &o->tree;
        if (t)
            func_0043BA00(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}