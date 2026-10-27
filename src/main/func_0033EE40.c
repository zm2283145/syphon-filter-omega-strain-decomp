#include "types.h"
typedef struct { char pad[0xA8]; int fa8; char pad2[0x54]; int f100; } O33E;
extern int cDME_GetLobby(void);
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern char* GuiLobbyScreen_GetLobbyString(O33E*, int, int, int, int, int);
extern void GuiKeyboard_Display(void*, char*, char*, O33E*, int, int, int);
extern char D_004B9C60[];
void GuiMissionLobbyScreen_SelectAgentChat(O33E* o, int* p) {
    void* w;
    if (!o->fa8 || !cDME_GetLobby()) return;
    o->f100 = p ? *p : 0;
    w = GuiManager_OpenGui(Gui_Manager(), "GuiKeyboard", "KEYBOARD");
    if (w) GuiKeyboard_Display(w, GuiLobbyScreen_GetLobbyString(o, 0x64, 0, 0, 0, 0), D_004B9C60, o, 0x40, 0x1D, 0);
}
