/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc; LobbyRecord1C accessors.
 */

#include "loose05_types.h"

void func_0044F160(LobbyRecord1C* self, char value) {
    self->unk19 = value;
}

unsigned char func_0044F170(LobbyRecord1C* self) {
    return self->unk19;
}
