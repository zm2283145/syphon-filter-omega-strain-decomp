#pragma cplusplus on
#include "types.h"
struct Sub282AF0 { char p[0x54]; unsigned char b54; };
struct Tank282AF0 { char p[0x6C]; Sub282AF0* sub; };
struct Msg282AF0 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth282AF0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" int Script_cTank_StopFiring(Tank282AF0** args) {
    Tank282AF0* self = args[0];
    if (self->sub) self->sub->b54 = 1;
    if (g_IsMultiplayer && IsAuth282AF0()) {
        Msg282AF0 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.b24 = 4;
m.b20 = 4;
m.f1C = 0x40;
m.f2C = 0;
m.f28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
