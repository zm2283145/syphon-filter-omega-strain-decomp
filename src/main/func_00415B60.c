#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } Ent415B60;
extern void GuiWidget_BroadcastEvent(Ent415B60* e, int kind, int v, int z);
void func_00415B60(Ent415B60* e, float v)
{
    if (e->flags & 4) {
        v = v * 30.0f;
        GuiWidget_BroadcastEvent(e, 7, (int)&v, 0);
    }
}
