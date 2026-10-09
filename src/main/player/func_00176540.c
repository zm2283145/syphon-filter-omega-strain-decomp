/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern void* Agent_GetSelected(void* agents, int index);
extern char D_004FFB50[];
extern void func_0024B4D0(PlayerInputState* input);
extern void func_00333F10(void* agent, int a1, int a2);

void cPlayer_v1D(PlayerComponent* self) {
    func_00333F10(Agent_GetSelected(D_004FFB50, -1), 8, 1);
    func_0024B4D0(&self->input);
}
