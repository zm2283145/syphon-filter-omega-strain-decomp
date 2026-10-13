#include "types.h"
typedef struct { char pad[0xC]; int handle; } Obj;
extern int DeleteSema(int h);
/* Returns 2 when o is NULL, else whether DeleteSema(o->handle) returned -1. */
int func_00302518(Obj* o)
{
    int ret = 2;
    if (o != 0) {
        ret = DeleteSema(o->handle) == -1;
    }
    return ret;
}
