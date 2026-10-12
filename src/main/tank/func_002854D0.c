#pragma cplusplus on
#include "types.h"
struct Sub2854D0 { char p[0x54]; unsigned char b54; };
struct Tank2854D0 { char p[0x6C]; Sub2854D0* sub; unsigned char b70; };
struct Msg2854D0 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth2854D0(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_002854D0(Tank2854D0* self) {
    if (self->sub) self->sub->b54 = 0;
    self->b70 = 1;
    if (D_005721C8 && IsAuth2854D0()) {
        Msg2854D0 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f2C = 0;
m.b24 = 2;
m.f28 = 0;
m.b20 = 4;
m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
