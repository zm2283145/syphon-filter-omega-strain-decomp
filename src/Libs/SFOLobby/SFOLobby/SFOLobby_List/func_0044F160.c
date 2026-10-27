/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc; LobbyRecord1C accessors.
 */

#include "loose05_types.h"

void SFOLobbyList_SetBusy(LobbyRecord1C* self, char value) {
    self->refreshing = value;
}

unsigned char SFOLobbyList_IsBusy(LobbyRecord1C* self) {
    return self->refreshing;
}
