/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"
#include "interface_manager_types.h"

/* Setter for unk1E0. */
void cInterfaceManager_SetHogList(IfManager* mgr, int value) {
    mgr->unk1E0 = value;
}
