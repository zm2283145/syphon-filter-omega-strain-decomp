#include "types.h"
#pragma cplusplus on
struct S33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual void v24(); };
struct V33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; } W33;
typedef struct { char pad[0x248]; int f248; } G33;
typedef struct { char pad[0x84]; int f84; } O33;
extern "C" {
extern G33* D_004FFC04;
extern char D_004B99D8[];
extern char* GuiLobbyScreen_GetLobbyString(O33*, int, char*, char*, int, int);
extern int cGameFrontEnd_PushMessageBox(G33*, int, char*, char*, int, int);
extern void FrontEnd_StartSplashThread(G33*);
extern void FrontEnd_StopSplashThread(G33*);
extern void cGameFrontEnd_PopMessageBox(G33*, int);
extern int Gui_Manager(void);
extern W33* GuiManager_OpenGui(int, char*, char*);
extern void GuiManager_CloseGui(int, W33*);
extern int cDME_GetLobby(void);
extern int SFOLobby_CheckMissionLobby(int, int);
extern int SFOLobby_CellIsPlayerInCell(int);
extern V33* Gui_Canvas(void);
extern void GuiWidget_SendMessage(W33*, V33*, int, int, int);
}
extern "C" int GuiLobbyScreen_PushLobbyScreen(O33* self, int type) {
    int c = -1;
    int h;
    W33* w;
    switch (type) {
    case 1: c = 0x78; break;
    case 3: c = 0x7A; break;
    case 4: c = 0x7B; break;
    case 9: c = 0x7C; break;
    case 2: c = 0x79; break;
    case 6: c = 0x79; break;
    }
    if (type == 1 && self->f84 == 9) c = -1;
    h = -1;
    if (c != -1) {
        G33* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, 0, 0, 0, 0), 0, 0);
        FrontEnd_StartSplashThread(D_004FFC04);
    }
    w = 0;
    switch (type) {
    case 0: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineConnect", "ONLINECN"); break;
    case 1: w = GuiManager_OpenGui(Gui_Manager(), "GuiCommandCenter", "CMDCENTR"); break;
    case 2: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetJoinMission", "JOINMIS"); break;
    case 6: w = GuiManager_OpenGui(Gui_Manager(), "GuiMissionSetup", "MSNSETUP"); break;
    case 3: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetAgencyCell", "AGENTCEL"); break;
    case 4: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetContacts", "CONTACTS"); break;
    case 5: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineOptions", "ONLIPREF"); break;
    case 9: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetMessages", "NETMESS"); break;
    case 7: w = GuiManager_OpenGui(Gui_Manager(), "GuiAccountLogin", "ACNTLOGN"); break;
    }
    if (c != -1) FrontEnd_StopSplashThread(D_004FFC04);
    if (w) {
        if (type == 6 || type == 2) {
            int x = D_004FFC04->f248;
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CheckMissionLobby(p, x)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 3) {
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CellIsPlayerInCell(p)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 0 || type == 7) w->f10 = 1;
    }
    ((S33*)self)->v24();
    if (w) {
        V33* m;
        w->flags &= ~2;
        m = Gui_Canvas();
        m->v23(w, 0);
    }
    Gui_Canvas()->v24(self);
    if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    if (w) {
        w->flags |= 2;
        GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 2, 0);
    }
    return 1;
}
