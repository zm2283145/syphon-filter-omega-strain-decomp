#include "types.h"
typedef struct { char pad[0x68]; int count; void* items[1]; } G4_Act;
extern void func_003BCB90(void* a);
extern void Actor_BaseLogicUpdate(G4_Act* a, float dt);
void func_003BC520(G4_Act* a, float dt)
{
    int i;
    for (i = 0; i < a->count; i++) {
        func_003BCB90(a->items[i]);
    }
    Actor_BaseLogicUpdate(a, dt);
}