/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack virtual slot.
 */

#include "types.h"
#include "backpack_types.h"

extern BackpackWorld* g_WeaponDatabase;
extern char D_005716C0[];

char* cBackpack_GetBBox(void) {
    char* p = g_WeaponDatabase->unkB8;
    if (p != 0) {
        return p + 0x3E0;
    }
    return D_005716C0;
}
