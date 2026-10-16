#include "types.h"
#include "DME.h"
/* volatile keeps the four flag stores in source order */
extern volatile unsigned char D_005723B0;
extern volatile unsigned char D_005721E0;
extern volatile unsigned char D_005721F0;
extern volatile unsigned char D_005724B0;
extern int g_DmeConnectRetries;
extern int g_DmeConnectMaxRetries;
extern char D_004BFA30[]; /* "F_TO_CREATEGAME" */
extern char D_004BF9B8[]; /* "F_TO_CONNECT" */
int Net_ConnectGame(void);
int Net_CreateGame(void);
void func_002EBCE0(int* out);
int Gui_GetScreenStack(void);
void GuiWidget_SendEvent(int a, int b, int c, int d, char* msg);

/* Joins (join != 0) or hosts a game; shows an error screen on failure. */
void Net_StartSession(int join)
{
    int ok;
    D_005723B0 = 0;
    D_005721E0 = 0;
    D_005721F0 = 0;
    D_005724B0 = DME_STATE_CONNECTING;
    if (join) {
        ok = Net_ConnectGame();
        asm { .set reorder } /* barrier: keeps the pad nop before the else label */
    } else {
        ok = Net_CreateGame();
    }
    if (ok == 0) {
        int netTime;
        func_002EBCE0(&netTime);
        return;
    }
    if (Gui_GetScreenStack()) {
        GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, join ? D_004BF9B8 : D_004BFA30);
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
}





