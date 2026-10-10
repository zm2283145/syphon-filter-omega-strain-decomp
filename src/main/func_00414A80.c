#include "types.h"

typedef struct { char pad[0x48]; int id; char pad2[4]; unsigned char pressed; } Widget414;

extern int func_0041EF10(Widget414* self, int id, unsigned short event);

/* Marks the widget pressed on event 3 for its own id (returns 1); otherwise returns the base handler's result. */
int func_00414A80(Widget414* self, int id, unsigned short event)
{
    if (event == 3 && id == self->id) {
        self->pressed = 1;
        return 1;
    }
    return func_0041EF10(self, id, event);
}
