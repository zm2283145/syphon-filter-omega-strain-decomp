#include "types.h"
typedef struct { char pad[0x2E]; unsigned char b2e; char p2f; unsigned char b30; char p31; unsigned char b32; } G295;
typedef struct { char pad[0x2F4]; unsigned char b2f4; } O295;
extern G295* D_004FFC04;
extern char D_004AA288[];
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern char* func_0033CE30(O295*, int, int, int, int, int);
extern int FrontEnd_OpenPopup(G295*, int, char*, char*, int, int);
extern void func_002CA640(G295*, int);
extern void FrontEnd_ClosePopup(G295*, int);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, O295*, void*);
extern void func_002982C0(O295*);
void func_00295430(O295* o) {
    void* w;
    G295* g;
    if (!o->b2f4) return;
    g = D_004FFC04;
    if (g->b30 && !g->b32) {
        int h;
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
        {
            G295* m = D_004FFC04;
            h = FrontEnd_OpenPopup(m, 0, D_004AA288, func_0033CE30(o, 0x77, 0, 0, 0, 0), 0, 0);
        }
        func_002CA640(D_004FFC04, 1);
        FrontEnd_ClosePopup(D_004FFC04, h);
    } else if (g->b2e) {
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiTitleScreen", "TITLESCR");
    } else {
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    }
    if (w) {
        GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        func_002982C0(o);
    }
    o->b2f4 = 0;
}
