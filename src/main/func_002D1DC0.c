#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x3584]; void* link; } Obj1DC0;
typedef struct { char pad[0x1C]; char ref[8]; int owner; unsigned char b28; unsigned char b29; char pad2[2]; int netId; } Sess1DC0;
typedef struct { char pad[4]; int owner; char pad2[0x14]; Sess1DC0* sess; } Hdl1DC0;
extern unsigned char D_005723C8;
extern unsigned char D_0051F080;
extern Obj1DC0* Object_LookupById(int* id);
extern void func_002C4EA0(void* ref, Obj1DC0* o);
extern void func_00316980(Sess1DC0* s, Obj1DC0* o);
#pragma push
#pragma opt_common_subs off
void func_002D1DC0(void* recv, int id, int kind)
{
    struct { int pad; int oid; Hdl1DC0* h; } sl;
    if (!D_005723C8)
        D_005723C8 = 1;
    if (func_002EB650((NetOwnerHdl**)&sl.h, id) == 0) {
        Sess1DC0* s = sl.h->sess;
        if (kind == -2 && sl.h->owner == NetOwner_LocalId(D_005721A8) && D_0051F080) {
            s->owner = id;
            s->b28 = 1;
            if (s->b29) {
                Obj1DC0* o;
                sl.oid = s->netId;
                o = Object_LookupById(&sl.oid);
                if (o) {
                    func_002C4EA0(s->ref, o);
                    func_00316980(s, o);
                    o->link = s;
                }
                D_0051F080 = 0;
                s->b29 = 0;
            }
        }
    }
    D_005723C8 = 0;
}
#pragma pop
