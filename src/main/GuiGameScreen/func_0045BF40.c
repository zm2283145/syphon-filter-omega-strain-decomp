#include "GuiGameScreen_types.h"

extern int func_00421290(GuiChoiceList* choices, const char* text, int value, int flags);

/* Append a text choice only when the in-game menu is available. */
void cPlayer_AddMenuChoice(GuiGameScreen* screen, const char* text)
{
    if (screen->menu)
        func_00421290(screen->choices, text, -1, 0);
}
