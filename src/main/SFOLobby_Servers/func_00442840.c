#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "SFOLobby.h"

typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int worldId;
} Join442840;

extern int D_00497890;    /* request timeout */
extern char D_004C05C8[]; /* "1" (message id) */
extern char D_004C05D0[]; /* "SFOLobby_Servers.cc" */
void* memset(void*, int, unsigned int);
void String_Copy(char*, char*);
int Lobby_GetTime(void);
int* LobbyArray_At(LobbyArray*, int);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int SFOLobby_Poll(SFOLobby*, int, int, int);
int func_0046B280(void*, void*);
void func_00446E50();

/* Joins lobby `index` of lobbyList (func_0046B280, reply callback func_00446E50)
 * and records its world id in lobbyWorldId. */
int SFOLobby_JoinLobby(SFOLobby* self, int index) {
    Join442840 l;
    int* e;

    memset(&l, 0, sizeof(l));
    String_Copy(l.messageId, D_004C05C8);
    String_Copy(l.sessionKey, self->sessionKey);
    e = LobbyArray_At(self->lobbyList, index);
    l.worldId = *e;
    self->lobbyWorldId = 0;
    *(int*)((char*)self + 0x26A8) = 0; /* just past the end of SFOLobby */
    self->waitStart = Lobby_GetTime();
    self->gotReply1B0 = 0;
    self->requestResult = func_0046B280(&l, func_00446E50);
    while (self->gotReply1B0 == 0) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        if (SFOLobby_Poll(self, self->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(self, 2, D_004C05D0, 0x153);
            return 0;
        }
    }
    self->lobbyWorldId = *e;
    SFOLobby_SetError(self, 0, D_004C05D0, 0x162);
    return 1;
}
