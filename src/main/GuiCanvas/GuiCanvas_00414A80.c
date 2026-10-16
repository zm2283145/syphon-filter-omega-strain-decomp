#include "types.h"

typedef struct { char pad[0x48]; int id; char pad2[4]; unsigned char pressed; } Widget414;

extern int GuiWidget_OnEvent(Widget414* self, int id, unsigned short event);

/* Marks the widget pressed on event 3 for its own id (returns 1); otherwise returns the base handler's result. */
int GuiCanvas_FinishDeferredPop(Widget414* self, int id, unsigned short event)
{
    if (event == 3 && id == self->id) {
        self->pressed = 1;
        return 1;
    }
    return GuiWidget_OnEvent(self, id, event);
}
