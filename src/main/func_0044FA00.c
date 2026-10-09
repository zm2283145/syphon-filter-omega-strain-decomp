/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc (starts 0x0044FA70).
 */

#include "loose05_types.h"

extern int D_00585FA8;

/* Constructor: clears the record; unk18 defaults to 1. */
LobbyRecord1C* func_0044FA00(LobbyRecord1C* self) {
    self->unk10 = 0;
    self->unk0C = 0;
    self->unk08 = 0;
    self->unk04 = 0;
    self->unk00 = 0;
    self->unk14 = 0;
    self->unk18 = 1;
    self->unk19 = 0;
    self->unk1A = 0;
    self->unk18 = 1;
    return self;
}

/* True when D_00585FA8 is set and the object's flag at +0x17C is clear. */
int func_0044FA40(Lobby17C* self) {
    int ret;

    ret = 0 < (unsigned int)D_00585FA8;
    if (ret != 0) {
        ret = (0 < (unsigned int)self->unk17C) ^ 1;
    }
    return ret;
}
