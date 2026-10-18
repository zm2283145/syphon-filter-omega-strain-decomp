#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00463980 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int GuiScoresEquip_HandleEvent(...);                                
int Gui_GetScreenList(...);                                
void **Gui_GetScreenStack(...);                             
int GuiStack_SwapScreens(...);              
int GuiManager_FindOrLoad(...);                   
extern char D_004C2780;
extern char D_004C2798;
}
extern "C" int GuiEndGameStatistics_HandleEvent(char * arg0, int d1, int arg2) {
    int temp_s0;
    void **temp_v0;

    if ((arg2 & 0xFFFF) == 2) {
        temp_v0 = Gui_GetScreenStack();
        ((VC00463980 *)(temp_v0))->v24(F_(arg0, 0x250, int));
        temp_s0 = GuiManager_FindOrLoad(Gui_GetScreenList(), &D_004C2780, &D_004C2798);
        GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_s0);
        return 1;
    }
    return GuiScoresEquip_HandleEvent();
}
