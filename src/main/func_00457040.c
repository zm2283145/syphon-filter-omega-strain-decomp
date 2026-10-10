#include "GuiGameScreen_types.h"

extern void* func_00414790(void);
extern void* func_00418980(void* manager, const char* name);
extern GuiGameChild* func_0041DB80(void* parent, const char* name);
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
    void* parent = func_00418980(func_00414790(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = func_0041DB80(parent, D_004C1B28);
        GuiGameChild* second = func_0041DB80(parent, D_004C1B38);
        set_active(first, active);
        set_active(second, active);
    }
}

/* Toggle the second pair of named widgets when their parent is available. */
void func_00457110(int active)
{
    void* parent = func_00418980(func_00414790(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = func_0041DB80(parent, D_004C1B18);
        GuiGameChild* second = func_0041DB80(parent, D_004C1B20);
        set_active(first, active);
        set_active(second, active);
    }
}
