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
