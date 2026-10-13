#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "SFOLobby.h"

extern int D_00497890;    /* request timeout */
extern char D_004C05C8[]; /* "1" (message id) */
extern char D_004C05D0[]; /* "SFOLobby_Servers.cc" */
void* memset(void*, int, unsigned int);
void String_Copy(char*, char*);
int Lobby_GetTime(void);
void LobbyArray_Clear(LobbyArray*);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int SFOLobby_Poll(SFOLobby*, int, int, int);
int func_0046B1E0(char*, void*);
void func_00446EA0();

/* Refills lobbyList (func_0046B1E0, one reply per lobby via func_00446EA0) and
 * waits for the end-of-list record. */
int SFOLobby_RequestLobbyList(SFOLobby* self) {
    char buf[0x26]; /* message id, session key at +0x15 */

    LobbyArray_Clear(self->lobbyList);
    memset(buf, 0, sizeof(buf));
    memset(self->reply39C, 0, 0x64);
    String_Copy(buf, D_004C05C8);
    String_Copy(buf + 0x15, self->sessionKey);
    self->waitStart = Lobby_GetTime();
    self->requestResult = func_0046B1E0(buf, func_00446EA0);
    while (self->reply39CEnd != 1) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        if (SFOLobby_Poll(self, self->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(self, 2, D_004C05D0, 0x7C);
            return 0;
        }
    }
    return self->reply39CStatus >= 0;
}
