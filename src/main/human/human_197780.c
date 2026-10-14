/*
 * main/human: range (2 files, 00197780-001977F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_00197780 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetGrenadeMsg_dtor, D_004DCDC0, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00197780 */

/* merge_units: begin func_001977F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctl_1977F0 { char pad[0x810]; int flags; };
struct Inv_1977F0 { char pad[0x18]; int v18; char pad1C[0x84 - 0x1C]; unsigned char b84; };
struct A_1977F0 {
    char pad0[0x31B2];
    unsigned char autoAim;              /* 0x31B2 */
    char pad31B3[0x31C4 - 0x31B3];
    float f31C4;                        /* 0x31C4 */
    char pad31C8[0x31D0 - 0x31C8];
    float f31D0;                        /* 0x31D0 */
    char pad31D4[0x3204 - 0x31D4];
    int flags3204;                      /* 0x3204 */
    char pad3208[0x320C - 0x3208];
    int state;                          /* 0x320C */
    char pad3210[0x3248 - 0x3210];
    int flags3248;                      /* 0x3248 */
    char pad324C[0x3310 - 0x324C];
    Ctl_1977F0* ctl;                    /* 0x3310 */
    void* secondary;                    /* 0x3314 */
    char pad3318[0x33EC - 0x3318];
    unsigned char* flashlight;          /* 0x33EC */
    char pad33F0[0x3524 - 0x33F0];
    Inv_1977F0* inv;                    /* 0x3524 */
};

extern "C" {
int Inventory_GetEquipMode(Inv_1977F0* inv);
unsigned char WeaponInv_GetHeldClass(Inv_1977F0* inv);
void Actor_ApplySecondaryMode(void* s, int mode);
}

static inline unsigned char CtlBit9_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->ctl && ((a->ctl->flags >> 9) & 1)) r = 1;
    return r;
}

static inline unsigned char Swim9_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->state == 8 && CtlBit9_1977F0(a)) r = 1;
    return r;
}

static inline unsigned char FlashOn_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->flashlight != 0 && *a->flashlight != 0) r = 1;
    return r;
}

static inline bool Armed_1977F0(A_1977F0* a, bool melee) { return a->inv->b84 != 6 && !melee; }
static inline unsigned char CanAim_1977F0(A_1977F0* a, bool melee) { unsigned char r = 1; if (!Armed_1977F0(a, melee) && !FlashOn_1977F0(a)) r = 0; return r; }
static inline unsigned char OkAim_1977F0(A_1977F0* a, unsigned char want, bool melee) { unsigned char r = 0; if (want && CanAim_1977F0(a, melee)) r = 1; return r; }
static inline bool AimState_1977F0(A_1977F0* a, bool swimAim, bool ladder, bool bit3)
{
    return a->state == 0 || swimAim || ladder || bit3;
}

static inline bool Loaded_1977F0(Inv_1977F0* w)
{
    return !(w->v18 == -1) && w->b84 == 0;
}

extern "C" void Actor_ChooseSecondaryMode(A_1977F0* a, unsigned char want)
{
    bool melee;
    unsigned char swimAim;
    bool bit3;
    unsigned char ok;
    bool ladder;
    int eq;
    unsigned char aim;
    bool water;
    bool hold;
    int mode;
    unsigned char k;
    eq = Inventory_GetEquipMode(a->inv);
    melee = WeaponInv_GetHeldClass(a->inv) == 1;
    water = a->state == 8 || a->state == 0x10;
    swimAim = 0;
    if (Swim9_1977F0(a) && (a->flags3204 & 1)) swimAim = 1;
    ladder = a->state == 0x10;
    bit3 = (a->flags3248 >> 3) & 1;
    aim = 0;
    ok = OkAim_1977F0(a, want, melee);
    if (ok && AimState_1977F0(a, swimAim, ladder, bit3)) aim = 1;
    hold = ((a->flags3204 >> 4) & 1) && !(a->flags3204 & 1);

    a->autoAim = aim;
    k = eq;
    switch (k) {
    case 1:
        if (aim) {
            if (water) mode = 0x17;
            else if (Loaded_1977F0(a->inv)) mode = 5;
            else mode = 2;
        } else {
            if (Loaded_1977F0(a->inv) || melee || water) mode = 1;
            else if (a->state == 0 && !((a->flags3204 >> 3) & 1) && !(a->f31D0 <= 0.75f) && !(a->f31C4 <= 0.1f)) mode = 1;
            else mode = 0xD;
        }
        break;
    case 8:
        if (aim) {
            if (water) mode = 0x17;
            else mode = 6;
        } else {
            mode = 1;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (aim) {
            if (water) {
                if (k == 3) mode = 0x17;
                else mode = 1;
            } else if (k == 3) {
                if (a->flags3204 & 1) mode = 9;
                else mode = 8;
            } else {
                if (a->flags3204 & 1) mode = 0xB;
                else mode = 0xA;
            }
        } else {
            if (water) mode = 1;
            else if (k == 4) mode = 0xF;
            else mode = 0xE;
        }
        break;
    case 6:
        if (aim) {
            if (water) mode = 1;
            else mode = 0xC;
        } else {
            if (water) mode = 1;
            else mode = 0x10;
        }
        break;
    case 0:
    case 7:
    case 9:
        if (aim && FlashOn_1977F0(a)) {
            if (water) {
                if (ladder) mode = 1;
                else mode = 0x17;
            } else {
                mode = 7;
            }
        } else if (water) {
            mode = 1;
        } else {
            switch (WeaponInv_GetHeldClass(a->inv)) {
            case 3: mode = 0x11; break;
            case 4: mode = 0x12; break;
            case 10: mode = 0x13; break;
            case 7: mode = 1; break;
            default: mode = 1; break;
            }
        }
        break;
    }
    if (a->state != 0 || hold) {
        if (a->state == 4) goto s4;
        if (a->state == 5 || a->state == 10 || a->state == 11) {
        s4:
            if ((unsigned char)mode == 0xE && !((a->flags3248 >> 10) & 1) && !((a->flags3248 >> 12) & 1)) goto done;
        }
        if (a->state == 3 && ((unsigned char)mode == 0xD || (unsigned char)mode == 0xE || (unsigned char)mode == 0xF)) goto done;
        if (a->state == 2 && (!((unsigned char)mode == 0xD || (unsigned char)mode == 6 || (unsigned char)mode == 0x10 || (unsigned char)mode == 0x11 || (unsigned char)mode == 0x12 || (unsigned char)mode == 0x13) || ((a->flags3248 >> 3) & 1))) goto done;
        if (!water) mode = 1;
    }
done:

    if (a->secondary) Actor_ApplySecondaryMode(a->secondary, mode);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001977F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001977F0 */
