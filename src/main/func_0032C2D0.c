#include "types.h"
typedef struct { char p0[0xE4]; unsigned int flags; } O32C2D0;
typedef struct { char p0[0xA]; unsigned char flags; } I32C2D0;
/* Picks which of the item's key slots (0-3) applies for the object's current mode bits. */
int GuiKeyboard_GetModifierIndex(O32C2D0* o, I32C2D0* it)
{
    unsigned int f = o->flags;
    int r;
    if (f & 4) {
        r = 2;
        if (f & 2) {
            if (it->flags & 2) r = 3;
            if (f & 1) r = (r == 3) ? 2 : 3;
        } else {
            if (f & 1) r = 3;
        }
    } else {
        r = 0;
        if (f & 2) {
            if (it->flags & 1) r = 1;
            if (f & 1) r = (r ^ 1) != 0;
        } else {
            if (f & 1) r = 1;
        }
    }
    return r;
}
