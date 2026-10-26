#ifndef TANK_OBJ_INIT_VT_H
#define TANK_OBJ_INIT_VT_H
/* Variant of tank_obj_init.h whose vtable declaration lets a unit define it.
   cTank-style object (vtable cTank_vtable, 0x78 bytes): field init, register,
   activate (virtual slot 0x5C) and bind to the net map (cTank_init body,
   inlined into the factories). C++ only; needs net_local_id.h and
   #pragma inline_depth(10) in the user. */
#include "vslot_pad.h"
struct TankObj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
extern char g_TargetVisMgr[];
extern void* const cTank_vtable[]; /* defined by the cTank factory unit */
void TargetVis_Register(void* list, int arg);
void Object_Register(TankObj* o);
int NetMap_BindReceiver(int id, int owner, TankObj* o);
}
static inline int TankObj_HostOk(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void TankObj_Init(TankObj* o, int arg)
{
    *(void* const**)o = cTank_vtable;
    o->f60 = arg;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    TargetVis_Register(g_TargetVisMgr, arg);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (g_IsMultiplayer) {
        o->id10 = o->idC;
        if (!TankObj_HostOk()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
}
#endif