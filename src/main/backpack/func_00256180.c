/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack link creation.
 */

#include "types.h"
#include "backpack_types.h"

extern int D_004FFBD0;
extern BackpackLink* func_00170E20(int manager, cBackpack* backpack, int a2, int a3);

/* Creates the backpack's link object through manager D_004FFBD0 if it has none. */
void func_00256180(cBackpack* backpack) {
    if (backpack->link == 0) {
        backpack->link = func_00170E20(D_004FFBD0, backpack, 0, 1);
        backpack->link->owner = backpack->unk0C;
    }
}
