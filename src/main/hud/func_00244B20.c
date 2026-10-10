#include "types.h"
typedef struct { char pad[0x74]; void* widget; } Hud;
extern void func_003F45A0(void* w, float v);
extern void func_003F44E0(void* w, float v);
/* Positions the widget based on the row index. */
void func_00244B20(Hud* h, unsigned char row)
{
    if (h->widget) {
        int y = row * 30 + 200;
        func_003F45A0(h->widget, y);
        func_003F44E0(h->widget, y + 10);
    }
}
