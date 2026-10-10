#include "types.h"

typedef struct { char pad[0x20]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; } NpcFlags;
typedef struct { char pad[0x1AC]; NpcFlags* flags; } cNPC;

/* cNPC virtual 0x2B: returns 1 if flag bits 0 and 2 are both set. */
int cNPC_v2B(cNPC* self)
{
    return self->flags->b0 && self->flags->b2;
}
