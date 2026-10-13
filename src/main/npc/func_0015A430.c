/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* True when the message's mode byte is 3. */
int TeleportMsg_IsMode3(NpcAiMsg* msg) {
    return (unsigned int)(msg->aiMode ^ 3) < 1U;
}
