#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct WiId { int a, b, c, d; WiId() {} } __attribute__((aligned(16)));
typedef struct { char d[0x9C]; } WiStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    WiStr s78;
    WiStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) WiSnd;
struct WiChk {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsBusy();
};
struct WiEquip { char pad[0x2410]; int slots[8]; };
struct WiOwner {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual WiId GetId(int n);
    char pad4[0x10];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    WiChk* chk;
    char pad5C[4];
    WiEquip equip;
};
typedef struct {
    char pad0[0x18];
    int id;
    char pad1C[0x84 - 0x1C];
    unsigned char cur;
    char pad85[3];
    WiOwner* owner;
    char pad8C[0xA4 - 0x8C];
    int timer;
} WiInv;
extern "C" {
extern unsigned char D_00489D70[];
extern unsigned char D_00489D78[];
extern char D_004F1950[];
extern char D_004FFB50[];
extern char D_004DAE30[];
void WeaponInv_HolsterCurrent(WiInv* inv);
void Equip_SwapSlots(WiEquip* e, int a, int b);
void SoundPosRequest_Ctor(WiSnd* e, void* preset, WiId* id);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void func_0036E220(WiStr* s, int flag);
}
static inline int WiIsNone(int x) { return x == -1; }
static inline bool WiBusy(WiOwner* o)
{
    bool r = false;
    if (o->chk && o->chk->IsBusy())
        r = true;
    return r;
}
static inline void WiSwap(WiEquip* e, int a, int b, bool& sw)
{
    if (e->slots[a]) {
        sw = true;
        Equip_SwapSlots(e, a, b);
    }
}
extern "C" bool WeaponInv_Equip(WiInv* self, unsigned char slot)
{
    bool swapped = false;
    if (self->cur != slot) {
        WeaponInv_HolsterCurrent(self);
        if (slot == 0 && (WiIsNone(self->id) ^ 1)) {
            WeaponInv_Equip(self, 1);
        }
        if (WiBusy(self->owner)) {
            WiOwner* o = self->owner;
            if (o->b14 && slot != 1) {
                WiId id = o->GetId(-1);
                WiSnd snd;
                SoundPosRequest_Ctor(&snd, D_004F1950, &id);
                snd.flag = 1;
                Event_Send(&snd, D_004FFB50, 0);
                snd.vt = D_004DAE30;
                func_0036E220(&snd.s114, -1);
                func_0036E220(&snd.s78, -1);
                cMessage_dtor(&snd, 0);
            }
        }
        self->cur = slot;
        WiSwap(&self->owner->equip, D_00489D70[slot], D_00489D78[slot], swapped);
        self->timer = -1;
    }
    return swapped;
}
