#pragma cplusplus on
#include "types.h"

struct MenuScreen {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void Pick0(void* item);
    virtual void Pick1(void* item, int b);
    virtual void Pick2(void* item);
    virtual void Pick3(void* item);
    char pad4[0x10];
    unsigned short flags;   /* 0x14 */
    char pad16[0x88 - 0x16];
    void* list;             /* 0x88 */
    void* f8C;
    int mode;               /* 0x90 */
    int pad94;
    void* bt98;             /* 0x98 */
    void* bt9C;             /* 0x9C */
    void* btA0;             /* 0xA0 */
    void* btA4;             /* 0xA4 */
    int enabled;            /* 0xA8 */
    char padAC[0x100 - 0xAC];
    int lobbyId;            /* 0x100 */
    char pad104[0xC];
    char name[4];           /* 0x110 */
};

struct MenuScreen2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void Join(void* name, int a);
};

typedef struct { char pad[0x32]; unsigned char busy; } FrontEnd;

extern "C" {
extern FrontEnd* D_004FFC04;
extern char D_004B9C60[];
extern int D_00532FF8;
extern char* D_00533000;
extern unsigned char D_00532FF0;
void GuiMissionList_SetSelectMode(void* list, int mode);
int GuiMissionLobbyScreen_ButtonAction(MenuScreen* o, void* w, int v);
void* GuiMissionList_GetAgentElemFromIndex(void* list, char* data);
int GuiMissionList_CanSelectAgent(void* list, void* item);
int cDME_GetLobby(void);
int SFOLobby_SendChat(int lobby, char* data, int id);
char* GuiLobbyScreen_GetLobbyString(MenuScreen* o, int a, char* b, char* c, int d, int e);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, void* d, int e);
int GuiLobbyScreen_onMessage(MenuScreen* o, void* w, unsigned short kind, int code, char* data);
}

/* Menu screen event handler: tab buttons select the list mode, a list pick goes to the
 * per-mode virtual (mode 1 takes a flag, retail passes 1 in a2), lobby join / name-entry
 * events, deferred event 30; everything else goes to GuiLobbyScreen_onMessage. */
extern "C" int GuiMissionLobbyScreen_onMessage(MenuScreen* o, void* w, unsigned short kind, int code, char* data)
{
    if (kind == 0 && o->list) {
        if (w == o->bt9C) {
            GuiMissionList_SetSelectMode(o->list, 0);
            return 1;
        }
        if (w == o->bt98) {
            GuiMissionList_SetSelectMode(o->list, 2);
            return 1;
        }
        if (w == o->btA0) {
            GuiMissionList_SetSelectMode(o->list, 1);
            return 1;
        }
        if (w == o->btA4) {
            GuiMissionList_SetSelectMode(o->list, 3);
            return 1;
        }
        if (w != o->list) {
            GuiMissionList_SetSelectMode(o->list, 1);
            return 1;
        }
    }
    if (kind == 2 && GuiMissionLobbyScreen_ButtonAction(o, w, 1)) return 1;
    if (w == o->list && kind == 19) {
        void* item;
        if (!o->enabled) return 1;
        item = GuiMissionList_GetAgentElemFromIndex(o->list, data);
        if (!item || !(GuiMissionList_CanSelectAgent(o->list, item) & 1)) return 1;
        if (o->mode == 0) o->Pick0(item);
        else if (o->mode == 1) o->Pick1(item, 1);
        else if (o->mode == 2) o->Pick2(item);
        else if (o->mode == 3) o->Pick3(item);
        return 1;
    }
    if (kind == 26 || kind == 27) {
        if (code == 29) {
            if (o->lobbyId != -1 && data && *data) {
                if (!cDME_GetLobby() || !SFOLobby_SendChat(cDME_GetLobby(), data, o->lobbyId)) {
                    FrontEnd* dlg = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(dlg, 2, D_004B9C60, GuiLobbyScreen_GetLobbyString(o, 101, 0, 0, 0, 0), 0, 0);
                }
            }
            return 1;
        }
        if (code == 30 && kind == 26) {
            ((MenuScreen2*)o)->Join(o->name, 0);
            return 1;
        }
    }
    if (kind == 30 && !D_004FFC04->busy) {
        if (!(o->flags & 2)) return 0;
        D_00532FF8 = code;
        D_00533000 = data;
        D_00532FF0 = 1;
        return 1;
    }
    return GuiLobbyScreen_onMessage(o, w, kind, code, data);
}
