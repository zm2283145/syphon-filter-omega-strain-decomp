#include "types.h"

typedef struct Settings2E {
    char pad00[0x2E];
    unsigned char altMode; /* 0x2E */
} Settings2E;

extern Settings2E* D_004FFC04;
extern void* Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(void* lib, const char* a, const char* b);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void* mgr, int arg, void* res);

/* Looks up the mode-dependent resource and hands it to the manager. */
void func_002928E0(int arg) {
    void* res;
    if (D_004FFC04->altMode) {
        res = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "CMDCENTR");
    } else {
        res = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "onoffsel");
    }
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, res);
}
