#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Gun285710 { VPAD32(a) VPAD16(b) VPAD16(c) VPAD2(d) VPAD1(e) virtual void Fire(); virtual void Arm(int on); };
struct Sub285710 { Gun285710* gun; };
struct Tank285710 { char p[0x60]; Gun285710* turret; char p64[8]; Sub285710* sub; };
struct Msg285710 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; float f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void func_0023E3D0(Gun285710*);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth285710(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_00285710(Tank285710* self, float v) {
    Gun285710* t = self->turret;
    func_0023E3D0(t);
    t->Fire();
    if (self->sub) self->sub->gun->Arm(1);
    if (D_005721C8 && IsAuth285710()) {
        Msg285710 m;
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
}
