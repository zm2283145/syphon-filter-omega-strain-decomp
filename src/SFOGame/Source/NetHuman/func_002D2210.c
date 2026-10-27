#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x24]; int id; } Obj2210;
unsigned char func_002D2210(Obj2210* o)
{
    return NetOwner_IsMine(o->id);
}