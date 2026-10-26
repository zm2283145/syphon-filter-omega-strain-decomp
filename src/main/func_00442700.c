/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Mission.cc and SFOLobby_Servers.cc.
 */

#include "loose05_types.h"

extern int SFOLobby_CellUpdateClanInvitations(SFOLobby* lobby);
extern int SFOLobby_ContactGetInvites(SFOLobby* lobby);
extern int func_00451B30(SFOLobby* lobby);

/* Per-frame lobby update: runs three sub-updates while in mode 4 and not suspended. */
void SFOLobby_MissionScreenIntel(SFOLobby* self) {
    if (self->state == 4 && self->inUpdateHook == 0) {
        SFOLobby_ContactGetInvites(self);
        SFOLobby_CellUpdateClanInvitations(self);
        func_00451B30(self);
    }
}
