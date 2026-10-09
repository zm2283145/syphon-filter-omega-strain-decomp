/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"
#include "interface_manager_types.h"

/* unk0C of slot `index`, or 0 when the index is out of range. */
int func_00413370(IfManager* mgr, int index) {
    int inRange = index < IFMGR_SLOT_COUNT; /* computed before the sign test (matches) */

    if (index < 0 || !inRange) {
        return 0;
    }
    return mgr->slots[index].unk0C;
}
