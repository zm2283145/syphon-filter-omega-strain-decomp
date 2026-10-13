#include "SFOLobby.h"
extern int LobbyArray_At(LobbyArray*);
/* Element of array38 (0 when empty). */
int func_00450EF0(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->array38.count == 0) { asm { .set reorder } return 0; }
    return LobbyArray_At(&p->array38);
}
