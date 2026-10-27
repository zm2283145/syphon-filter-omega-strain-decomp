/*
 * Libs/SFOLib/Source/DME: 1 file, 0042A870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A870 */
#pragma push /* merge_units */
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
void NetGetTime(int* out);
int Gui_Canvas(void);
void GuiWidget_SendMessage(int a, int b, int c, int d, char* msg);

/* Joins (join != 0) or hosts a game; shows an error screen on failure. */
void cDME_ConnectToGame(int join)
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
        NetGetTime(&netTime);
        return;
    }
    if (Gui_Canvas()) {
        GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 0x1E, 0, join ? D_004BF9B8 : D_004BFA30);
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
}
static inline void merge_flush_func_0042A870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A870 */
