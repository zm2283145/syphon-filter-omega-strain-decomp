#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Obj_63E0 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
extern char D_004F77C0[];
void func_0022C650(void* list);
void Object_Register(Obj_63E0* o);
int NetMap_BindReceiver(int id, int owner, Obj_63E0* o);
}
static inline int NetHostOk_63E0(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_002863E0(Obj_63E0* o, int arg1)
{
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    func_0022C650(D_004F77C0);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (D_005721C8) {
        o->id10 = o->idC;
        if (!NetHostOk_63E0()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
}