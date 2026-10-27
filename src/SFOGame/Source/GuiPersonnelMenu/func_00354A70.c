#include "types.h"
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E354A70;
typedef struct { char pad[0x94]; unsigned char a94; char pad95[0x1AB]; int a240; } S354A70;
extern "C" {
void* Gui_Canvas(void);
void GuiWidget_SendMessage(void* self, void* mgr, int a, int b, int c);
void GuiPersonnelMenu_SetMode(S354A70* self, int on);
bool GuiPersonnelScreen_onInput(void* self, E354A70* e);
bool GuiPersonnelMenu_onInput(S354A70* self, E354A70* e);
}
bool GuiPersonnelMenu_onInput(S354A70* self, E354A70* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x40 && e->a6 == 0;
    if (b) {
        if (self->a94) {
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
            if (self->a240 == 0) GuiPersonnelMenu_SetMode(self, 1);
            else GuiPersonnelMenu_SetMode(self, 0);
        }
        return 1;
    }
    return GuiPersonnelScreen_onInput(self, e);
}