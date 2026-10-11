#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Ctl_56D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x29]; Ctl_56D0* ctl; } Obj_56D0;
extern "C" {
int func_003FBC40(int id);
void func_002D1FF0(void* key, int id);
int NetMap_BindReceiver(int id, int owner, Obj_56D0* o);
}
static inline unsigned char IsNet_56D0(Obj_56D0* o)
{
    unsigned char ok = 0;
    Ctl_56D0* c = o->ctl;
    if (c && c->isNet()) ok = 1;
    return ok;
}
extern "C" void func_001856D0(Obj_56D0* o)
{
    if (IsNet_56D0(o)) o->id10 = o->idC;
    else { int v = o->idC; if (v == -1) o->id10 = v; else { o->id10 = v; asm { .set reorder } /* barrier: keeps the identical arms from merging */ } }
    if (IsNet_56D0(o) || func_003FBC40(o->id10)) {
        int ok = o->b2D != 0;
        ok = ok ? o->b2C != 0 : ok;
        ok = ok ? (o->b2E != 0) ^ 1 : ok;
        if (ok) func_002D1FF0(&o->idC, o->id10);
    }
    {
        int t = o->id10;
        NetMap_BindReceiver(t, NetLocalId(), o);
    }
}
