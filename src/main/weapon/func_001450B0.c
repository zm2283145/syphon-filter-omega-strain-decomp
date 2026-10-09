/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int D_004EA158;   /* cOutOfAmmoMsg type id */
extern int* func_001450C0(void);

void* func_001450B0(void* self) {
    return self;
}

int* func_001450C0(void) {
    return &D_004EA158;
}

int cOutOfAmmoMsg_v03(void) {
    return *func_001450C0();
}
