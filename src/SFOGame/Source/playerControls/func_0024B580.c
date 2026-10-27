/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int cPlayerControls_ExitCrawl_cGOBJP(InputState* self, int a1);
extern int cPlayerControls_StayInCrawl(InputState* self, int a1);

void cPlayerControls_HandleExitJumpBox(InputState* self) {
    self->unk26 = 0;
}

void cPlayerControls_HandleEnterJumpBox(InputState* self, int unk27, int* unk28) {
    self->unk26 = 1;
    self->unk27 = unk27;
    self->unk28 = *unk28;
}

/* Leaving a code-9 (crouch) zone. */
int cPlayerControls_HandleExitCrawlBox(InputState* self, int a1) {
    self->crouchZone = 0;
    return cPlayerControls_ExitCrawl_cGOBJP(self, a1);
}

/* Entering a code-9 (crouch) zone. */
int cPlayerControls_HandleEnterCrawlBox(InputState* self, int a1) {
    self->crouchZone = 1;
    return cPlayerControls_StayInCrawl(self, a1);
}
