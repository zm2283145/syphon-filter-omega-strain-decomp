#include "SFOLobby.h"
extern void LobbyArray_RemoveAt(LobbyArray* list, int index);
/* Removes element index of array38 when it is within range. */
void func_00450EC0(SFOLobby* self, int index) {
    if (index < self->array38.count) {
        LobbyArray_RemoveAt(&self->array38, index);
    }
}
