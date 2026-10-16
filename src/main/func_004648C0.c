#pragma cplusplus on
#include "types.h"
struct Ev48C0 { unsigned short type; unsigned short sub; unsigned short x4; unsigned short x6; unsigned short key; };
struct W48C0 { char pad[0x4C]; int m4C; };
extern int D_004FFC2C;
extern "C" {
void Hud_ToggleMap(int a);
void func_0026C130(int a);
int func_0026C180(int a);
int func_0026C3B0(int a);
void func_0026D6D0(int a);
void func_0026D710(int a);
int Gui_GetScreenStack(void);
void GuiWidget_SendEvent(W48C0* self, int a, int b, int c, int d);
}
extern "C" int func_004648C0(W48C0* self, Ev48C0* e)
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
            func_0026C130(self->m4C);
            break;
        case 8:
            func_0026D710(self->m4C);
            if (func_0026C3B0(self->m4C))
                GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 0, 0);
            break;
        case 4:
            func_0026D710(self->m4C);
            if (func_0026C180(self->m4C))
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
                func_0026D6D0(self->m4C);
                return 1;
            }
        }
    }
    return 0;
}

