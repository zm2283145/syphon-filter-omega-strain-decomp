/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"
#include "interface_manager_types.h"

/* Setter for unk1E0. */
void func_004138F0(IfManager* mgr, int value) {
    mgr->unk1E0 = value;
}
