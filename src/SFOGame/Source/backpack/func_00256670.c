/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack virtual slot (teardown).
 */

#include "types.h"
#include "backpack_types.h"

extern int g_HotboxTracker;
extern void cHotboxMan_SetupInteractBoxDimensionsAndLocation(int manager, BackpackLink* link, cBackpack* backpack, int a3);
extern void cGOBJ_ApplyTranslation(cBackpack* backpack);

/* Calls the base implementation, then unregisters the link object if one exists. */
void cBackpack_ApplyTranslation(cBackpack* backpack) {
    cGOBJ_ApplyTranslation(backpack);
    if (backpack->link != 0) {
        cHotboxMan_SetupInteractBoxDimensionsAndLocation(g_HotboxTracker, backpack->link, backpack, 0);
    }
}
