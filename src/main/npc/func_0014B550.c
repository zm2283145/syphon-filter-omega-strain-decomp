#include "types.h"
typedef struct { char pad[0x118]; int prio; char pad2[0x22]; char state; } NPC;
/* Sets the state when the given priority is at least the current one. */
void cNPC_v46(NPC* n, char state, int prio) { if (prio >= n->prio) { n->state = state; n->prio = prio; } }
