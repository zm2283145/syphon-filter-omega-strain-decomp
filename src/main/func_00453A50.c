/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after SFOLobby_Main.cc (ends 0x004534A0); probably part of it.
 */

#include "loose05_types.h"

extern int LobbyArray_Init(LobbyRecord1C* pool, int count, int grow, int elemSize);

/* Sets up the lobby's record pools (count, growth, element size). */
int func_00453A50(SFOLobby* self) {
    LobbyArray_Init(&self->pool70, 32, 32, 276);
    LobbyArray_Init(&self->accountCache, 512, 0, 320);
    LobbyArray_Init(&self->pool118, 1024, 512, 44);
    LobbyArray_Init(&self->poolC4, 64, 32, 80);
    LobbyArray_Init(&self->buddyList, 64, 32, 80);
    LobbyArray_Init(&self->pool134, 64, 32, 80);
    return LobbyArray_Init(&self->pool150, 64, 32, 80);
}
