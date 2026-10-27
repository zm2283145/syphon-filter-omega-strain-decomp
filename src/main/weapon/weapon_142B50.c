/*
 * main/weapon: range (4 files, 00142B50-00142E00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00142B50 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int rate; } Weap_2B50;
typedef struct { int pad0; int pad4; int id; int padC; } Slot_2B50;
typedef struct { Slot_2B50 slots[8]; char pad[4]; unsigned char cur; } S_2B50;
extern void* g_WeaponDatabase;
const float D_00489C10[2] = { 1.0f, 0.0f };
Weap_2B50* cWeaponDB_GetEntry(void* db, int id);
int cWeapon_GetDamage(S_2B50* self)
{
    unsigned char i = self->cur;
    int r = 0;
    if (i != 6)
        { float f = cWeaponDB_GetEntry(g_WeaponDatabase, self->slots[i].id)->rate; r = (int)(f * (*(float*)D_00489C10)); }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142B50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142B50 */

/* merge_units: begin func_00142BB0 */
#pragma push /* merge_units */
#pragma bool off
static inline int E1IsNone(int x) { return x == -1; }
typedef struct { char pad[0x18]; int id; char pad1c[0x84 - 0x1C]; unsigned char state; unsigned char sub; char pad86[2]; char* equip; char pad8c[0xA4 - 0x8C]; int timer; } AnimHost_e1;
extern unsigned char WeaponHandAttachPoints[];
extern unsigned char WeaponHolsterAttachPoints[];
extern void cMan_ChangeGunPlacement(void*, int, int);
void cWeapon_StoreWeapon_eWpnSlot(AnimHost_e1* self, unsigned char b)
{
    if (b == 0 && (E1IsNone(self->id) ^ 1)) {
        cWeapon_StoreWeapon_eWpnSlot(self, 1);
    }
    cMan_ChangeGunPlacement(self->equip + 0x60, WeaponHandAttachPoints[b], WeaponHolsterAttachPoints[b]);
    self->state = 6;
    self->sub = b;
    self->timer = -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142BB0 */

/* merge_units: begin func_00142C50 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern char D_004F1950[];
extern char g_Game[];
extern char D_004DAE30[];
void cWeapon_StoreWeapon_void(WiInv* inv);
#if 0 /* merge_units */
void cMan_ChangeGunPlacement(WiEquip* e, int a, int b);
#endif /* merge_units */
#define cMan_ChangeGunPlacement(a0, a1, a2) (cMan_ChangeGunPlacement((void *)(a0), (a1), (a2))) /* merge_units */

void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(WiSnd* e, void* preset, WiId* id);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void cFileMan_dtor(WiStr* s, int flag);
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
        cMan_ChangeGunPlacement(e, a, b);
    }
}
extern "C" bool cWeapon_DrawWeapon_eWpnSlot(WiInv* self, unsigned char slot)
{
    bool swapped = false;
    if (self->cur != slot) {
        cWeapon_StoreWeapon_void(self);
        if (slot == 0 && (WiIsNone(self->id) ^ 1)) {
            cWeapon_DrawWeapon_eWpnSlot(self, 1);
        }
        if (WiBusy(self->owner)) {
            WiOwner* o = self->owner;
            if (o->b14 && slot != 1) {
                WiId id = o->GetId(-1);
                WiSnd snd;
                cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&snd, D_004F1950, &id);
                snd.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
                snd.vt = D_004DAE30;
                cFileMan_dtor(&snd.s114, -1);
                cFileMan_dtor(&snd.s78, -1);
                cMessage_dtor(&snd, 0);
            }
        }
        self->cur = slot;
        WiSwap(&self->owner->equip, WeaponHolsterAttachPoints[slot], WeaponHandAttachPoints[slot], swapped);
        self->timer = -1;
    }
    return swapped;
}
#undef cMan_ChangeGunPlacement /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142C50 */

/* merge_units: begin func_00142E00 */
#pragma push /* merge_units */
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { char pad[0x24A2]; unsigned char flags[8]; } Own_2E00;
void cWeapon_SetHardpointActivation(INV* self, unsigned char slot, char v)
{
    if (*(int*)((char*)self + slot * 16 + 8) != -1)
        { Own_2E00* ow = (Own_2E00*)self->owner; ow->flags[WeaponHolsterAttachPoints[slot]] = v; }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142E00 */
