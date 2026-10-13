#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* WorldInv_AddArmor: count a spawn request; on first activation register the object and create its proxy */
struct Pt1SpProxy { char pad[0x94]; int id; };
struct Pt1SpObj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetActive(int on);
    char pad4[0xC - 4];
    int id;
    char pad10[0x2E4 - 0x10];
    int requests;
    int reqA;
    int reqB;
    char pad2F0[0x2FC - 0x2F0];
    Pt1SpProxy* proxy;
};
extern "C" {
extern void* D_004FFBD0;
void Object_Register(Pt1SpObj* o);
Pt1SpProxy* Hotbox_CreateRuntime(void* mgr, Pt1SpObj* o, int a, int b);
}
extern "C" void WorldInv_AddArmor(Pt1SpObj* o, int a, int b)
{
    if (!a)
        return;
    if (o->requests++ == 0) {
        o->reqA = a;
        o->reqB = b;
    }
    if (o->proxy)
        return;
    o->SetActive(1);
    Object_Register(o);
    if (o->proxy)
        return;
    o->proxy = Hotbox_CreateRuntime(D_004FFBD0, o, 0, 1);
    o->proxy->id = o->id;
}