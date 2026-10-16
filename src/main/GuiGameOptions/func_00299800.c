#include "types.h"

typedef struct { char pad[0x14]; unsigned short flags; } Widget;
typedef struct {
    char pad[0x8C];
    Widget* widgets[4];
    void* items[4];
    Widget* cursor;
    char pad3[4];
    int index;
} Menu299;
extern void* Gui_GetScreenStack(void);
extern void GuiScreen_SetFocus(void* ctx, void* item);
extern void GuiWidget_SendEvent(void* item, void* ctx, int a, int b, int c);

/* Activates the current menu item: un-hides its widget, focuses it; then shows the cursor. */
void GuiGameOptions_ShowMenu(Menu299* m)
{
    if (m->items[m->index]) {
        m->widgets[m->index]->flags &= ~4;
        GuiScreen_SetFocus(Gui_GetScreenStack(), m->items[m->index]);
        GuiWidget_SendEvent(m->items[m->index], Gui_GetScreenStack(), 0x10, 0, 0);
    }
    if (m->cursor)
        m->cursor->flags |= 4;
}
