#include "types.h"
#pragma inline_depth(10)
#include "net_local_id.h"
typedef struct {
    char* vt; char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0xF]; unsigned char b24; char pad25[0x7F];
    int fA4; int fA8; unsigned char bAC; char padAD[0x1130 - 0xAD]; int arr[0x20]; int f11B0;
} ObjMan_7ED0;
extern char D_004F7578[];
extern char D_004DB790[];
void Receiver_Construct(ObjMan_7ED0* o, void* type);
void IdMgr_Allocate(int* out, int kind);
int NetMap_BindReceiver(int id, int owner, ObjMan_7ED0* o);
ObjMan_7ED0* ObjMan_Ctor(ObjMan_7ED0* o)
{
    int i;
    Receiver_Construct(o, D_004F7578);
    o->vt = D_004DB790;
    o->fA4 = 0;
    o->fA8 = 1;
    o->f11B0 = 0;
    for (i = 0; i < 0x20; i++) o->arr[i] = 0;
    o->b24 = 0;
    o->bAC = 0;
    if (D_005721C8) {
        int id[1];
        IdMgr_Allocate(id, 0xF6);
        o->idC = id[0];
        o->id10 = o->idC;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
        if (!(D_005721C8 ? D_005721C0 : 1)) o->b14 = 0;
    }
    return o;
}
