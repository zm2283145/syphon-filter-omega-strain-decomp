#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "SFOLobby.h"

extern "C" {
int strcmp(const char*, const char*);
int func_0044CA30(SFOLobby*);
int func_0044CA90(SFOLobby*);
int SFOLobby_Authenticate(SFOLobby*);
char* LobbyArray_At(LobbyArray*, int);
int SFOLobby_ResolveHost(SFOLobby*, char*, char*);
int SFOLobby_RequestLobbyList(SFOLobby*);
int SFOLobby_JoinLobby(SFOLobby*, int);
}

/* Same as SFOLobby_ConnectUniverse. */
static inline bool Connect(SFOLobby* self, int idx) {
    if (self->connHandle > 0) {
        if (!func_0044CA90(self)) return false;
        if (!func_0044CA30(self)) return false;
    }
    if (!self->directAuth) {
        LobbyUniverseEntry* e = (LobbyUniverseEntry*)LobbyArray_At(self->universeList, idx);
        if (!SFOLobby_ResolveHost(self, e->hostName, self->authServer)) return false;
        self->authPort = e->port;
    }
    if (!SFOLobby_Authenticate(self)) return false;
    if (!SFOLobby_RequestLobbyList(self)) return false;
    return true;
}

/* Auto-join: finds wantedUniverse in universeList, connects to it, then joins
 * the lobby named wantedLobby. Not available with directAuth. */
extern "C" int SFOLobby_AutoJoin(SFOLobby* self) {
    bool found;
    int i;
    char* e;
    LobbyArray* l;

    if (self->directAuth) return 0;
    found = false;
    for (i = 0; i < (l = self->universeList)->count; i++) {
        e = LobbyArray_At(l, i);
        if (e && !strcmp(self->wantedUniverse, e /* name */)) {
            found = true;
            if (!Connect(self, i)) return 0;
            break;
        }
    }
    if (!found) return 0;
    for (i = 0; i < (l = self->lobbyList)->count; i++) {
        e = LobbyArray_At(l, i);
        if (e && !strcmp(self->wantedLobby, e + 4 /* name */)) return SFOLobby_JoinLobby(self, i);
    }
    return 0;
}
