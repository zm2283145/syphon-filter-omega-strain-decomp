#include "SFOLobby.h"

void func_0010D3E0(int);
int ezNetCtlSetProperties(int);
int ezNetCtlGetStatus(void*);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int Lobby_GetTime(void);
int func_00353130(void);
int func_003A6650(int);
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern int D_00585D00;    /* time the network was last brought down (SFOLobby_NetDown) */
extern char D_00585D40[]; /* ezNetCtl status buffer */
extern int D_00585D4C;    /* ezNetCtl state: 3 = up, 5 = down */

/* Applies the network configuration, waits at least 2.5 s after the last
 * shutdown, starts the network and waits (60 s timeout) for it to come up. */
int SFOLobby_NetUp(SFOLobby* self, int props)
{
    int r;
    int now;

    func_0010D3E0(0);
    r = ezNetCtlSetProperties(props);
    func_0010D3E0(0);
    if (r < 0) {
        SFOLobby_SetError(self, 7, D_004C0D70, 0x14A);
        return 0;
    }
    now = Lobby_GetTime();
    if (now < D_00585D00)
        D_00585D00 = now;
    while (now < D_00585D00 + 0x9C4) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        now = Lobby_GetTime();
    }
    D_00585D00 = 0;
    self->waitStart = now;
    if (func_00353130() < 0) {
        SFOLobby_SetError(self, 0x20, D_004C0D70, 0x163);
        return 0;
    }
    for (;;) {
        SFOLobby_CallUpdateHook(self, 1, 0);
        if (!!func_003A6650(0)) {
            SFOLobby_SetError(self, 0x3E, D_004C0D70, 0x16D);
            return 0;
        }
        if (ezNetCtlGetStatus(D_00585D40) >= 0) {
            switch (D_00585D4C) {
            case 1:
                break;
            case 3:
                return 1;
            case 2:
                break;
            case 5:
                SFOLobby_SetError(self, 0x21, D_004C0D70, 0x187);
                return 0;
            }
            if (now - self->waitStart > 60000) {
                SFOLobby_SetError(self, 2, D_004C0D70, 0x190);
                return 0;
            }
            now = Lobby_GetTime();
        } else
            return 1;
    }
}
