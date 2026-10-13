#include "types.h"

typedef struct { char pad[0x4C]; int id; } Slot;
extern int sprintf(char* buf, const char* fmt, ...);
extern int GuiWidget_FindChildByName(void* self, const char* name);
extern void func_0041F150(void* self);

/* Looks up four numbered children by name into the ids at +0x4C, then finishes setup. */
void func_002B1B30(void* self)
{
    char buf[0x20];
    Slot* slot;
    int i;
    for (i = 0, slot = (Slot*)self; i < 4; i++) {
        sprintf(buf, "dpad%d", i);
        slot->id = GuiWidget_FindChildByName(self, buf);
        slot = (Slot*)((int*)slot + 1);
    }
    func_0041F150(self);
}
