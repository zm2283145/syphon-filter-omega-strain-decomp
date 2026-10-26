/*
 * main/GuiGameScreen: 4 files, 00465570-004657E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00465570 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char p[0x6C]; float f6C; } W465570;
extern void GuiCanvas_PushScreen(W465570* w);
extern void* GuiWidget_FindChildByName(void* x, int key);
extern void GuiWidget_SendEvent(void* w, void* src, int kind, int a, int b);
extern char D_004C28F8[];
static int D_00497BE0 = (int)D_004C28F8;
void GuiGameCanvas_PushScreen(W465570* w, void* x)
{
    GuiCanvas_PushScreen(w);
    if (x) {
        void* o = GuiWidget_FindChildByName(x, D_00497BE0);
        if (o) {
            GuiWidget_SendEvent(w, o, 10, (int)w->f6C, 0);
            GuiWidget_SendEvent(w, o, 0xD, 0, 300);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00465570 */

/* merge_units: begin func_00465600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */


extern int GuiCanvas_Navigate(int, int);

int GuiFrontendCanvas_HandleInput(int a0, int a1) {
    return GuiCanvas_Navigate(a0, a1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00465600 */

/* merge_units: begin func_00465610 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ui_00465610 { char pad[0x33]; unsigned char f33; char pad34; unsigned char f35; };
extern "C" {
extern Ui_00465610* D_004FFC04;
extern signed char g_GameState;
extern signed char g_PrevGameState;
extern unsigned char g_GuiSoundGate;
extern char D_004C2988[];
extern char D_00586AF0[];
extern char D_00586C90[];
extern char D_00586E30[];
extern char D_00586FD0[];
extern char D_00587170[];
char* Loc_LookupText(int key);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
int GuiWidget_BroadcastEvent(void* self, int message, int first, int second);
int GuiCommonCanvas_onMessage(void* self, void* sender, int message, int first, int second);
int GuiSound_Stop(void* sender, char* tbl, int message);
int GuiSound_Play(void* sender, char* tbl, int message);
}
extern "C" int GuiFrontendCanvas_OnEvent(void* self, void* sender, int message, int first, int second)
{
    unsigned short m = message;
    if (m == 0x1E) {
        if (!GuiWidget_BroadcastEvent(self, message, first, second)) {
            if ((first != 0) == 1) {
                g_PrevGameState = g_GameState;
                g_GameState = 3;
            } else {
                D_004FFC04->f35 = 0;
                D_004FFC04->f33 = 0;
                { Ui_00465610* ui = D_004FFC04; FrontEnd_OpenPopup(ui, 2, D_004C2988, Loc_LookupText(second), 0, 0); }
            }
        }
        return 1;
    }
    if (m == 0x10 || m == 0x11) {
        char* tbl;
        if (g_GuiSoundGate)
            return 1;
        tbl = 0;
        switch (first) {
        case 5: tbl = D_00586AF0; break;
        case 6: tbl = D_00586C90; break;
        case 7: tbl = D_00586E30; break;
        case 8: tbl = D_00586FD0; break;
        case 9: tbl = D_00587170; break;
        }
        if (tbl) {
            if (m == 0x10)
                return GuiSound_Play(sender, tbl, message);
            else
                return GuiSound_Stop(sender, tbl, message);
        }
    }
    return GuiCommonCanvas_onMessage(self, sender, message, first, second);
}
#pragma pop /* merge_units */
/* merge_units: end func_00465610 */

/* merge_units: begin func_004657E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLibInit_RequestCancel(int);                                 
int func_00465A40();                                  
extern unsigned char g_DebugTriangle;

void GuiCanvas_HandlePad(int d0, char * arg1) {
    int var_v1;

    if (g_DebugTriangle != 0) {
        var_v1 = F_(arg1, 0x0, unsigned short) == 1;
        if (var_v1 != 0) {
            var_v1 = F_(arg1, 0x2, unsigned short) == 0;
        }
        var_v1 = var_v1 ? F_(arg1, 0x8, unsigned short) == 0x10 : var_v1;
        if (var_v1 != 0) {
            var_v1 = F_(arg1, 0x6, unsigned short) == 0;
        }
        if (var_v1 != 0) {
            SFOLibInit_RequestCancel(1);
        }
        return;
    }
    func_00465A40();
}
#pragma pop /* merge_units */
/* merge_units: end func_004657E0 */
