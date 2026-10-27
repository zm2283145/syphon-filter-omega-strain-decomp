#include "types.h"
typedef struct { char pad[0x40]; float health; } D2_Actor5B;
typedef struct { char pad[0x30]; D2_Actor5B* actor; } D2_NPC5B;
extern void cGOBJ_SetHitpoints(D2_Actor5B* a, int v, int sync);
void cNPC_SetHitPoints(D2_NPC5B* self, int v) {
    D2_Actor5B* a = self->actor;
    if ((int)a->health > 0) {
        cGOBJ_SetHitpoints(a, v, 0);
    }
}