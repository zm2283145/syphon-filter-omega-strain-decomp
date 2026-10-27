/*
 * SFOGame/Source/GuiMissionLobbyScreen: 1 file, 0033E410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033E410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V33E4 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); };
typedef struct { char pad[0x10]; void* f10; } W33E4;
typedef struct { int f0; char name[4]; } I33E4;
typedef struct { char pad[0x14]; unsigned short flags; char pad2[0x92]; int fa8; } O33E4;
extern "C" {
extern int cDME_GetLobby(void);
extern int SFOLobby_GetAgentInfo(int, int, char*);
extern int D_004FFC04;
extern char D_004B9C60[];
extern char* GuiLobbyScreen_GetLobbyString(O33E4*, int, char*, int, int, int);
extern int cGameFrontEnd_PushMessageBox(int, int, char*, char*, int, int);
extern void FrontEnd_StartSplashThread(int);
extern void FrontEnd_StopSplashThread(int);
extern int Gui_Manager(void);
extern W33E4* GuiManager_OpenGui(int, char*, char*);
extern void GuiAgentInfo_DisplayRemoteAgent(W33E4*, I33E4*, char*);
extern V33E4* Gui_Canvas(void);
extern void cGameFrontEnd_PopMessageBox(int, int);
}
extern "C" void GuiMissionLobbyScreen_SelectAgentInfo(O33E4* o, I33E4* info) {
    char buf[0x100];
    if (!o->fa8 || !cDME_GetLobby()) return;
    if (SFOLobby_GetAgentInfo(cDME_GetLobby(), info->f0, buf)) {
        int g = D_004FFC04;
        int h = cGameFrontEnd_PushMessageBox(g, 0, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, 0x7D, info->name, 0, 0, 0), 0, 0);
        W33E4* w;
        FrontEnd_StartSplashThread(D_004FFC04);
        w = GuiManager_OpenGui(Gui_Manager(), "GuiAgentInfo", "AGNTINFO");
        FrontEnd_StopSplashThread(D_004FFC04);
        if (w) {
            w->f10 = o;
            GuiAgentInfo_DisplayRemoteAgent(w, info, buf);
        }
        o->flags &= ~2;
        Gui_Canvas()->v23(w, 0x14);
        cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    } else {
        int g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, 0x67, 0, 0, 0, 0), 0, 0);
    }
}
static inline void merge_flush_func_0033E410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033E410 */
