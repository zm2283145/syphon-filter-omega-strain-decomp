#include "types.h"
typedef struct { char pad[0x24]; void* h; unsigned char done; } Obj1D80;
extern int NetRequestObjectPrivateOwnership(void* h);
void cNetHuman_Activate(Obj1D80* o)
{
    if (!o->done && NetRequestObjectPrivateOwnership(o->h) == 0)
        o->done = 1;
}