#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_Manager();                                
int Gui_Canvas();                                
int GuiCanvas_Transition(int, int, int);                     
int GuiManager_Add(int, int);                          
int AbstractWidgetClassRep_Create(char *);                             
int GuiEndGameAwards_ActivateNextAward(int);                             
extern char D_004C2460;

int GuiEndGameAwards_onInput(int arg0, char * arg1) {
    int temp_v0;
    int var_v0;

    var_v0 = F_(arg1, 0x0, unsigned short) == 1;
    if (var_v0 != 0) {
        var_v0 = F_(arg1, 0x2, unsigned short) == 0;
    }
    var_v0 = var_v0 ? F_(arg1, 0x8, unsigned short) == 0x40 : var_v0;
    if (var_v0 != 0) {
        var_v0 = F_(arg1, 0x6, unsigned short) == 0;
    }
    if (var_v0 != 0) {
        if (GuiEndGameAwards_ActivateNextAward(arg0) == 0) {
            temp_v0 = AbstractWidgetClassRep_Create(&D_004C2460);
            if (temp_v0 != 0) {
                GuiManager_Add(Gui_Manager(), temp_v0);
                GuiCanvas_Transition(Gui_Canvas(), arg0, temp_v0);
            }
        }
        return 1;
    }
    return 0;
}
