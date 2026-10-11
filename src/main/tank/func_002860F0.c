#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Tank_60F0 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
extern char D_004DCF90[];
extern char D_004F77C0[];
void func_0022C650(void* list, int arg);
void Object_Register(Tank_60F0* o);
int NetMap_BindReceiver(int id, int owner, Tank_60F0* o);
void cGOBJ_ctor(Tank_60F0* o, void* id, int a, int* b);
void IdMgr_Allocate(void* out, int kind);
}
static inline int NetHostOk_60F0(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" Tank_60F0* cTank_ctor(Tank_60F0* o, int arg1)
{
    char id[4];
    int z[1];
    z[0] = 0;
    IdMgr_Allocate(id, 0xF9);
    cGOBJ_ctor(o, id, 0, z);
    *(char**)o = D_004DCF90;
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    func_0022C650(D_004F77C0, arg1);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (D_005721C8) {
        o->id10 = o->idC;
        if (!NetHostOk_60F0()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
    return o;
}