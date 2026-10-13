#include "SFOLobby.h"
extern int LobbyArray_At(LobbyArray*);
/* Element of inbox (0 when empty). */
int func_00451010(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->inbox.count == 0) { asm { .set reorder } return 0; }
    return LobbyArray_At(&p->inbox);
}
