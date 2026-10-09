/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "grenade_types.h"

extern char D_005716C0[];   /* default resource */

/* Vtable slot +0x88: resource for the projectile, or the default one. */
char* func_0025AC20(Grenade* self) {
    char* res = self->def->unk13C;

    if (res != 0) {
        return res + 992;
    }
    return D_005716C0;
}
