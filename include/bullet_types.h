#ifndef BULLET_TYPES_H
#define BULLET_TYPES_H

#include "types.h"

/* Bullet manager; only the pointer vector at 0x78 is used here. */
typedef struct BulletOwner {
    char pad00[0x78];
    PtrVec list;                    /* 0x78 */
} BulletOwner;

#endif
