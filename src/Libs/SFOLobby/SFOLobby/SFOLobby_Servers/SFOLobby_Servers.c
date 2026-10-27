/*
 * main/SFOLobby_Servers: 5 files, 00442840-00442D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00442840 */
#pragma push /* merge_units */
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
void Libc_Strcpy(char*, char*);
int SFOLobby_GetMillisecs(void);
int* SFOLobbyList_GetSlot(LobbyArray*, int);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void SFOLobby_GuiCallback(SFOLobby*, int, int);
int SFOLobby_Poll(SFOLobby*, int, int, int);
int MediusPickLocation(void*, void*);
void SFOLobby_Callback_PickLocation();

/* Joins lobby `index` of lobbyList (MediusPickLocation, reply callback SFOLobby_Callback_PickLocation)
 * and records its world id in lobbyWorldId. */
int SFOLobby_RegionSelect(SFOLobby* self, int index) {
    Join442840 l;
    int* e;

    memset(&l, 0, sizeof(l));
    Libc_Strcpy(l.messageId, D_004C05C8);
    Libc_Strcpy(l.sessionKey, self->sessionKey);
    e = SFOLobbyList_GetSlot(self->lobbyList, index);
    l.worldId = *e;
    self->lobbyWorldId = 0;
    *(int*)((char*)self + 0x26A8) = 0; /* just past the end of SFOLobby */
    self->waitStart = SFOLobby_GetMillisecs();
    self->gotReply1B0 = 0;
    self->requestResult = MediusPickLocation(&l, SFOLobby_Callback_PickLocation);
    while (self->gotReply1B0 == 0) {
        SFOLobby_GuiCallback(self, 0, 0);
        if (SFOLobby_Poll(self, self->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(self, 2, D_004C05D0, 0x153);
            return 0;
        }
    }
    self->lobbyWorldId = *e;
    SFOLobby_SetError(self, 0, D_004C05D0, 0x162);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00442840 */

/* merge_units: begin func_00442970 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off

extern "C" {
int strcmp(const char*, const char*);
int SFOLobby_MediusDisconnectMAS(SFOLobby*);
int SFOLobby_SessionEndRequest(SFOLobby*);
int SFOLobby_Authenticate(SFOLobby*);
#if 0 /* merge_units */
char* SFOLobbyList_GetSlot(LobbyArray*, int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((char *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */

int SFOLobby_DNSLookup(SFOLobby*, char*, char*);
int SFOLobby_ServerMuisGetRegionList(SFOLobby*);
#if 0 /* merge_units */
int SFOLobby_RegionSelect(SFOLobby*, int);
#endif /* merge_units */
#define SFOLobby_RegionSelect(a0, a1) (SFOLobby_RegionSelect((a0), (a1))) /* merge_units */

}

/* Same as SFOLobby_ConnectUniverse. */
static inline bool Connect(SFOLobby* self, int idx) {
    if (self->connHandle > 0) {
        if (!SFOLobby_SessionEndRequest(self)) return false;
        if (!SFOLobby_MediusDisconnectMAS(self)) return false;
    }
    if (!self->directAuth) {
        LobbyUniverseEntry* e = (LobbyUniverseEntry*)SFOLobbyList_GetSlot(self->universeList, idx);
        if (!SFOLobby_DNSLookup(self, e->hostName, self->authServer)) return false;
        self->authPort = e->port;
    }
    if (!SFOLobby_Authenticate(self)) return false;
    if (!SFOLobby_ServerMuisGetRegionList(self)) return false;
    return true;
}

/* Auto-join: finds wantedUniverse in universeList, connects to it, then joins
 * the lobby named wantedLobby. Not available with directAuth. */
extern "C" int SFOLobby_ServerSelect(SFOLobby* self) {
    bool found;
    int i;
    char* e;
    LobbyArray* l;

    if (self->directAuth) return 0;
    found = false;
    for (i = 0; i < (l = self->universeList)->count; i++) {
        e = SFOLobbyList_GetSlot(l, i);
        if (e && !strcmp(self->wantedUniverse, e /* name */)) {
            found = true;
            if (!Connect(self, i)) return 0;
            break;
        }
    }
    if (!found) return 0;
    for (i = 0; i < (l = self->lobbyList)->count; i++) {
        e = SFOLobbyList_GetSlot(l, i);
        if (e && !strcmp(self->wantedLobby, e + 4 /* name */)) return SFOLobby_RegionSelect(self, i);
    }
    return 0;
}
#undef SFOLobbyList_GetSlot /* merge_units */
#undef SFOLobby_RegionSelect /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442970 */

/* merge_units: begin func_00442B50 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int SFOLobby_DNSLookup();
int SFOLobby_ServerMuisGetRegionList();
int SFOLobby_MediusDisconnectMAS();
int SFOLobby_SessionEndRequest();
int SFOLobby_Authenticate();
#if 0 /* merge_units */
LobbyUniverseEntry * SFOLobbyList_GetSlot(LobbyArray *, int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((LobbyUniverseEntry *)SFOLobbyList_GetSlot((a0), (a1))) /* merge_units */


/* Connects to universe `arg1` of universeList: drops any current connection,
 * resolves the universe's auth server (unless directAuth), authenticates
 * (SFOLobby_Authenticate) and fetches its lobby list (SFOLobby_ServerMuisGetRegionList). */
int SFOLobby_ConnectUniverse(SFOLobby * arg0, int arg1) {
    LobbyUniverseEntry * temp_v0;

    if (arg0->connHandle > 0) {
        if (SFOLobby_SessionEndRequest() == 0) {
            return 0;
        }
        if (SFOLobby_MediusDisconnectMAS(arg0) == 0) {
            return 0;
        }
        goto block_5;
    }
block_5:
    if (arg0->directAuth == 0) {
        temp_v0 = SFOLobbyList_GetSlot(arg0->universeList, arg1);
        if (SFOLobby_DNSLookup(arg0, temp_v0->hostName, arg0->authServer) == 0) {
            return 0;
        }
        arg0->authPort = temp_v0->port;
        goto block_10;
    }
block_10:
    if (SFOLobby_Authenticate(arg0) == 0) {
        return 0;
    }
    return SFOLobby_ServerMuisGetRegionList(arg0);
}
#undef SFOLobbyList_GetSlot /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00442B50 */

/* merge_units: begin func_00442C20 */
#pragma push /* merge_units */
typedef struct {
    int type;
    int id;
    char data[0x38];
} NetCfg442C20;

extern char D_00583A00[];
char* strncpy(char*, const char*, unsigned int);
int sceLibnetInitialize(void*, int, int, int);
int sceLibnetRegisterHandler(void*, void*);
int sceInetName2Address(void*, void*, int, void*, char*, int, int);
int sceInetAddress2String(void*, void*, char*, int, void*);
void sceLibnetTerminate(void*);

/* Resolves `hostName` with sceLibnet (DNS lookup) and stores the address
 * string (max 31 chars) in `out`. */
int SFOLobby_DNSLookup(SFOLobby* self, char* hostName, char* out) {
    NetCfg442C20 cfg;
    char buf[0x5C0];

    memset(&cfg, 0, sizeof(cfg));
    cfg.type = 1;
    cfg.id = -1;
    if (sceLibnetInitialize(self->libnetCtx, 0x800, 0x2000, 0x20) != 0) {
        return 0;
    }
    if (sceLibnetRegisterHandler(self->libnetCtx, D_00583A00) < 0) {
        return 0;
    }
    if (sceInetName2Address(self->libnetCtx, D_00583A00, 0, cfg.data, hostName, 0, 0) < 0) {
        SFOLobby_SetError(self, 0x2D, D_004C05D0, 0xB3);
        sceLibnetTerminate(self->libnetCtx);
        return 0;
    }
    if (sceInetAddress2String(self->libnetCtx, D_00583A00, buf, 0x80, cfg.data) < 0) {
        SFOLobby_SetError(self, 0x2D, D_004C05D0, 0xC0);
        sceLibnetTerminate(self->libnetCtx);
        return 0;
    }
    strncpy(out, buf, 0x1F);
    out[0x1F] = 0;
    sceLibnetTerminate(self->libnetCtx);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00442C20 */

/* merge_units: begin func_00442D80 */
#pragma push /* merge_units */
#pragma opt_loop_invariants off
#pragma opt_common_subs off

void SFOLobbyList_ClearList(LobbyArray*);
int MediusGetLocations(char*, void*);
void SFOLobby_Callback_GetLocations();

/* Refills lobbyList (MediusGetLocations, one reply per lobby via SFOLobby_Callback_GetLocations) and
 * waits for the end-of-list record. */
int SFOLobby_ServerMuisGetRegionList(SFOLobby* self) {
    char buf[0x26]; /* message id, session key at +0x15 */

    SFOLobbyList_ClearList(self->lobbyList);
    memset(buf, 0, sizeof(buf));
    memset(self->reply39C, 0, 0x64);
    Libc_Strcpy(buf, D_004C05C8);
    Libc_Strcpy(buf + 0x15, self->sessionKey);
    self->waitStart = SFOLobby_GetMillisecs();
    self->requestResult = MediusGetLocations(buf, SFOLobby_Callback_GetLocations);
    while (self->reply39CEnd != 1) {
        SFOLobby_GuiCallback(self, 0, 0);
        if (SFOLobby_Poll(self, self->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(self, 2, D_004C05D0, 0x7C);
            return 0;
        }
    }
    return self->reply39CStatus >= 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00442D80 */
