#include "types.h"

typedef struct Obj4C {
    char pad[0x4C];
    int handle;
} Obj4C;

extern void GuiWidget_onSleep(Obj4C*);
extern void cMap_Deactivate(int);

/* Calls GuiWidget_onSleep, releases the handle at +0x4C and clears it. */
void GuiMapScreen_onSleep(Obj4C* o) {
    GuiWidget_onSleep(o);
    cMap_Deactivate(o->handle);
    o->handle = 0;
}
