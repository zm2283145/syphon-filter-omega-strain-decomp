#include "types.h"
typedef struct { char pad[0x38]; int state; } Obj250;
typedef struct { char pad[0x320C]; int mode; } Ctx250;
int PlayerInput_CycleWeapon(Obj250* o, Ctx250* c) {
    if (o->state != 6 && c->mode != 0x17 && c->mode != 0x14 && c->mode != 0x15) return 1;
    return 0;
}