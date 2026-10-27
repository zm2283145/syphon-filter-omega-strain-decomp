#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int GuiWidget_onRender();                            
int GuiGameScreen_DrawWeaponPanelText();                            
int GuiGameScreen_WeaponRestoreTransparency();                            
int GuiGameScreen_WeaponSaveTransparency();                                  
extern char * g_Hud;

void GuiGameScreen_onRender(char * arg0) {
    if (F_(g_Hud, 0x6A8, unsigned char) == 0) {
        if (F_(F_(arg0, 0x6C, int), 0x14, unsigned short) & 2) {
            GuiGameScreen_WeaponSaveTransparency();
            GuiWidget_onRender(arg0);
            GuiGameScreen_WeaponRestoreTransparency(arg0);
            if (F_(arg0, 0xD4, int) == 1) {
                GuiGameScreen_DrawWeaponPanelText(arg0);
            }
        } else {
            GuiWidget_onRender();
        }
    }
}
