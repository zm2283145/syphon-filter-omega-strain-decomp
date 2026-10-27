/*
 * main/SFOLobby_Connect: SFOLobby_Connect.cc (12 files, 0044C620-0044D200)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
void *memcpy(void *, const void *, int);
void *memset(void *, int, int);
int strlen(const void *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0044C620 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern int Libc_Strcpy(char*, char*);
extern int SFOLobby_GetMillisecs(void);
extern int SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_GuiCallback(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int MediusGetMyIP(void*, void*);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char SFOLobby_Callback_GetMyIP[];
#pragma push
#pragma opt_common_subs off
/* Asks the server for the own IP address; the reply callback SFOLobby_Callback_GetMyIP stores
 * it in myIp and sets gotMyIp. */
int SFOLobby_GetMyIP(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    Libc_Strcpy(req.messageId, D_004C0E78);
    Libc_Strcpy(req.sessionKey, s->sessionKey);
    memset(s->myIp, 0, 0x14);
    s->requestResult = MediusGetMyIP(&req, SFOLobby_Callback_GetMyIP);
    if (s->requestResult != 0) return 0;
    s->gotMyIp = 0;
    s->waitStart = SFOLobby_GetMillisecs();
    while (s->gotMyIp == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x38A);
            break;
        }
    }
    if (strlen(s->myIp) == 0) {
        SFOLobby_SetError(s, 1, D_004C0E80, 0x392);
        return 0;
    }
    return 1;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0044C620 */

/* merge_units: begin func_0044C760 */
#pragma push /* merge_units */
extern int D_00497728;              /* connect timeout */
extern int D_00497740;              /* connect attempts */
void SFOLobby_Callback_MediusConnect(void);
#if 0 /* merge_units */
void SFOLobby_GuiCallback(void* a, int b, int c);
#endif /* merge_units */
#define SFOLobby_GuiCallback(a0, a1, a2) (SFOLobby_GuiCallback((void *)(a0), (a1), (a2))) /* merge_units */



void MediusSetDefaultConnectInParams(LobbyConnectParams* cfg, int a, char* host, int port, int c);
int MediusConnect(LobbyConnectParams* cfg, int* out);
int SFOLobby_GetMillisecs(void);
#if 0 /* merge_units */
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */


/* Connects to the directory server dirServer:dirPort, retrying up to D_00497740 times;
 * the connect callback SFOLobby_Callback_MediusConnect sets connHandle and gotConnect. */
int SFOLobby_MediusConnectMUIS(SFOLobby* self)
{
    LobbyConnectParams cfg;
    int out[2];
    int tries;
    SFOLobby_GuiCallback(self, 2, 3);
    tries = 0;
    memset(&cfg, 0, 0x100);
    memset(out, 0, 8);
    MediusSetDefaultConnectInParams(&cfg, 0, self->dirServer, self->dirPort, 1);
    cfg.timeout = D_00497728;
    cfg.onConnect = SFOLobby_Callback_MediusConnect;
    cfg.unkF8 = 0;
    cfg.unkFC = 0;
    cfg.info.serverKey = self->serverKey; self->connHandle = -1;
    while (tries < D_00497740 && self->connHandle == -1) {
        SFOLobby_GuiCallback(self, 0, 0);
        tries++;
        self->requestResult = MediusConnect(&cfg, out);
        if (self->requestResult == 0) {
            self->gotConnect = 0;
            self->waitStart = SFOLobby_GetMillisecs();
            while (self->gotConnect == 0) {
                SFOLobby_GuiCallback(self, 0, 0);
                if (!SFOLobby_Poll(self, self->waitStart, D_00497890, 1)) {
                    SFOLobby_SetError(self, 2, D_004C0E80, 0x34D);
                    break;
                }
            }
        }
    }
    if (self->connHandle == -1) {
        SFOLobby_SetError(self, 0xC, D_004C0E80, 0x358);
        return 0;
    }
    return 1;
}
#undef SFOLobby_GuiCallback /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044C760 */

/* merge_units: begin func_0044C940 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Libc_Strcpy();
int SFOLobby_SetError();
int MediusUpdateClientState();
#if 0 /* merge_units */
extern char D_004C0E80;             /* "SFOLobby_Connect.cc" */
#endif /* merge_units */
#define D_004C0E80 (*(char*)&D_004C0E80) /* merge_units */

#pragma opt_common_subs off
/* Sends the session key with flag (MediusUpdateClientState). */
int SFOLobby_UpdateClientState(SFOLobby * self, int flag) {
    struct { int sessionKey[5]; int flag[3]; } sl;
    memset(sl.sessionKey, 0, 0x18);
    Libc_Strcpy(sl.sessionKey, self->sessionKey);
    sl.flag[0] = flag;
    self->requestResult = MediusUpdateClientState(sl.sessionKey);
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0xD, &D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}
#undef D_004C0E80 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044C940 */

/* merge_units: begin func_0044C9D0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int SFOLobby_SetError(SFOLobby * , int, char *, int);
int MediusDisconnect();
/* Disconnects (MediusDisconnect) and forgets the connection. */
int SFOLobby_MediusDisconnectMLS(SFOLobby *self) {
    self->requestResult = MediusDisconnect();
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0x2B, &D_004C0E80, 0x2A0);
        return 0;
    }
    self->connHandle = -1;
    self->gotConnect = 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044C9D0 */

/* merge_units: begin func_0044CA30 */
#pragma push /* merge_units */
#pragma mpwc_relax on

/* Disconnects (MediusDisconnect) and forgets the connection. */
int SFOLobby_MediusDisconnectMAS(SFOLobby *self) {
    self->requestResult = MediusDisconnect();
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 0x2C, &D_004C0E80, 0x288);
        return 0;
    }
    self->connHandle = -1;
    self->gotConnect = 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044CA30 */

/* merge_units: begin func_0044CA90 */
#pragma push /* merge_units */
extern int MediusSessionEnd(void*, void*);
extern char SFOLobby_Callback_SessionEnd[];
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
/* Request answered into reply380 (callback SFOLobby_Callback_SessionEnd); fails on a negative status. */
int SFOLobby_SessionEndRequest(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply380, 0, 0x1C);
    Libc_Strcpy(req.messageId, D_004C0E78);
    Libc_Strcpy(req.sessionKey, s->sessionKey);
    s->requestResult = MediusSessionEnd(&req, SFOLobby_Callback_SessionEnd);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x12, D_004C0E80, 0x25F);
        return 0;
    }
    s->gotReply1A8 = 0;
    s->gotReply1A4 = 0;
    s->waitStart = SFOLobby_GetMillisecs();
    while (s->gotReply1A8 == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x26C);
            return 0;
        }
    }
    if (s->reply380.statusCode < 0) {
        SFOLobby_SetError(s, 0x12, D_004C0E80, 0x274);
        return 0;
    }
    return 1;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0044CA90 */

/* merge_units: begin func_0044CBE0 */
#pragma push /* merge_units */
extern int MediusSessionBegin(void*, void*);
extern char SFOLobby_Callback_SessionBegin[];
#pragma push
#pragma opt_common_subs off
/* Request answered into reply350 (callback SFOLobby_Callback_SessionBegin); fails unless MediusSuccess. */
int SFOLobby_SessionBeginRequest(SFOLobby* s)
{
    struct { char messageId[0x18]; int flag; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply350, 0, 0x30);
    Libc_Strcpy(req.messageId, D_004C0E78);
    req.flag = 1;
    s->requestResult = MediusSessionBegin(&req, SFOLobby_Callback_SessionBegin);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x11, D_004C0E80, 0x222);
        return 0;
    }
    s->gotReply1A4 = 0;
    s->waitStart = SFOLobby_GetMillisecs();
    while (s->gotReply1A4 == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x22E);
            return 0;
        }
    }
    if (s->reply350.statusCode != 0) {
        SFOLobby_SetError(s, 0x11, D_004C0E80, 0x236);
        return 0;
    }
    return 1;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0044CBE0 */

/* merge_units: begin func_0044CD20 */
#pragma push /* merge_units */
extern int MediusGetUniverseInformation(void*, void*, void*);
extern char SFOLobby_Callback_UniverseNews[];
extern char SFOLobby_Callback_UniverseStatusList[];
/* Two-part list request (callbacks SFOLobby_Callback_UniverseNews -> reply17CC and
 * SFOLobby_Callback_UniverseStatusList -> reply18EC); waits until both lists report their end. */
int SFOLobby_UniverseInformationRequest(SFOLobby* s)
{
    struct { char messageId[0x18]; int f18; int f1C; int f20; } req;
    memset(&req, 0, sizeof(req));
    memset(s->reply17CC, 0, 0x120);
    memset(s->reply18EC, 0, 0x230);
    Libc_Strcpy(req.messageId, D_004C0E78);
    req.f18 = 3;
    req.f1C = 2;
    req.f20 = s->unk26A4;
    s->requestResult = MediusGetUniverseInformation(&req, SFOLobby_Callback_UniverseNews, SFOLobby_Callback_UniverseStatusList);
    if (s->requestResult != 0) {
        return 0;
    }
    s->gotReply19C = 0;
    s->gotReply1A0 = 0;
    s->waitStart = SFOLobby_GetMillisecs();
    do {
        SFOLobby_GuiCallback(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 1) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x1E6);
            return 0;
        }
    } while (!s->gotReply19C || !s->gotReply1A0 || s->reply17CCEnd != 1 || s->reply18ECEnd != 1);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044CD20 */

/* merge_units: begin func_0044CE60 */
#pragma push /* merge_units */
extern int SFOLobby_PackIPAddress(char*);
#if 0 /* merge_units */
extern int MediusConnect(void*, void*);
#endif /* merge_units */
#define MediusConnect(a0, a1) (MediusConnect((void *)(a0), (void *)(a1))) /* merge_units */

extern int MediusUpdateClientState(void*);
extern int SFOLobby_GetAgentDetails(SFOLobby*, int);
extern void SFOLobby_CellGetInfo(SFOLobby*);
extern void SFOLobby_StatsCallback(SFOLobby*, int, LobbyPlayerInfo*);
extern void SFOLobby_UpdateStats(SFOLobby*, LobbyPlayerInfo*);
extern void SFOLobby_RefreshAgentData(SFOLobby*, int, char*, int, LobbyPlayerInfo*);
extern void SFOLobby_CellUpdateMemberList(SFOLobby*, int);
extern LobbyPlayerInfo D_00585E90;  /* own player info */
#if 0 /* merge_units */
void SFOLobby_Callback_MediusConnect(); /* gsynth: address taken */
#endif /* merge_units */
#define SFOLobby_Callback_MediusConnect() (SFOLobby_Callback_MediusConnect()) /* merge_units */

#define SFOLobby_Callback_MediusConnect ((char *)SFOLobby_Callback_MediusConnect) /* merge_units */
extern char SFOLobby_Callback_RemoteClientConnect[];
extern char SFOLobby_Callback_RemoteClientDisconnect[];
/* Sends the session key (same request as SFOLobby_UpdateClientState with flag 1). */
static inline unsigned char Login_CE60(SFOLobby* s)
{
    struct { char sessionKey[0x14]; int flag; } req;
    memset(&req, 0, sizeof(req));
    Libc_Strcpy(req.sessionKey, s->sessionKey);
    req.flag = 1;
    s->requestResult = MediusUpdateClientState(&req);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0xD, D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}
/* Connects to the lobby server named in the login reply, sends the session key,
 * then fetches the own player info (falling back to D_00585E90), fills in the
 * live fields and publishes it. */
int SFOLobby_MediusConnectMLS(SFOLobby* s)
{
    LobbyConnectParams req;
    char buf[8];
    int n;
    LobbyPlayerInfo* info;
    SFOLobby_GuiCallback(s, 2, 3);
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
    req.onConnect = SFOLobby_Callback_MediusConnect;
    req.unkF8 = SFOLobby_Callback_RemoteClientConnect;
    req.unkFC = SFOLobby_Callback_RemoteClientDisconnect;
    while (n < D_00497740 && s->connHandle == -1) {
        SFOLobby_GuiCallback(s, 0, 0);
        n++;
        s->requestResult = MediusConnect(&req, buf);
        if (s->requestResult == 0) {
            s->gotConnect = 0;
            s->waitStart = SFOLobby_GetMillisecs();
            while (s->gotConnect == 0) {
                SFOLobby_GuiCallback(s, 0, 0);
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
        unsigned char ok = SFOLobby_GetAgentDetails(s, s->accountId);
        SFOLobby_CellGetInfo(s);
        info = ok ? &s->accountInfoReply.info : &D_00585E90;
    }
    SFOLobby_StatsCallback(s, 0, info);
    info->wE8 = s->unk2484;
    info->ip = SFOLobby_PackIPAddress(s->myIp);
    info->wEC = 0;
    info->bF9 = 0;
    info->wF0 = 0;
    info->bF8 = 5;
    SFOLobby_UpdateStats(s, info);
    SFOLobby_RefreshAgentData(s, s->accountId, s->accountInfoReply.accountName, info->ip, info);
    SFOLobby_CellUpdateMemberList(s, 1);
    return 1;
}
#undef SFOLobby_Callback_MediusConnect /* merge_units */
#undef MediusConnect /* merge_units */
#undef SFOLobby_Callback_MediusConnect /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044CE60 */

/* merge_units: begin func_0044D200 */
#pragma push /* merge_units */
#if 0 /* merge_units */
void SFOLobby_GuiCallback(void* a, int b, int c);
#endif /* merge_units */
#define SFOLobby_GuiCallback(a0, a1, a2) (SFOLobby_GuiCallback((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */

/* Connects to the authentication server authServer:authPort, retrying up to D_00497740 times;
 * the connect callback SFOLobby_Callback_MediusConnect sets connHandle and gotConnect. */
int SFOLobby_MediusConnectMAS(SFOLobby* self)
{
    LobbyConnectParams cfg;
    int out[2];
    int tries;
    SFOLobby_GuiCallback(self, 2, 3);
    tries = 0;
    memset(&cfg, 0, 0x100);
    memset(out, 0, 8);
    MediusSetDefaultConnectInParams(&cfg, 0, self->authServer, self->authPort, 1);
    cfg.timeout = D_00497728;
    cfg.onConnect = SFOLobby_Callback_MediusConnect;
    cfg.unkF8 = 0;
    cfg.unkFC = 0;
    cfg.info.serverKey = self->serverKey;
    while (tries < D_00497740 && self->connHandle == -1) {
        SFOLobby_GuiCallback(self, 0, 0);
        tries++;
        self->requestResult = MediusConnect(&cfg, out);
        if (self->requestResult == 0) {
            self->gotConnect = 0;
            self->waitStart = SFOLobby_GetMillisecs();
            while (self->gotConnect == 0) {
                SFOLobby_GuiCallback(self, 0, 0);
                if (!SFOLobby_Poll(self, self->waitStart, D_00497890, 0)) {
                    SFOLobby_SetError(self, 2, D_004C0E80, 0xF8);
                    break;
                }
            }
        }
    }
    if (self->connHandle == -1) {
        SFOLobby_SetError(self, 0xC, D_004C0E80, 0x103);
        return 0;
    }
    return 1;
}
#undef SFOLobby_GuiCallback /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D200 */

/* merge_units: begin func_0044D3D0 */
#pragma push /* merge_units */
extern int MediusSetLocalizationParams(void*, void*);
extern char func_00445F40[];
#pragma push
#pragma opt_common_subs off
/* Request answered by callback func_00445F40 (status in reply188Status). */
int func_0044D3D0(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int x; int z; } req;
    memset(&req, 0, sizeof(req));
    req.x = 2;
    req.z = s->unk26A4;
    Libc_Strcpy(req.messageId, D_004C0E78);
    Libc_Strcpy(req.sessionKey, s->sessionKey);
    s->requestResult = MediusSetLocalizationParams(&req, func_00445F40);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 1, D_004C0E80, 0x68);
        return 0;
    }
    s->gotReply188 = 0;
    s->waitStart = SFOLobby_GetMillisecs();
    while (s->gotReply188 == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x75);
            return 0;
        }
    }
    if (s->reply188Status != 0) {
        SFOLobby_SetError(s, 1, D_004C0E80, 0x7E);
        return 0;
    }
    return 1;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0044D3D0 */

/* merge_units: begin func_0044D510 */
#pragma push /* merge_units */
typedef struct { char messageId[0x15]; char sessionKey[0x13]; int f28; unsigned char passwordLen; char password[0x20]; char pad[3]; } R44D;
extern void SFOLobbyList_ClearList(LobbyArray*);
#if 0 /* merge_units */
extern int SFOLobby_MediusConnectMAS(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_MediusConnectMAS(a0) (SFOLobby_MediusConnectMAS((a0))) /* merge_units */


#if 0 /* merge_units */
extern int SFOLobby_SessionBeginRequest(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_SessionBeginRequest(a0) (SFOLobby_SessionBeginRequest((a0))) /* merge_units */

extern int MediusGetMySessionKey(char*);


extern void MediusDnasSignature(R44D*);
#if 0 /* merge_units */
extern int SFOLobby_GetMyIP(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_GetMyIP(a0) (SFOLobby_GetMyIP((a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_0044D3D0(SFOLobby*);
#endif /* merge_units */
#define func_0044D3D0(a0) (func_0044D3D0((a0))) /* merge_units */


/* Authentication sequence: connect to the auth server, run the reply350 request,
 * send the session key, send the password (a placeholder when none is set), fetch
 * the own IP and finish with func_0044D3D0. */
int SFOLobby_Authenticate(SFOLobby* o) {
    R44D rec;
    SFOLobbyList_ClearList(&o->accountCache);
    SFOLobbyList_ClearList(&o->pool118);
    if (!SFOLobby_MediusConnectMAS(o)) return 0;
    if (!SFOLobby_SessionBeginRequest(o)) return 0;
    o->requestResult = MediusGetMySessionKey(o->sessionKey);
    if (o->requestResult) {
        SFOLobby_SetError(o, 0x13, D_004C0E80, 0x25);
        return 0;
    }
    if (!o->useDnas || o->passwordLen == 0x20) {
        memset(&rec, 0, 0x50);
        Libc_Strcpy(rec.messageId, D_004C0E78);
        strncpy(rec.sessionKey, o->sessionKey, 0x11);
        rec.f28 = 0;
        if (!o->passwordLen) {
            o->passwordLen = 0x20;
            Libc_Strcpy(o->password, "*******************************");
        }
        rec.passwordLen = o->passwordLen;
        memcpy(rec.password, o->password, 0x20);
        MediusDnasSignature(&rec);
    }
    SFOLobby_GetMyIP(o);
    if (!func_0044D3D0(o)) return 0;
    return 1;
}
#undef SFOLobby_MediusConnectMAS /* merge_units */
#undef SFOLobby_SessionBeginRequest /* merge_units */
#undef SFOLobby_GetMyIP /* merge_units */
#undef func_0044D3D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D510 */
