/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc; LobbyRecord1C accessors.
 */

#include "loose05_types.h"

void LobbyArray_SetRefreshing(LobbyRecord1C* self, char value) {
    self->refreshing = value;
}

unsigned char LobbyArray_GetRefreshing(LobbyRecord1C* self) {
    return self->refreshing;
}
