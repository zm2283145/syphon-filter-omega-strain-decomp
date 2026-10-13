#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_GetScreenList();                                
int Gui_GetScreenStack();                                
int GuiStack_SwapScreens(int, char * , int);                  
int GuiManager_AddWidget(int, int);                          
int func_0041EFA0(char * );                            
int func_0041F960(char *);                             
int func_0045F4D0(char * );                            
int func_0045F860(char * );                            
int GuiNewParts_BuildBonusList();                                  
int func_00460450(char * );                            
extern char D_004C2460;

void func_004603A0(char * arg0) {
    int temp_v0;

    GuiNewParts_BuildBonusList();
    if (F_(arg0, 0x1B4, int) == 0) {
        temp_v0 = func_0041F960(&D_004C2460);
        if (temp_v0 != 0) {
            GuiManager_AddWidget(Gui_GetScreenList(), temp_v0);
            GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_v0);
        }
    } else {
        func_0041EFA0(arg0);
        func_00460450(arg0);
        F_(arg0, 0x204, signed char) = 0;
        func_0045F860(arg0);
        func_0045F4D0(arg0);
    }
}
