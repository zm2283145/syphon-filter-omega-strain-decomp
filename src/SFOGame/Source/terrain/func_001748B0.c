#include "types.h"
typedef struct { int pad; unsigned char alive; } T_48B0;
typedef struct { char pad[0x6C]; int x6C; T_48B0* t; } S_48B0;
#pragma opt_propagation off
int* cVUM_GOBJ_GetCollisionModel(S_48B0* self)
{
    unsigned char dead = 1;
    T_48B0* t = self->t;
    int z = (t != 0) ^ 1;
    if (!z && !t->alive) dead = 0;
    return dead ? 0 : &self->x6C;
}