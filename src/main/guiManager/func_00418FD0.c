#include "loose04_types.h"

typedef struct GuiManager GuiManager;

extern GuiWidget* func_00418B10(GuiManager* self, char** cursor, GuiWidget* existing);
extern void func_00419530(GuiManager* self, GuiWidget* widget);

/* Read a widget hierarchy and register the root when creation succeeds. */
GuiWidget* func_00418FD0(GuiManager* self, char** cursor, GuiWidget* existing) {
    GuiWidget* widget = func_00418B10(self, cursor, existing);
    if (widget != 0) {
        func_00419530(self, widget);
    }
    return widget;
}
