#include "types.h"
typedef struct { char pad[0x32]; unsigned char flag; } Game;
typedef struct { char pad[0x10]; int enabled; } Item;
extern Game* D_004FFC04;
extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern void func_002CCA20(Game*, int);
extern void* Gui_GetScreenList(void);
extern Item* GuiManager_FindOrLoad(void*, const char*, const char*);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void*, void*, Item*);
/* Resets the game flag, creates a UI item and adds it with the given argument. */
void func_002A0440(void* arg)
{
    Item* item;
    func_002CCA20(D_004FFC04, 0);
    D_004FFC04->flag = 0;
    item = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
    item->enabled = 1;
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, item);
}
