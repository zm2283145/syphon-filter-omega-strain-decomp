#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern int Net_ParseIPv4(char*);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_004689F8(void*, void*);
extern int func_00468F78(void*);
extern int SFOLobby_RequestAccountInfo(SFOLobby*, int);
extern void func_00449A00(SFOLobby*);
extern void func_00452F30(SFOLobby*, int, LobbyPlayerInfo*);
extern void func_004505E0(SFOLobby*, LobbyPlayerInfo*);
extern void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, LobbyPlayerInfo*);
extern void func_00449800(SFOLobby*, int);
extern void* memset(void*, int, int);
extern int D_00497728;              /* connect timeout */
extern int D_00497740;              /* connect attempts */
extern int D_00497890;              /* reply timeout */
extern LobbyPlayerInfo D_00585E90;  /* own player info */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_00447220[];
extern char func_00447D80[];
extern char func_00447D70[];
/* Sends the session key (same request as func_0044C940 with flag 1). */
static inline unsigned char Login_CE60(SFOLobby* s)
{
    struct { char sessionKey[0x14]; int flag; } req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.sessionKey, s->sessionKey);
    req.flag = 1;
    s->requestResult = func_00468F78(&req);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0xD, D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}
/* Connects to the lobby server named in the login reply, sends the session key,
 * then fetches the own player info (falling back to D_00585E90), fills in the
 * live fields and publishes it. */
int SFOLobby_ConnectLobby(SFOLobby* s)
{
    LobbyConnectParams req;
    char buf[8];
    int n;
    LobbyPlayerInfo* info;
    SFOLobby_CallUpdateHook(s, 2, 3);
    n = 0;
    memset(&req, 0, sizeof(req));
    memset(buf, 0, sizeof(buf));
    req.info.type = s->loginReply.connectInfo.type;
    req.info.addrs = s->loginReply.connectInfo.addrs;
    req.info.worldId = s->loginReply.connectInfo.worldId;
    req.info.serverKey = s->loginReply.connectInfo.serverKey;
    req.info.sessionKey = s->loginReply.connectInfo.sessionKey;
    req.info.accessKey = s->loginReply.connectInfo.accessKey;
    req.timeout = D_00497728;
    req.onConnect = func_00447220;
    req.unkF8 = func_00447D80;
    req.unkFC = func_00447D70;
    while (n < D_00497740 && s->connHandle == -1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        n++;
        s->requestResult = func_004689F8(&req, buf);
        if (s->requestResult == 0) {
            s->gotConnect = 0;
            s->waitStart = Lobby_GetTime();
            while (s->gotConnect == 0) {
                SFOLobby_CallUpdateHook(s, 0, 0);
                if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
                    SFOLobby_SetError(s, 2, D_004C0E80, 0x184);
                    break;
                }
            }
        }
    }
    if (s->connHandle == -1) {
        SFOLobby_SetError(s, 0xC, D_004C0E80, 0x18D);
        return 0;
    }
    if (!Login_CE60(s)) {
        return 0;
    }
    {
        unsigned char ok = SFOLobby_RequestAccountInfo(s, s->accountId);
        func_00449A00(s);
        info = ok ? &s->accountInfoReply.info : &D_00585E90;
    }
    func_00452F30(s, 0, info);
    info->wE8 = s->unk2484;
    info->ip = Net_ParseIPv4(s->myIp);
    info->wEC = 0;
    info->bF9 = 0;
    info->wF0 = 0;
    info->bF8 = 5;
    func_004505E0(s, info);
    SFOLobby_CacheAccount(s, s->accountId, s->accountInfoReply.accountName, info->ip, info);
    func_00449800(s, 1);
    return 1;
}
