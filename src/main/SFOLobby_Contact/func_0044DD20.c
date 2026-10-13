#include "SFOLobby.h"
extern void func_00452FC0(SFOLobby*, int);
extern void LobbyArray_Free(LobbyArray*);

/* Leaves the CONTACTS state (6; state 10 is left unchanged), releasing the
 * caller-supplied lists set up by SFOLobby_EnterContactsState. */
void SFOLobby_LeaveContactsState(SFOLobby* s)
{
    int st = s->state;
    if (st == SFOLOBBY_STATE_IDLE) return;
    if (st == SFOLOBBY_STATE_CONTACTS || st == SFOLOBBY_STATE_10) {
        if (st != SFOLOBBY_STATE_10) s->state = SFOLOBBY_STATE_IDLE;
        func_00452FC0(s, 0);
        if (s->outList23EC) LobbyArray_Free(s->outList23EC);
        s->outList23EC = 0;
        if (s->outBuddyList) LobbyArray_Free(s->outBuddyList);
        s->outBuddyList = 0;
    }
}
