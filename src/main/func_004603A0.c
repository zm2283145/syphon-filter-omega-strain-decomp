#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_GetScreenList();                                
int Gui_GetScreenStack();                                
int GuiStack_SwapScreens(int, char * , int);                  
int GuiManager_AddWidget(int, int);                          
int GuiWidget_BaseWake(char * );                            
int GuiFactory_CreateWidget(char *);                             
int GuiEndGameAwards_Next(char * );                            
int GuiEndGameAwards_Layout(char * );                            
int GuiNewParts_BuildBonusList();                                  
int GuiEndGameAwards_QueueVoices(char * );                            
extern char D_004C2460;

void GuiEndGameAwards_Wake(char * arg0) {
    int temp_v0;

    GuiNewParts_BuildBonusList();
    if (F_(arg0, 0x1B4, int) == 0) {
        temp_v0 = GuiFactory_CreateWidget(&D_004C2460);
        if (temp_v0 != 0) {
            GuiManager_AddWidget(Gui_GetScreenList(), temp_v0);
            GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_v0);
        }
    } else {
        GuiWidget_BaseWake(arg0);
        GuiEndGameAwards_QueueVoices(arg0);
        F_(arg0, 0x204, signed char) = 0;
        GuiEndGameAwards_Layout(arg0);
        GuiEndGameAwards_Next(arg0);
    }
}
