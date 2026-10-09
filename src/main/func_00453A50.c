/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after SFOLobby_Main.cc (ends 0x004534A0); probably part of it.
 */

#include "loose05_types.h"

extern int func_0044F880(LobbyRecord1C* pool, int count, int grow, int elemSize);

/* Sets up the lobby's record pools (count, growth, element size). */
int func_00453A50(SFOLobby* self) {
    func_0044F880(&self->pool70, 32, 32, 276);
    func_0044F880(&self->poolFC, 512, 0, 320);
    func_0044F880(&self->pool118, 1024, 512, 44);
    func_0044F880(&self->poolC4, 64, 32, 80);
    func_0044F880(&self->poolE0, 64, 32, 80);
    func_0044F880(&self->pool134, 64, 32, 80);
    return func_0044F880(&self->pool150, 64, 32, 80);
}
