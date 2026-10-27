#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x3584]; void* link; } Obj1F00;
typedef struct { char pad[0x10]; void* val; } Ent1F00;
typedef struct { char pad[0x1C]; char ref[8]; int owner; unsigned char b28; unsigned char b29; char pad2[2]; int netId; } Sess1F00;
typedef struct { char pad[4]; int owner; char pad2[0x14]; Sess1F00* sess; } Hdl1F00;
extern unsigned char D_005723C8;
extern Obj1F00* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void cAimWeapon_Creation(void* ref, Obj1F00* o);
extern void cTargetInfo_Creation(Sess1F00* s, Obj1F00* o);
extern Ent1F00* cNetObj_GetNetSystem(int);
extern Ent1F00* cNetObj_AddSystem(int, void*, int);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cNetHuman_NetHumanCreationCallback(void* recv, int id)
{
    struct { int pad; int oid; Hdl1F00* h; } sl;
    if (!D_005723C8)
        D_005723C8 = 1;
    if (NetGetObject((NetOwnerHdl**)&sl.h, id) == 0) {
        Obj1F00* r;
        Sess1F00* s = sl.h->sess;
        s->b29 = 0;
        s->b28 = 0;
        s->owner = id;
        sl.oid = s->netId;
        r = nGobjManager_LookupGOBJ_cObjectIdR(&sl.oid);
        if (r) {
            Obj1F00* o = r;
            cAimWeapon_Creation(s->ref, o);
            cTargetInfo_Creation(s, o);
            o->link = s;
        } else {
            Ent1F00* e = cNetObj_GetNetSystem(s->netId);
            if (e)
                e->val = s;
            else
                cNetObj_AddSystem(s->netId, recv, 0)->val = s;
        }
    }
    D_005723C8 = 0;
}
#pragma pop




