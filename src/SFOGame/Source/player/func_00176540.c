/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "types.h"
#include "player_types.h"

extern void* cGameSystem_GetAgentData(void* agents, int index);
extern char g_Game[];
extern void cPlayerControls_HandleDeath(PlayerInputState* input);
extern void cAgentData_AddScore(void* agent, int a1, int a2);

void cPlayer_NoticeDeath(PlayerComponent* self) {
    cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 8, 1);
    cPlayerControls_HandleDeath(&self->input);
}
