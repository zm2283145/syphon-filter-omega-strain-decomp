/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern void* Agent_GetSelected(void* agents, int index);
extern char g_Game[];
extern void cPlayerControls_HandleDeath(PlayerInputState* input);
extern void Stats_Add(void* agent, int a1, int a2);

void cPlayer_v1D(PlayerComponent* self) {
    Stats_Add(Agent_GetSelected(g_Game, -1), 8, 1);
    cPlayerControls_HandleDeath(&self->input);
}
