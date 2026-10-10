#include "types.h"
typedef struct { char pad[0x40]; float health; } D2_Actor5B;
typedef struct { char pad[0x30]; D2_Actor5B* actor; } D2_NPC5B;
extern void func_003CC990(D2_Actor5B* a, int v, int sync);
void cNPC_v5B(D2_NPC5B* self, int v) {
    D2_Actor5B* a = self->actor;
    if ((int)a->health > 0) {
        func_003CC990(a, v, 0);
    }
}