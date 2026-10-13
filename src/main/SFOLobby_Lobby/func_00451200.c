#include "SFOLobby.h"
extern int D_00497890;              /* reply timeout */
extern char D_004C0F68[];           /* "1" */
extern char D_004C0F70[];           /* "SFOLobby_Lobby.cc" */
extern char func_00446DB0[];
extern int Lobby_GetTime(void);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_0046A048(void*, void*);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, int);
extern void* memset(void*, int, int);
/* Asks the server for an account's info (reply callback func_00446DB0 fills
 * accountInfoReply), waits for it and stores it in the account cache. */
int SFOLobby_RequestAccountInfo(SFOLobby* s, int id)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int accountId; } req;
    int t;
    if (id < 0) {
        SFOLobby_SetError(s, 0x1D, D_004C0F70, 0x14C);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0F68);
    strncpy(req.sessionKey, s->sessionKey, 0x11);
    req.accountId = id;
    s->requestResult = func_0046A048(&req, func_00446DB0);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 1, D_004C0F70, 0x15A);
        return 0;
    }
    t = Lobby_GetTime();
    s->gotAccountInfo = 0;
    while (s->gotAccountInfo == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, t, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0F70, 0x168);
            return 0;
        }
    }
    SFOLobby_CacheAccount(s, id, s->accountInfoReply.accountName, s->accountInfoReply.info.ip,
                  (int)&s->accountInfoReply.info);
    return 1;
}
