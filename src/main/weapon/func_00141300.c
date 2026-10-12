#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class R_1300 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1300 { void* vt; char pad[0x20]; int id; char f28; char pad29[7]; };
struct SEv_1300 { void* vt; char pad4[0x1C]; char f20; char pad21[0x57]; char f78[0x9C]; char f114[0xAC]; };
struct Slot_1300 { int pad0; int id; int f8; int count; };
struct Own_1300 { char pad[0x14]; unsigned char f14; char pad15[0x43]; R_1300* recv; };
struct W_1300 { char pad[0x48]; unsigned char kind; char pad49[0xA7]; unsigned char fF0; };
struct S_1300 { int pad0; Slot_1300 slots[8]; unsigned char cur; char pad85[3]; Own_1300* own; };
extern "C" {
extern void* D_004FFD30;
extern char D_0055D480[];
extern char D_004E0840[];
extern char D_004DAE30[];
extern char D_004FFB50[];
extern char D_004F27F0[];
extern char D_004F2990[];
extern char D_004F2B30[];
W_1300* WeaponDb_Get(void* db, int id);
void Event_Construct(void* e, void* type);
void Event_Send(void* e, void* target, int a);
void cMessage_dtor(void* e, int f);
void SoundEvent_CtorFromPreset(void* e, void* preset, void* src);
void func_0036E220(void* p, int a);
}
extern "C" int Weapon_DryFire(S_1300* self)
{
    SEv_1300 se;
    Ev_1300 e;
    if (self->cur != 6) {
        Slot_1300* s = &self->slots[self->cur];
        W_1300* w = WeaponDb_Get(D_004FFD30, s->id);
        if (!w->fF0 && !s->f8) {
            if (s->count > 0) {
                Event_Construct(&e, D_0055D480);
                e.f28 = 0;
                e.vt = D_004E0840;
                e.id = 0x3C;
                Event_Send(&e, self->own, 0);
                e.vt = D_004E0840;
                cMessage_dtor(&e, 0);
                return 1;
            }
            if (self->own->f14) {
                unsigned char local = 0;
                R_1300* r = self->own->recv;
                if (r && r->IsLocal())
                    local = 1;
                if (local) {
                    char* preset;
                    switch (w->kind) {
                    case 2:
                        preset = D_004F2990;
                        break;
                    case 4:
                        preset = D_004F2B30;
                        break;
                    default:
                        preset = D_004F27F0;
                        break;
                    }
                    if (preset) {
                        SoundEvent_CtorFromPreset(&se, preset, self->own);
                        se.f20 = 1;
                        Event_Send(&se, D_004FFB50, 0);
                        se.vt = D_004DAE30;
                        func_0036E220(se.f114, -1);
                        func_0036E220(se.f78, -1);
                        cMessage_dtor(&se, 0);
                    }
                }
            }
        }
    }
    return 0;
}

