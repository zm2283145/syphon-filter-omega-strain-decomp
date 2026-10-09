/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack virtual slot.
 */

#include "types.h"
#include "backpack_types.h"

extern BackpackWorld* D_004FFD30;
extern char D_005716C0[];

char* cBackpack_v20(void) {
    char* p = D_004FFD30->unkB8;
    if (p != 0) {
        return p + 0x3E0;
    }
    return D_005716C0;
}
