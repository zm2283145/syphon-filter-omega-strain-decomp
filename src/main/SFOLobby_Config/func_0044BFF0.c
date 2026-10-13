#include "SFOLobby.h"
extern int func_003531B8(SFOLobby *);
extern void SFOLobby_SetError(SFOLobby *, int, const char *, int);
extern int Lobby_GetTime(void);
extern void SFOLobby_CallUpdateHook(SFOLobby *, int, int);
extern int ezNetCtlGetStatus(void *);
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern int D_00585D00;    /* time the network was last brought down */
extern char D_00585D40[]; /* ezNetCtl status buffer */
extern int D_00585D4C;    /* ezNetCtl state: 5 = down */

/* Stops the network and waits (60 s timeout) until it reports down. */
int SFOLobby_NetDown(SFOLobby *a) {
    int t;
    if (func_003531B8(a) < 0) {
        SFOLobby_SetError(a, 0x20, D_004C0D70, 0x11A);
        return 0;
    }
    a->waitStart = t = Lobby_GetTime();
    D_00585D00 = t;
    for (;;) {
        SFOLobby_CallUpdateHook(a, 0, 0);
        if (ezNetCtlGetStatus(D_00585D40) < 0 || D_00585D4C == 5) {
            break;
        }
        if (t - a->waitStart > 60000) {
            SFOLobby_SetError(a, 2, D_004C0D70, 0x134);
            return 0;
        }
        t = Lobby_GetTime();
    }
    return 1;
}
