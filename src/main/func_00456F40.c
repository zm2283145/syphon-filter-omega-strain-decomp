#include "loose05_types.h"

extern int func_0041EF10(GuiWidget456D90* self, void* sender, int message);

/* Consume message 16 for values 2 and 3; defer other messages to the base. */
int func_00456F40(GuiWidget456D90* self, void* sender, int message, int value) {
    if ((message & 0xFFFF) == 16 && (value == 2 || value == 3)) {
        return 1;
    }
    return func_0041EF10(self, sender, message);
}
