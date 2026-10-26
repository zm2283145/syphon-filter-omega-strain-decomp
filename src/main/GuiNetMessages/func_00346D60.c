#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W_46D60;
typedef struct { char pad[0x8C]; void* x8C; W_46D60* x90; void* x94; int x98; int x9C; } S_46D60;
extern char D_004BA310[];
extern char D_004BA328[];
extern char D_004BA338[];
extern void* D_004FFC04;
extern int Gui_GetScreenList(void);
extern int Gui_GetScreenStack(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern void* DME_GetLobby(void);
extern int GuiScreen_GetLobbyString(S_46D60*, int, int, int, int, int);
extern int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, void* d, int e);
extern void FrontEnd_ClosePopup(void* ui, int p);
extern void FrontEnd_LeaveOnline(void* ui, int a);
extern void GuiStack_SwapScreens(int, S_46D60*, void*);
extern int SFOLobby_MessageGet(void* l, int id);
extern void GuiNetMessages_MessageSelected(S_46D60* s, int x);
extern void SFOLobby_MessageAck(void* l, int id, int ok);
extern void LobbyArray_SetDirty(void* l, int a);
extern int GuiScreen_HandleEvent(S_46D60* s, void* from, unsigned short ev, int kind, int data);
int GuiNetMessages_HandleEvent(S_46D60* self, void* from, unsigned short ev, int kind, int data)
{
    if (kind == 0x19 && ev == 0x1A) {
        void* scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004BA310, D_004BA328);
        if (DME_GetLobby()) {
            void* ui = D_004FFC04;
            int p = FrontEnd_OpenPopup(ui, 0, D_004BA338, GuiScreen_GetLobbyString(self, 0x77, 0, 0, 0, 0), 0, 0);
            FrontEnd_LeaveOnline(D_004FFC04, 1);
            FrontEnd_ClosePopup(D_004FFC04, p);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->x9C);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, scr);
        return 1;
    }
    if (ev == 0x14) {
        void* l = DME_GetLobby();
        if (l) {
            self->x98 = data;
            GuiNetMessages_MessageSelected(self, SFOLobby_MessageGet(l, self->x98));
        }
        return 1;
    }
    if (ev == 2) {
        void* l = DME_GetLobby();
        if (l && SFOLobby_MessageGet(l, self->x98)) {
            if (from == self->x8C || from == self->x94) {
                SFOLobby_MessageAck(l, self->x98, !(self->x90->flags & 2));
                LobbyArray_SetDirty((char*)l + 0x1C, 1);
                return 1;
            }
            if (from == self->x90) {
                SFOLobby_MessageAck(l, self->x98, 1);
                LobbyArray_SetDirty((char*)l + 0x1C, 1);
                return 1;
            }
        }
    }
    return GuiScreen_HandleEvent(self, from, ev, kind, data);
}
