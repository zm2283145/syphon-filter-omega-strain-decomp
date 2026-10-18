#include "types.h"

typedef struct Obj4C {
    char pad[0x4C];
    int handle;
} Obj4C;

extern void GuiWidget_BaseSleep(Obj4C*);
extern void HudMap_Close(int);

/* Calls GuiWidget_BaseSleep, releases the handle at +0x4C and clears it. */
void GuiMapScreen_Sleep(Obj4C* o) {
    GuiWidget_BaseSleep(o);
    HudMap_Close(o->handle);
    o->handle = 0;
}
