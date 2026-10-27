#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00463A20 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(...); };
extern "C" {
int GuiScoresEquip_onWake(...);                            
int Gui_Manager(...);                                
void **Gui_Canvas(...);                             
int GuiManager_ConstructWidget_charP_GuiWidgetP(...);                     
int GuiEndGameStatistics_PlayQuips(...);                            
}
#pragma push
#pragma opt_common_subs off
extern "C" void GuiEndGameStatistics_onWake(char * arg0) {
    int temp_s0;
    void **temp_v0;

    F_(arg0, 0x250, int) = GuiManager_ConstructWidget_charP_GuiWidgetP(Gui_Manager(), "ENDBACK", 0);
    F_(arg0, 0x256, signed char) = 0;
    F_(arg0, 0x255, signed char) = 0;
    F_(arg0, 0x254, signed char) = 0;
    temp_s0 = F_(arg0, 0x250, int);
    if (temp_s0 != 0) {
        temp_v0 = Gui_Canvas();
        ((VC00463A20 *)(temp_v0))->v23(temp_s0, 0);
    }
    GuiScoresEquip_onWake(arg0);
    GuiEndGameStatistics_PlayQuips(arg0);
}
#pragma pop
