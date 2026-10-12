#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Gun282E10 { VPAD32(a) VPAD16(b) VPAD16(c) VPAD2(d) VPAD1(e) virtual void Fire(); virtual void Arm(int on); };
struct Sub282E10 { Gun282E10* gun; };
struct Tank282E10 { char p[0x60]; Gun282E10* turret; char p64[8]; Sub282E10* sub; };
struct Msg282E10 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; float f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void func_0023E3D0(Gun282E10*, float);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth282E10(void) { return D_005721C8 ? D_005721C0 : 1; }
union Arg282E10 { int i; float f; void* p; };
extern "C" int Script_cTank_Move(Arg282E10* args) {
    float v;
Gun282E10* t;
Tank282E10* self;
int tmp;
    tmp = args[1].i;
    v = *(float*)&tmp;
    self = (Tank282E10*)args[0].p;
    t = self->turret;
    func_0023E3D0(t, v);
    t->Fire();
    if (self->sub) self->sub->gun->Arm(1);
    if (D_005721C8 && IsAuth282E10()) {
        Msg282E10 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = 0;
        m.b24 = 1;
        m.f2C = v;
        m.b20 = 4;
        m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
