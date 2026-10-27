#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x24]; int id; unsigned char active; } Obj2110;
extern int NetReleaseObjectPrivateOwnership(int id);
void cNetHuman_Deactivate(Obj2110* o)
{
    if (NetOwner_IsMine(o->id) && NetReleaseObjectPrivateOwnership(o->id) == 0)
        o->active = 0;
}