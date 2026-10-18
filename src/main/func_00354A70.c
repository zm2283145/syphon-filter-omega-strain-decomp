#include "types.h"
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E354A70;
typedef struct { char pad[0x94]; unsigned char a94; char pad95[0x1AB]; int a240; } S354A70;
extern "C" {
void* Gui_GetScreenStack(void);
void GuiWidget_SendEvent(void* self, void* mgr, int a, int b, int c);
void GuiPersonnelMenu_ToggleDetail(S354A70* self, int on);
bool GuiPersonnelScreen_HandleInput(void* self, E354A70* e);
bool GuiPersonnelMenu_HandleInput(S354A70* self, E354A70* e);
}
bool GuiPersonnelMenu_HandleInput(S354A70* self, E354A70* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x40 && e->a6 == 0;
    if (b) {
        if (self->a94) {
            GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 2, 0);
            if (self->a240 == 0) GuiPersonnelMenu_ToggleDetail(self, 1);
            else GuiPersonnelMenu_ToggleDetail(self, 0);
        }
        return 1;
    }
    return GuiPersonnelScreen_HandleInput(self, e);
}