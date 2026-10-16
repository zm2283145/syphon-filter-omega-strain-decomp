#include "GuiGameScreen_types.h"

extern int GuiTextListWidget_AddItem(GuiChoiceList* choices, const char* text, int value, int flags);

/* Append a text choice only when the in-game menu is available. */
void cPlayer_AddMenuChoice(GuiGameScreen* screen, const char* text)
{
    if (screen->menu)
        GuiTextListWidget_AddItem(screen->choices, text, -1, 0);
}
