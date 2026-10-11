#include "types.h"
typedef struct { int m0; void* m4; } TD360;
typedef struct { TD360 tree; } OD360;
extern void func_0040D300(TD360* t, short del);
extern void operator_delete(void* p);
/* Deleting destructor of a tree wrapper. */
OD360* func_0040D360(OD360* o, short del)
{
    if (o) {
        TD360* t = &o->tree;
        if (t)
            func_0040D300(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}