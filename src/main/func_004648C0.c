#pragma cplusplus on
#include "types.h"
struct Ev48C0 { unsigned short type; unsigned short sub; unsigned short x4; unsigned short x6; unsigned short key; };
struct W48C0 { char pad[0x4C]; int m4C; };
extern int D_004FFC2C;
extern "C" {
void Hud_ToggleMap(int a);
void HudMap_Reset(int a);
int HudMap_PrevMarker(int a);
int HudMap_NextMarker(int a);
void HudMap_Release(int a);
void HudMap_Hold(int a);
int Gui_GetScreenStack(void);
void GuiWidget_SendEvent(W48C0* self, int a, int b, int c, int d);
}
extern "C" int GuiMapScreen_HandleInput(W48C0* self, Ev48C0* e)
{
    bool press = false;
    bool down = false;
    if (e->type == 1 && e->sub == 0)
        down = true;
    if (down && e->x6 == 0)
        press = true;
    if (press) {
        switch (e->key) {
        case 0x10:
            Hud_ToggleMap(D_004FFC2C);
            break;
        case 0x100:
            HudMap_Reset(self->m4C);
            break;
        case 8:
            HudMap_Hold(self->m4C);
            if (HudMap_NextMarker(self->m4C))
                GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 0, 0);
            break;
        case 4:
            HudMap_Hold(self->m4C);
            if (HudMap_PrevMarker(self->m4C))
                GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 0, 0);
            break;
        default:
            return 0;
        }
        return 1;
    }
    {
        bool r = e->type == 1 && e->sub == 0 && e->x6 == 1;
        if (r) {
            switch (e->key) {
            case 8:
            case 4:
                HudMap_Release(self->m4C);
                return 1;
            }
        }
    }
    return 0;
}

