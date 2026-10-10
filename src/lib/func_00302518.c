#include "types.h"
typedef struct { char pad[0xC]; int handle; } Obj;
extern int func_0010D170(int h);
/* Returns 2 when o is NULL, else whether func_0010D170(o->handle) returned -1. */
int func_00302518(Obj* o)
{
    int ret = 2;
    if (o != 0) {
        ret = func_0010D170(o->handle) == -1;
    }
    return ret;
}
