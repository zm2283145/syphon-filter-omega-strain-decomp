/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack virtual slot (teardown).
 */

#include "types.h"
#include "backpack_types.h"

extern int g_HotboxTracker;
extern void HotboxWorld_UpdateBoxBounds(int manager, BackpackLink* link, cBackpack* backpack, int a3);
extern void func_003CDBE0(cBackpack* backpack);

/* Calls the base implementation, then unregisters the link object if one exists. */
void cBackpack_v28(cBackpack* backpack) {
    func_003CDBE0(backpack);
    if (backpack->link != 0) {
        HotboxWorld_UpdateBoxBounds(g_HotboxTracker, backpack->link, backpack, 0);
    }
}
