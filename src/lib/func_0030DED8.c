#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { int handle; } Sub;
typedef struct { char pad[0x58]; Sub* sub; } Obj;
extern void func_002F5DB0(int handle);
extern void func_002FB3C0(void* ref);

/* Releases an object and its sub-object; returns 2 on NULL, 0 otherwise. */
int func_0030DED8(Obj* obj)
{
    Obj* local = 0;
    int ret = 2;
    if (obj != 0) {
        local = obj;
        if (obj->sub != 0) {
            func_002F5DB0(obj->sub->handle);
            func_002FB3C0(&local->sub);
        }
        func_002FB3C0(&local);
        ret = 0;
    }
    return ret;
}
