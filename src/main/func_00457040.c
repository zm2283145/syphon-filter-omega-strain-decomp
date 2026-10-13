#include "GuiGameScreen_types.h"

extern void* Gui_GetScreenList(void);
extern void* GuiManager_FindByName(void* manager, const char* name);
extern GuiGameChild* GuiWidget_FindChildByName(void* parent, const char* name);
extern char D_004C1B00[];
extern char D_004C1B28[];
extern char D_004C1B38[];
extern char D_004C1B18[];
extern char D_004C1B20[];

static inline void set_active(GuiGameChild* widget, int active)
{
    if (widget) {
        if (active)
            widget->flags |= 2;
        else
            widget->flags &= ~2;
    }
}

/* Toggle the first pair of named widgets when their parent is available. */
void func_00457040(int active)
{
    void* parent = GuiManager_FindByName(Gui_GetScreenList(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = GuiWidget_FindChildByName(parent, D_004C1B28);
        GuiGameChild* second = GuiWidget_FindChildByName(parent, D_004C1B38);
        set_active(first, active);
        set_active(second, active);
    }
}

/* Toggle the second pair of named widgets when their parent is available. */
void func_00457110(int active)
{
    void* parent = GuiManager_FindByName(Gui_GetScreenList(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = GuiWidget_FindChildByName(parent, D_004C1B18);
        GuiGameChild* second = GuiWidget_FindChildByName(parent, D_004C1B20);
        set_active(first, active);
        set_active(second, active);
    }
}
