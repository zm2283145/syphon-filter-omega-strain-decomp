#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_GetScreenList();                                
int Gui_GetScreenStack();                                
int GuiStack_SwapScreens(int, int, int);                     
int GuiManager_AddWidget(int, int);                          
int func_0041F960(char *);                             
int func_0045F4D0(int);                             
extern char D_004C2460;

int func_0045F3F0(int arg0, char * arg1) {
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
        if (func_0045F4D0(arg0) == 0) {
            temp_v0 = func_0041F960(&D_004C2460);
            if (temp_v0 != 0) {
                GuiManager_AddWidget(Gui_GetScreenList(), temp_v0);
                GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_v0);
            }
        }
        return 1;
    }
    return 0;
}
