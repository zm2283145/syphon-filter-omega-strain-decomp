/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc (starts 0x0044FA70).
 */

#include "loose05_types.h"

extern int D_00585FA8;

/* Constructor: clears the record; dirty defaults to 1. */
LobbyRecord1C* SFOLobbyList_ctor(LobbyRecord1C* self) {
    self->elemSize = 0;
    self->grow = 0;
    self->initialCapacity = 0;
    self->count = 0;
    self->capacity = 0;
    self->data = 0;
    self->dirty = 1;
    self->refreshing = 0;
    self->unique = 0;
    self->dirty = 1;
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
