#include "types.h"

typedef struct TankBody {
    char pad[0x40];
    float hitpoints;
} TankBody;

typedef struct Tank {
    char pad[0x60];
    TankBody* body;
} Tank;

typedef struct TankArgs {
    Tank* obj;
} TankArgs;

/* Script native: cTank.GetHitpoints - returns the body's hitpoints truncated to int. */
int Script_cTank_GetHitpoints(TankArgs* args) {
    volatile int hp = args->obj->body->hitpoints;
    return hp;
}
