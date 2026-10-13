/*
 * main/SFOLobby_Connect: 3 files, 0044D200-0044D510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044D200 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern int D_00497728;              /* connect timeout */
extern int D_00497740;              /* connect attempts */
extern int D_00497890;              /* reply timeout */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
void func_00447220(void);
void SFOLobby_CallUpdateHook(void* a, int b, int c);
int memset(void* d, int c, int n);
void func_0046BA68(LobbyConnectParams* cfg, int a, char* host, int port, int c);
int func_004689F8(LobbyConnectParams* cfg, int* out);
int Lobby_GetTime(void);
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
void SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
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
#pragma pop /* merge_units */
/* merge_units: end func_0044D200 */

/* merge_units: begin func_0044D3D0 */
#pragma push /* merge_units */
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
#if 0 /* merge_units */
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
#endif /* merge_units */
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */

extern int func_0046BEB0(void*, void*);
#if 0 /* merge_units */
extern void* memset(void*, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((void *)memset((a0), (a1), (a2))) /* merge_units */

extern char D_004C0E78[];           /* "1" */
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
#undef SFOLobby_SetError /* merge_units */
#undef SFOLobby_CallUpdateHook /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef memset /* merge_units */
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

extern int func_0044CBE0(SFOLobby*);
extern int func_004688D8(char*);
#if 0 /* merge_units */
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void* memset(void*, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((void *)memset((a0), (a1), (a2))) /* merge_units */

extern char* strncpy(char*, const char*, int);
extern void* memcpy(void*, const void*, int);
extern void func_004691D8(R44D*);
extern void SFOLobby_RequestMyIp(SFOLobby*);
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
#undef SFOLobby_SetError /* merge_units */
#undef memset /* merge_units */
#undef func_0044D3D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D510 */
