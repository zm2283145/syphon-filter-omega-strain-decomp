/*
 * main/SFOLobby_Connect: 2 files, 0044C620-0044C760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044C620 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046AF60(void*, void*);
extern void* memset(void*, int, int);
extern int strlen(const char*);
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
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((SFOLobby *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int memset(void* d, int c, int n);
#endif /* merge_units */
#define memset(a0, a1, a2) ((int)memset((a0), (a1), (a2))) /* merge_units */

void func_0046BA68(LobbyConnectParams* cfg, int a, char* host, int port, int c);
int func_004689F8(LobbyConnectParams* cfg, int* out);
int Lobby_GetTime(void);
#if 0 /* merge_units */
int SFOLobby_Poll(SFOLobby* self, int a, int b, int c);
#endif /* merge_units */
#define SFOLobby_Poll(a0, a1, a2, a3) (SFOLobby_Poll((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
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
#undef memset /* merge_units */
#undef SFOLobby_Poll /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044C760 */
