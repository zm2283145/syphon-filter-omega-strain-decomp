#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x24]; int id; unsigned char active; } Obj2110;
extern int func_002EC460(int id);
void func_002D2110(Obj2110* o)
{
    if (NetOwner_IsMine(o->id) && func_002EC460(o->id) == 0)
        o->active = 0;
}