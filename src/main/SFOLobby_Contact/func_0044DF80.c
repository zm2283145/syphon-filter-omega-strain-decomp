#include "SFOLobby.h"
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void func_00452FC0(SFOLobby*);
extern void LobbyArray_Init(LobbyArray*, int, int, int);
extern void SFOLobby_RequestBuddyList(SFOLobby*, int);
extern char D_004C0ED0[]; /* "SFOLobby_Contact.cc" */
#pragma push
/* Enters the CONTACTS state (6) from IDLE/initial with the caller-supplied
 * output lists, then requests the buddy list. */
int SFOLobby_EnterContactsState(SFOLobby* s, int unused, LobbyArray* list23EC, LobbyArray* buddies)
{
    if (s->state != SFOLOBBY_STATE_IDLE && s->state != SFOLOBBY_STATE_0) {
        SFOLobby_SetError(s, 1, D_004C0ED0, 0x21);
        return 0;
    }
    s->state = SFOLOBBY_STATE_CONTACTS;
    func_00452FC0(s);
    s->outList23EC = list23EC;
    s->outBuddyList = buddies;
    LobbyArray_Init(s->outList23EC, s->unk1EA4, 0, 0x68);
    LobbyArray_Init(s->outBuddyList, 0x40, 0x20, sizeof(LobbyBuddyEntry));
    s->buddyListTime = 0;
    s->buddyInfoTime = 0;
    SFOLobby_RequestBuddyList(s, 0);
    SFOLobby_SetError(s, 0, D_004C0ED0, 0x3C);
    return 1;
}
#pragma pop
