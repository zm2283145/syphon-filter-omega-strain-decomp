#include "SFOLobby.h"
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int SFOLobby_ResolveHost();
int SFOLobby_RequestLobbyList();
int func_0044CA30();
int func_0044CA90();
int SFOLobby_Authenticate();
LobbyUniverseEntry * LobbyArray_At(LobbyArray *, int);

/* Connects to universe `arg1` of universeList: drops any current connection,
 * resolves the universe's auth server (unless directAuth), authenticates
 * (SFOLobby_Authenticate) and fetches its lobby list (SFOLobby_RequestLobbyList). */
int SFOLobby_ConnectUniverse(SFOLobby * arg0, int arg1) {
    LobbyUniverseEntry * temp_v0;

    if (arg0->connHandle > 0) {
        if (func_0044CA90() == 0) {
            return 0;
        }
        if (func_0044CA30(arg0) == 0) {
            return 0;
        }
        goto block_5;
    }
block_5:
    if (arg0->directAuth == 0) {
        temp_v0 = LobbyArray_At(arg0->universeList, arg1);
        if (SFOLobby_ResolveHost(arg0, temp_v0->hostName, arg0->authServer) == 0) {
            return 0;
        }
        arg0->authPort = temp_v0->port;
        goto block_10;
    }
block_10:
    if (SFOLobby_Authenticate(arg0) == 0) {
        return 0;
    }
    return SFOLobby_RequestLobbyList(arg0);
}
