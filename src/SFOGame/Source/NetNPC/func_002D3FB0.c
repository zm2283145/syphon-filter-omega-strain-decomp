#include "types.h"
typedef struct { char pad[8]; int id; } Ref3FB0;
typedef struct { char pad[0x1E0]; Ref3FB0* target; } Obj3FB0;
extern void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cNetNPC_GetTargetGobj(Obj3FB0* o)
{
    Ref3FB0* r = o->target;
    void* res = 0;
    if (r) {
        int id = r->id;
        res = nGobjManager_LookupGOBJ_cObjectIdR(&id);
    }
    return res;
}