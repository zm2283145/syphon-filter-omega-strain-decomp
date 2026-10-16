#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int GuiWidget_Draw();                            
int func_0045C0F0();                            
int func_0045D710();                            
int func_0045D7F0();                                  
extern char * D_004FFC2C;

void GuiGameScreen_Draw(char * arg0) {
    if (F_(D_004FFC2C, 0x6A8, unsigned char) == 0) {
        if (F_(F_(arg0, 0x6C, int), 0x14, unsigned short) & 2) {
            func_0045D7F0();
            GuiWidget_Draw(arg0);
            func_0045D710(arg0);
            if (F_(arg0, 0xD4, int) == 1) {
                func_0045C0F0(arg0);
            }
        } else {
            GuiWidget_Draw();
        }
    }
}
