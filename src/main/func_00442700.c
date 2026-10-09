/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Mission.cc and SFOLobby_Servers.cc.
 */

#include "loose05_types.h"

extern int func_004498C0(SFOLobby* lobby);
extern int func_0044D780(SFOLobby* lobby);
extern int func_00451B30(SFOLobby* lobby);

/* Per-frame lobby update: runs three sub-updates while in mode 4 and not suspended. */
void func_00442700(SFOLobby* self) {
    if (self->unk255C == 4 && self->unk2409 == 0) {
        func_0044D780(self);
        func_004498C0(self);
        func_00451B30(self);
    }
}
