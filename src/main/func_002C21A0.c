/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void* D_004FFD30;                    /* weapon definition table */
extern GuiEquipmentModifyObj* D_0051EE10;   /* GuiEquipmentModify instance */
extern WeaponDefL2* WeaponDb_Get(void* table, int id);
extern int func_002BF4B0(GuiEquipmentModifyObj* screen, WeaponLinkL2* link, int arg);

Rel* func_002C21A0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Applies the attachment of the currently selected weapon (or its linked record). */
void func_002C21C0(void) {
    GuiEquipmentModifyObj* screen;
    WeaponLinkL2* link;
    WeaponDefL2* def;
    int index;

    screen = D_0051EE10;
    if (screen->unk84 != 0 && screen->unk8C != 0) {
        index = screen->weaponIndex;
        link = 0;
        if (index < screen->weaponCount) {
            link = WeaponDb_Get(D_004FFD30, screen->weaponIds[index])->attachment;
        }
        if (link != 0 && D_0051EE10->unkD4 != 0) {
            def = WeaponDb_Get(D_004FFD30, link->weaponId);
            if (def->kind == 7) {
                link = def->link;
            }
            if (link != 0) {
                func_002BF4B0(D_0051EE10, link, D_0051EE10->unkD4);
            }
        }
    }
}
