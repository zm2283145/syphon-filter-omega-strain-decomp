#include "types.h"
typedef struct { char pad[0x88]; int h; } F296A80_Obj;
extern int GuiWidget_SendMessage(void* o, int a, int b, int c, int d);
extern int Gui_Canvas(void);
void GuiCommandCenter_UpdateBackground(F296A80_Obj* o, float t) {
    float tab[11] = { 34.0f, 159.0f, 280.0f, 397.0f, 509.0f, 621.0f, 723.0f, 824.0f, 928.0f, 1009.0f, 1108.0f };
    if (o->h != 0) {
        float cur = 0.0f;
        int i;
        GuiWidget_SendMessage(o, o->h, 9, (int)&cur, 0);
        for (i = 0; i < 11; i++) {
            if (cur < tab[i] && !(cur + t < tab[i])) {
                GuiWidget_SendMessage(o, Gui_Canvas(), 16, 8, 0);
                return;
            }
        }
    }
}
