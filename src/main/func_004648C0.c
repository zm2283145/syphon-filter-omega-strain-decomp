#pragma cplusplus on
#include "types.h"
struct Ev48C0 { unsigned short type; unsigned short sub; unsigned short x4; unsigned short x6; unsigned short key; };
struct W48C0 { char pad[0x4C]; int m4C; };
extern int g_Hud;
extern "C" {
void cHud_ToggleMap(int a);
void cMap_ResetCamera(int a);
int cMap_PreviousObjective(int a);
int cMap_NextObjective(int a);
void cMap_StopSeekCountdown(int a);
void cMap_StartSeekCountdown(int a);
int Gui_Canvas(void);
void GuiWidget_SendMessage(W48C0* self, int a, int b, int c, int d);
}
extern "C" int GuiMapScreen_onInput(W48C0* self, Ev48C0* e)
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
            cHud_ToggleMap(g_Hud);
            break;
        case 0x100:
            cMap_ResetCamera(self->m4C);
            break;
        case 8:
            cMap_StartSeekCountdown(self->m4C);
            if (cMap_NextObjective(self->m4C))
                GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
            break;
        case 4:
            cMap_StartSeekCountdown(self->m4C);
            if (cMap_PreviousObjective(self->m4C))
                GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 0, 0);
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
                cMap_StopSeekCountdown(self->m4C);
                return 1;
            }
        }
    }
    return 0;
}

