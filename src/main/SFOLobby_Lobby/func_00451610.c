#include "SFOLobby.h"
extern void func_00452FC0(SFOLobby* self, int x);
extern void LobbyArray_Free(LobbyArray* p);
/* Shuts the lobby down from states 0, 5 and 10 (state becomes 9 unless it was 10)
 * and frees the caller lists and the lobby arrays. */
void func_00451610(SFOLobby* self)
{
    if (self->state == SFOLOBBY_STATE_IDLE) return;
    if (self->state == 5 || self->state == 0 || self->state == 10) {
        if (self->state != 10) {
            self->state = SFOLOBBY_STATE_IDLE;
        }
        func_00452FC0(self, 0);
        if (self->outList23EC) {
            LobbyArray_Free(self->outList23EC);
        }
        self->outList23EC = 0;
        if (self->outList23F4) {
            LobbyArray_Free(self->outList23F4);
        }
        self->outList23F4 = 0;
        if (self->outList23F0) {
            LobbyArray_Free(self->outList23F0);
        }
        self->outList23F0 = 0;
        LobbyArray_Free(&self->list8C);
        LobbyArray_Free(&self->listA8);
        LobbyArray_Free(&self->array00);
    }
}
