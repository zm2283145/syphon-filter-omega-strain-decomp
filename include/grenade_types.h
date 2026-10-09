#ifndef GRENADE_TYPES_H
#define GRENADE_TYPES_H

/*
 * Projectile (grenade) object, vtable 0x004dc6c0. Offsets from the matched code
 * and the projectile research notes.
 */

#include "types.h"

typedef struct GrenadeDefData {
    char pad00[0x13C];
    char* unk13C;                   /* 0x13C resource block (falls back to D_005716C0) */
} GrenadeDefData;

typedef struct Grenade {
    char pad00[0x120];
    GrenadeDefData* def;            /* 0x120 definition pointer */
} Grenade;

#endif
