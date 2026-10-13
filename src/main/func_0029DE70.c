#include "types.h"
typedef struct { int a[4]; } S29D;
typedef struct { char pad[0x94]; unsigned char b94; } O29D;
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, O29D*, void*);
extern int DME_GetLobby(void);
extern void SFOLobby_LeaveNetworkState(int);
extern int D_004FFC04;
extern void func_002CA640(int, int);
extern char* func_0033CE30(O29D*, int, int, int, int, int);
extern void String_CtorCStr_13B480(S29D*, char*);
extern char* String_CStr(S29D*);
extern void FrontEnd_OpenPopup(int, int, char*, char*, int, int);
extern void String_Dtor(S29D*, int);
void func_0029DE70(O29D* o, int show) {
    void* w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
    if (o->b94) {
        if (DME_GetLobby()) SFOLobby_LeaveNetworkState(DME_GetLobby());
        o->b94 = 0;
    }
    func_002CA640(D_004FFC04, 1);
    if (show) {
        S29D a;
        S29D b;
        String_CtorCStr_13B480(&a, func_0033CE30(o, 0xB, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(o, 0x84, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
}
