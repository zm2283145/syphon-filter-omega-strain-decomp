#include "types.h"
typedef struct { char pad[0x24]; void* h; unsigned char done; } Obj1D80;
extern int func_002EC3C8(void* h);
void func_002D1D80(Obj1D80* o)
{
    if (!o->done && func_002EC3C8(o->h) == 0)
        o->done = 1;
}