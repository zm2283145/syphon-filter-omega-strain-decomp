#include "SFOLobby.h"
#pragma mpwc_relax on
int func_003A6680(int);
int SFOLobby_NetDown(SFOLobby *);
int SFOLobby_ListNetConfigs(SFOLobby *, int);
int func_0044CA30(SFOLobby *);
int LobbyArray_Free(LobbyArray *);
int LobbyArray_Init(LobbyArray *, int, int, int);
int SFOLobby_SetError(SFOLobby *, int, char *, int);
int func_00452C70(SFOLobby *, int);
int func_00452FC0(SFOLobby *);
extern char D_004C0D70; /* "SFOLobby_Config.cc" */

/* Enters the NETWORK state (1) from IDLE/initial: shuts down any previous network
 * session, loads the network modules and sets up the caller-supplied lists, then
 * enumerates the network configurations (SFOLobby_ListNetConfigs). */
int SFOLobby_EnterNetworkState(SFOLobby *self, int arg1, LobbyArray *netConfigs, LobbyArray *list2404, char *universes) {
    LobbyArray *a;

    if ((self->state != SFOLOBBY_STATE_IDLE) && (self->state != SFOLOBBY_STATE_0)) {
        return 0;
    }
    self->state = SFOLOBBY_STATE_NETWORK;
    func_00452FC0(self);
    self->unk2578 = 0;
    if (self->unk1EA8 > 0) {
        if (self->connHandle > 0) {
            func_0044CA30(self);
        }
        func_00452C70(self, 1);
        SFOLobby_NetDown(self);
        func_003A6680(0);
        a = self->outList2404;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->outList2404 = 0;
        a = self->universeList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->universeList = 0;
    }
    if (func_003A6680(1) == 0) {
        SFOLobby_SetError(self, 0x2E, &D_004C0D70, 0x44);
        return 0;
    }
    self->outList2404 = list2404;
    LobbyArray_Init(self->outList2404, 0x10, 0x10, 0x100);
    self->universeList = (LobbyArray *) universes;
    LobbyArray_Init(self->universeList, 0x10, 0x10, sizeof(LobbyUniverseEntry));
    self->netConfigList = netConfigs;
    LobbyArray_Init(self->netConfigList, 0x10, 0x10, 0x13C0);
    if (SFOLobby_ListNetConfigs(self, 0) == 0) {
        a = self->outList2404;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->outList2404 = 0;
        a = self->universeList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->universeList = 0;
        a = self->netConfigList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->netConfigList = 0;
        return 0;
    }
    return 1;
}
