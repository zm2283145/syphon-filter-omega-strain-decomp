#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { int handle; } Sub;
typedef struct { char pad[0x58]; Sub* sub; } Obj;
extern void rt_comm_destroy(int handle);
extern void rt_memory_free(void* ref);

/* Releases an object and its sub-object; returns 2 on NULL, 0 otherwise. */
int func_0030DED8(Obj* obj)
{
    Obj* local = 0;
    int ret = 2;
    if (obj != 0) {
        local = obj;
        if (obj->sub != 0) {
            rt_comm_destroy(obj->sub->handle);
            rt_memory_free(&local->sub);
        }
        rt_memory_free(&local);
        ret = 0;
    }
    return ret;
}
