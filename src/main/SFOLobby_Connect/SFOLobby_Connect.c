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
extern int String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern int SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046AF60(void*, void*);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_00446D00[];
#pragma push
#pragma opt_common_subs off
/* Asks the server for the own IP address; the reply callback func_00446D00 stores
 * it in myIp and sets gotMyIp. */
int SFOLobby_RequestMyIp(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0E78);
    String_Copy(req.sessionKey, s->sessionKey);
    memset(s->myIp, 0, 0x14);
    s->requestResult = func_0046AF60(&req, func_00446D00);
    if (s->requestResult != 0) return 0;
    s->gotMyIp = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotMyIp == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
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
void func_00447220(void);
#if 0 /* merge_units */
void SFOLobby_CallUpdateHook(void* a, int b, int c);
#endif /* merge_units */
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((void *)(a0), (a1), (a2))) /* merge_units */



void func_0046BA68(LobbyConnectParams* cfg, int a, char* host, int port, int c);
int func_004689F8(LobbyConnectParams* cfg, int* out);
int Lobby_GetTime(void);
#if 0 /* merge_units */
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */


/* Connects to the directory server dirServer:dirPort, retrying up to D_00497740 times;
 * the connect callback func_00447220 sets connHandle and gotConnect. */
int SFOLobby_ConnectDir(SFOLobby* self)
{
    LobbyConnectParams cfg;
    int out[2];
    int tries;
    SFOLobby_CallUpdateHook(self, 2, 3);
    tries = 0;
    memset(&cfg, 0, 0x100);
    memset(out, 0, 8);
    func_0046BA68(&cfg, 0, self->dirServer, self->dirPort, 1);
    cfg.timeout = D_00497728;
    cfg.onConnect = func_00447220;
    cfg.unkF8 = 0;
    cfg.unkFC = 0;
    cfg.info.serverKey = self->serverKey; self->connHandle = -1;
    while (tries < D_00497740 && self->connHandle == -1) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        tries++;
        self->requestResult = func_004689F8(&cfg, out);
        if (self->requestResult == 0) {
            self->gotConnect = 0;
            self->waitStart = Lobby_GetTime();
            while (self->gotConnect == 0) {
                SFOLobby_CallUpdateHook(self, 0, 0);
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
#undef SFOLobby_CallUpdateHook /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044C760 */

/* merge_units: begin func_0044C940 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int String_Copy();
int SFOLobby_SetError();
int func_00468F78();
#if 0 /* merge_units */
extern char D_004C0E80;             /* "SFOLobby_Connect.cc" */
#endif /* merge_units */
#define D_004C0E80 (*(char*)&D_004C0E80) /* merge_units */

#pragma opt_common_subs off
/* Sends the session key with flag (func_00468F78). */
int func_0044C940(SFOLobby * self, int flag) {
    struct { int sessionKey[5]; int flag[3]; } sl;
    memset(sl.sessionKey, 0, 0x18);
    String_Copy(sl.sessionKey, self->sessionKey);
    sl.flag[0] = flag;
    self->requestResult = func_00468F78(sl.sessionKey);
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
int func_00468CD0();
/* Disconnects (func_00468CD0) and forgets the connection. */
int func_0044C9D0(SFOLobby *self) {
    self->requestResult = func_00468CD0();
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

/* Disconnects (func_00468CD0) and forgets the connection. */
int func_0044CA30(SFOLobby *self) {
    self->requestResult = func_00468CD0();
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
extern int func_004690A0(void*, void*);
extern char func_00447470[];
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
/* Request answered into reply380 (callback func_00447470); fails on a negative status. */
int func_0044CA90(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply380, 0, 0x1C);
    String_Copy(req.messageId, D_004C0E78);
    String_Copy(req.sessionKey, s->sessionKey);
    s->requestResult = func_004690A0(&req, func_00447470);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x12, D_004C0E80, 0x25F);
        return 0;
    }
    s->gotReply1A8 = 0;
    s->gotReply1A4 = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotReply1A8 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
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
extern int func_00469000(void*, void*);
extern char func_004471B0[];
#pragma push
#pragma opt_common_subs off
/* Request answered into reply350 (callback func_004471B0); fails unless MediusSuccess. */
int func_0044CBE0(SFOLobby* s)
{
    struct { char messageId[0x18]; int flag; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply350, 0, 0x30);
    String_Copy(req.messageId, D_004C0E78);
    req.flag = 1;
    s->requestResult = func_00469000(&req, func_004471B0);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x11, D_004C0E80, 0x222);
        return 0;
    }
    s->gotReply1A4 = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotReply1A4 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
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
extern int func_0046BFF0(void*, void*, void*);
extern char func_00447130[];
extern char func_00447070[];
/* Two-part list request (callbacks func_00447130 -> reply17CC and
 * func_00447070 -> reply18EC); waits until both lists report their end. */
int func_0044CD20(SFOLobby* s)
{
    struct { char messageId[0x18]; int f18; int f1C; int f20; } req;
    memset(&req, 0, sizeof(req));
    memset(s->reply17CC, 0, 0x120);
    memset(s->reply18EC, 0, 0x230);
    String_Copy(req.messageId, D_004C0E78);
    req.f18 = 3;
    req.f1C = 2;
    req.f20 = s->unk26A4;
    s->requestResult = func_0046BFF0(&req, func_00447130, func_00447070);
    if (s->requestResult != 0) {
        return 0;
    }
    s->gotReply19C = 0;
    s->gotReply1A0 = 0;
    s->waitStart = Lobby_GetTime();
    do {
        SFOLobby_CallUpdateHook(s, 0, 0);
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
extern int Net_ParseIPv4(char*);
#if 0 /* merge_units */
extern int func_004689F8(void*, void*);
#endif /* merge_units */
#define func_004689F8(a0, a1) (func_004689F8((void *)(a0), (void *)(a1))) /* merge_units */

extern int func_00468F78(void*);
extern int SFOLobby_RequestAccountInfo(SFOLobby*, int);
extern void func_00449A00(SFOLobby*);
extern void func_00452F30(SFOLobby*, int, LobbyPlayerInfo*);
extern void func_004505E0(SFOLobby*, LobbyPlayerInfo*);
extern void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, LobbyPlayerInfo*);
extern void func_00449800(SFOLobby*, int);
extern LobbyPlayerInfo D_00585E90;  /* own player info */
#if 0 /* merge_units */
void func_00447220(); /* gsynth: address taken */
#endif /* merge_units */
#define func_00447220() (func_00447220()) /* merge_units */

#define func_00447220 ((char *)func_00447220) /* merge_units */
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
#undef func_00447220 /* merge_units */
#undef func_004689F8 /* merge_units */
#undef func_00447220 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044CE60 */

/* merge_units: begin func_0044D200 */
#pragma push /* merge_units */
#if 0 /* merge_units */
void SFOLobby_CallUpdateHook(void* a, int b, int c);
#endif /* merge_units */
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */

/* Connects to the authentication server authServer:authPort, retrying up to D_00497740 times;
 * the connect callback func_00447220 sets connHandle and gotConnect. */
int SFOLobby_ConnectAuth(SFOLobby* self)
{
    LobbyConnectParams cfg;
    int out[2];
    int tries;
    SFOLobby_CallUpdateHook(self, 2, 3);
    tries = 0;
    memset(&cfg, 0, 0x100);
    memset(out, 0, 8);
    func_0046BA68(&cfg, 0, self->authServer, self->authPort, 1);
    cfg.timeout = D_00497728;
    cfg.onConnect = func_00447220;
    cfg.unkF8 = 0;
    cfg.unkFC = 0;
    cfg.info.serverKey = self->serverKey;
    while (tries < D_00497740 && self->connHandle == -1) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        tries++;
        self->requestResult = func_004689F8(&cfg, out);
        if (self->requestResult == 0) {
            self->gotConnect = 0;
            self->waitStart = Lobby_GetTime();
            while (self->gotConnect == 0) {
                SFOLobby_CallUpdateHook(self, 0, 0);
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
#undef SFOLobby_CallUpdateHook /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D200 */

/* merge_units: begin func_0044D3D0 */
#pragma push /* merge_units */
extern int func_0046BEB0(void*, void*);
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
    String_Copy(req.messageId, D_004C0E78);
    String_Copy(req.sessionKey, s->sessionKey);
    s->requestResult = func_0046BEB0(&req, func_00445F40);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 1, D_004C0E80, 0x68);
        return 0;
    }
    s->gotReply188 = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotReply188 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
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
extern void LobbyArray_Clear(LobbyArray*);
#if 0 /* merge_units */
extern int SFOLobby_ConnectAuth(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_ConnectAuth(a0) (SFOLobby_ConnectAuth((a0))) /* merge_units */


#if 0 /* merge_units */
extern int func_0044CBE0(SFOLobby*);
#endif /* merge_units */
#define func_0044CBE0(a0) (func_0044CBE0((a0))) /* merge_units */

extern int func_004688D8(char*);


extern void func_004691D8(R44D*);
#if 0 /* merge_units */
extern int SFOLobby_RequestMyIp(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_RequestMyIp(a0) (SFOLobby_RequestMyIp((a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_0044D3D0(SFOLobby*);
#endif /* merge_units */
#define func_0044D3D0(a0) (func_0044D3D0((a0))) /* merge_units */


/* Authentication sequence: connect to the auth server, run the reply350 request,
 * send the session key, send the password (a placeholder when none is set), fetch
 * the own IP and finish with func_0044D3D0. */
int SFOLobby_Authenticate(SFOLobby* o) {
    R44D rec;
    LobbyArray_Clear(&o->accountCache);
    LobbyArray_Clear(&o->pool118);
    if (!SFOLobby_ConnectAuth(o)) return 0;
    if (!func_0044CBE0(o)) return 0;
    o->requestResult = func_004688D8(o->sessionKey);
    if (o->requestResult) {
        SFOLobby_SetError(o, 0x13, D_004C0E80, 0x25);
        return 0;
    }
    if (!o->useDnas || o->passwordLen == 0x20) {
        memset(&rec, 0, 0x50);
        String_Copy(rec.messageId, D_004C0E78);
        strncpy(rec.sessionKey, o->sessionKey, 0x11);
        rec.f28 = 0;
        if (!o->passwordLen) {
            o->passwordLen = 0x20;
            String_Copy(o->password, "*******************************");
        }
        rec.passwordLen = o->passwordLen;
        memcpy(rec.password, o->password, 0x20);
        func_004691D8(&rec);
    }
    SFOLobby_RequestMyIp(o);
    if (!func_0044D3D0(o)) return 0;
    return 1;
}
#undef SFOLobby_ConnectAuth /* merge_units */
#undef func_0044CBE0 /* merge_units */
#undef SFOLobby_RequestMyIp /* merge_units */
#undef func_0044D3D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D510 */
