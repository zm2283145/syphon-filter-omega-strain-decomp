#include "types.h"

typedef struct GObjHp {
    char pad[0x40];
    float hitpoints;
} GObjHp;

typedef struct GObjArgs {
    GObjHp* obj;
} GObjArgs;

/* Script native: cGOBJ.GetHitpoints - returns hitpoints truncated to int. */
int Script_cGOBJ_GetHitpoints(GObjArgs* args) {
    volatile int hp = args->obj->hitpoints;
    return hp;
}
