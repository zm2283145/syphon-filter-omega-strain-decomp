/*
 * Libs/SFOLib/Source/man: 2 files, 0038C5E0-0038C790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038C5E0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct EquipAnim {
    int cur;      /* 0x0 */
    float weight; /* 0x4 */
    int a;        /* 0x8 */
    int b;        /* 0xC */
} EquipAnim;

typedef struct EquipWeapon {
    char pad[0x40D];
    unsigned char animA; /* 0x40D */
    unsigned char animB; /* 0x40E */
} EquipWeapon;

typedef struct Equip {
    char pad[0x23D0];
    EquipAnim primaryAnim;   /* 0x23D0 */
    EquipAnim secondaryAnim; /* 0x23E0 */
    char pad23F0[0x20];
    EquipWeapon* primary;    /* 0x2410 */
    EquipWeapon* secondary;  /* 0x2414 */
    char pad2418[0x2C0C - 0x2418];
    unsigned char mode;      /* 0x2C0C */
} Equip;

extern signed char D_00571510[][0x30];
extern signed char D_00571528[][0x30];

static inline void EquipAnim_Set(Equip* e, EquipAnim* s, signed char (*tbl)[0x30], int a, int b)
{
    s->weight = 1.0f;
    if (a >= 0) {
        s->a = tbl[e->mode][a];
    }
    if (b >= 0) {
        s->b = tbl[e->mode][b];
        s->cur = 0;
        return;
    }
    s->cur = 0;
}

static inline void EquipAnim_Clear(EquipAnim* s)
{
    s->weight = 0.0f;
    s->cur = 0;
}

void cMan_UpdateHandMorphs(Equip* e)
{
    if (e->secondary != 0) {
        EquipAnim_Set(e, &e->secondaryAnim, D_00571528, e->secondary->animA, e->secondary->animA + 1);
    } else {
        EquipAnim_Clear(&e->secondaryAnim);
    }
    if (e->primary != 0) {
        EquipAnim_Set(e, &e->primaryAnim, D_00571510, e->primary->animA, e->primary->animA + 1);
        if (e->primary->animB != -1) {
            EquipAnim_Set(e, &e->secondaryAnim, D_00571528, e->primary->animB, e->primary->animB);
        }
    } else {
        EquipAnim_Clear(&e->primaryAnim);
    }
}
static inline void merge_flush_func_0038C5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038C5E0 */

/* merge_units: begin func_0038C790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Equipment slot swap and clear; both refresh via cMan_UpdateHandMorphs.
 */

#include "man_types.h"

#if 0 /* merge_units */
extern void cMan_UpdateHandMorphs(ManEquipOwner* self);
#endif /* merge_units */
#define cMan_UpdateHandMorphs(a0) (cMan_UpdateHandMorphs((Equip *)(a0))) /* merge_units */


void cMan_ChangeGunPlacement(ManEquipOwner* self, int a, int b) {
    int itemA = self->slots[a];
    int itemB = self->slots[b];
    self->slots[a] = itemB;
    self->slots[b] = itemA;
    cMan_UpdateHandMorphs(self);
}

void cMan_RemoveGun(ManEquipOwner* self, int slot) {
    self->slots[slot] = 0;
    cMan_UpdateHandMorphs(self);
}
#undef cMan_UpdateHandMorphs /* merge_units */
static inline void merge_flush_func_0038C790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038C790 */
