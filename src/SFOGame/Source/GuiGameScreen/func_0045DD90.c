#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GuiQuickChat_Reset(int );                            
int Gui_Canvas();                                
int GuiCanvas_SetFocus(int, int );                       
int GuiWidget_SendMessage(int , int, int, int, int);                 
int GuiGameScreen_ReleaseInput(int );                            

#pragma opt_common_subs off
void GuiGameScreen_ActivateQuickChat(int arg0, int arg1) {
    int temp_v1;
    int temp_v1_2;

    temp_v1 = F_(arg0, 0x4C, int);
    if (temp_v1 != NULL) {
        if (arg1 != 0) {
            F_(temp_v1, 0x14, unsigned short) = (unsigned short) (F_(temp_v1, 0x14, unsigned short) | 2);
        } else {
            F_(temp_v1, 0x14, unsigned short) = (unsigned short) (F_(temp_v1, 0x14, unsigned short) & 0xFFFD);
        }
        if (arg1 != 0) {
            GuiQuickChat_Reset(F_(arg0, 0x4C, int));
            temp_v1_2 = F_(arg0, 0x4C, int);
            F_(temp_v1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_v1_2, 0x14, unsigned short) | 0x80);
            GuiCanvas_SetFocus(Gui_Canvas(), F_(arg0, 0x4C, int));
            GuiWidget_SendMessage(F_(arg0, 0x4C, int), Gui_Canvas(), 0x10, 2, 0);
            return;
        }
        GuiGameScreen_ReleaseInput(arg0);
    }
}
