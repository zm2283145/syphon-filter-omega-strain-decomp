#pragma cplusplus on
#include "types.h"
struct Sub283020 { char p[0x54]; unsigned char b54; };
struct Tank283020 { char p[0x6C]; Sub283020* sub; unsigned char b70; };
struct Msg283020 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth283020(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" int Script_cTank_ResumeAiming(Tank283020** args) {
    Tank283020* self = args[0];
    if (self->sub) self->sub->b54 = 0;
    self->b70 = 1;
    if (g_IsMultiplayer && IsAuth283020()) {
        Msg283020 m;
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
    return 0;
}
