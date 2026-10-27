#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_Manager();                                
int Gui_Canvas();                                
int GuiCanvas_Transition(int, char * , int);                  
int GuiManager_Add(int, int);                          
int GuiWidget_onWake(char * );                            
int AbstractWidgetClassRep_Create(char *);                             
int GuiEndGameAwards_ActivateNextAward(char * );                            
int GuiEndGameAwards_PositionAwards(char * );                            
int GuiEndGameAwards_PopulateAwards();                                  
int GuiEndGameAwards_PlayQuips(char * );                            
extern char D_004C2460;

void GuiEndGameAwards_onWake(char * arg0) {
    int temp_v0;

    GuiEndGameAwards_PopulateAwards();
    if (F_(arg0, 0x1B4, int) == 0) {
        temp_v0 = AbstractWidgetClassRep_Create(&D_004C2460);
        if (temp_v0 != 0) {
            GuiManager_Add(Gui_Manager(), temp_v0);
            GuiCanvas_Transition(Gui_Canvas(), arg0, temp_v0);
        }
    } else {
        GuiWidget_onWake(arg0);
        GuiEndGameAwards_PlayQuips(arg0);
        F_(arg0, 0x204, signed char) = 0;
        GuiEndGameAwards_PositionAwards(arg0);
        GuiEndGameAwards_ActivateNextAward(arg0);
    }
}
