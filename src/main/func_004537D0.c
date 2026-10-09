/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Main.cc (ends 0x004534A0) and GuiSubTitleDisplay.cc;
 * probably part of SFOLobby_Main.cc.
 */

#include "loose05_types.h"

extern int memset(void* dst, int value, int size); /* memset */

/* Resets the lobby object: clears the session block and the handles. */
int func_004537D0(SFOLobby* self) {
    int ret;

    ret = memset(self->sessionBlock, 0, 0x950);
    self->unk255C = 0;
    self->unk180 = -1;
    self->unk184 = 0;
    self->unk18C = 0;
    self->unk194 = 0;
    self->unk198 = 0;
    self->unk19C = 0;
    self->unk1A0 = 0;
    self->unk1A4 = 0;
    self->unk1A8 = 0;
    self->unk1AC = 0;
    self->unk1B0 = 0;
    self->unk1B4 = 0;
    self->unk1B8 = 0;
    self->unk1BC = 0;
    self->unk1C0 = 0;
    self->unk1C4 = 0;
    self->unk1C8 = 0;
    self->unk1D0 = 0;
    self->unk1F8 = 0;
    self->unk1FC = 0;
    self->unk200 = 0;
    self->unk204 = 0;
    self->unk208 = 0;
    self->unk210 = 0;
    self->unk2660 = 0;
    self->unk1E98 = 0;
    self->unk1E9C = 0;
    self->unk243D = 0;
    self->unk2480 = -1;
    self->unk2484 = -1;
    self->unk2408 = 0;
    self->unk2578 = 0;
    self->unk2188 = 0;
    self->unk218C = 0;
    self->unk238C = 0;
    self->unk26C = -1;
    self->unk330 = -1;
    self->unkA80 = -1;
    self->unkBEC = -1;
    self->unkC44 = -1;
    self->unkD14 = -1;
    self->unkD3C = -1;
    self->unkE84 = -1;
    self->unkEAC = -1;
    self->unk126C = -1;
    self->unk13B0 = -1;
    self->unk13B4 = -1;
    self->unk14F8 = -1;
    return ret;
}
