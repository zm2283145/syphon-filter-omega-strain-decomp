/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack link creation.
 */

#include "types.h"
#include "backpack_types.h"

extern int g_HotboxTracker;
extern BackpackLink* cHotboxMan_CreateInteractBox(int manager, cBackpack* backpack, int a2, int a3);

/* Creates the backpack's link object through manager g_HotboxTracker if it has none. */
void cBackpack_MakeInteractBox(cBackpack* backpack) {
    if (backpack->link == 0) {
        backpack->link = cHotboxMan_CreateInteractBox(g_HotboxTracker, backpack, 0, 1);
        backpack->link->owner = backpack->unk0C;
    }
}
