#include "types.h"

typedef struct { char pad[0xE0]; int menuActive; void* menu; } cPlayer;

extern void func_0041BEB0(void* menu, const char* title, int flags);

/* Sets the title of the player's menu when it is active. */
void cPlayer_SetMenuTitle(cPlayer* self, const char* title)
{
    if (self->menuActive)
        func_0041BEB0(self->menu, title, 0);
}
