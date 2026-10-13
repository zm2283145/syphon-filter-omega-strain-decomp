#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "SFOLobby.h"
typedef struct {
    char messageId[0x15];
    char sessionKey[0x11];
    char info[0xFC];                /* LobbyPlayerInfo (unaligned here) */
    char pad[4];
} Req4505;
extern "C" {
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);
char* strncpy(char*, const char*, unsigned int);
void String_Copy(char*, const char*);
int Lobby_GetTime(void);
int func_004695C8(void*, void*);
void func_00446CC0(void);
void SFOLobby_SetError(SFOLobby*, int, const char*, int);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int SFOLobby_Poll(SFOLobby*, int, int, int);
int Net_ParseIPv4(char*);
void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, LobbyPlayerInfo*);
extern int D_00497890;              /* reply timeout */
extern char D_004C0F68[];           /* "1" */
extern char D_004C0F70[];           /* "SFOLobby_Lobby.cc" */
extern LobbyPlayerInfo D_00585E90;  /* own player info */
}
/* Uploads the own player info (reply callback func_00446CC0), waits for the reply,
 * then keeps a copy in D_00585E90 and in the account cache. */
extern "C" int func_004505E0(SFOLobby* self, LobbyPlayerInfo* info)
{
    Req4505 req;
    int t;
    self->unk2590 = Lobby_GetTime();
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0F68);
    strncpy(req.sessionKey, self->sessionKey, 0x11);
    memcpy(&req.info, info, 0xFC);
    self->requestResult = func_004695C8(&req, (void*)func_00446CC0);
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 1, D_004C0F70, 0x428);
        return 0;
    }
    t = Lobby_GetTime();
    self->gotAccountInfo = 0;
    while (self->gotReply208 == 0) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        if (!SFOLobby_Poll(self, t, D_00497890, 0)) {
            SFOLobby_SetError(self, 2, D_004C0F70, 0x436);
            return 0;
        }
    }
    D_00585E90 = *info;
    SFOLobby_CacheAccount(self, self->accountId, self->accountName, Net_ParseIPv4(self->myIp), &D_00585E90);
    return 1;
}
