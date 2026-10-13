#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Gui_GetScreenList();                                
int Gui_GetScreenStack();                                
int GuiStack_SwapScreens(int, int , int);                  
int func_00418A80(int, int *, int *);                   
int func_00456160();                                  

void func_00299780(int arg0) {
    int temp_s0;

    if (F_(arg0, 0x400, unsigned char) != 0) {
        func_00456160();
        return;
    }
    temp_s0 = func_00418A80(Gui_GetScreenList(), ((int*)"GuiTitleScreen"), ((int*)"TITLESCR"));
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_s0);
}
