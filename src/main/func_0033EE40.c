#include "types.h"
typedef struct { char pad[0xA8]; int fa8; char pad2[0x54]; int f100; } O33E;
extern int DME_GetLobby(void);
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern char* GuiScreen_GetLobbyString(O33E*, int, int, int, int, int);
extern void GuiKeyboard_Open(void*, char*, char*, O33E*, int, int, int);
extern char D_004B9C60[];
void GuiMenuScreen_OpenKeyboard(O33E* o, int* p) {
    void* w;
    if (!o->fa8 || !DME_GetLobby()) return;
    o->f100 = p ? *p : 0;
    w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiKeyboard", "KEYBOARD");
    if (w) GuiKeyboard_Open(w, GuiScreen_GetLobbyString(o, 0x64, 0, 0, 0, 0), D_004B9C60, o, 0x40, 0x1D, 0);
}
