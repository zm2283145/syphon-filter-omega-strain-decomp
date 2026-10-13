#pragma cplusplus on
#include "types.h"
#include "guiManager.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


/* Virtual slots used here: v2 = widget teardown (vtable slot 4), v24 = screen stack notification. */
struct VC004193D0 { virtual int v0(); virtual int v1(); virtual int v2(...); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int func_00138DA0(...);                     /* list erase */
int func_0015AF40(...);
int func_002A8890(...);                     /* iterator != */
int func_002A88B0(...);                     /* end() */
int func_002CCDE0(...);
int func_002CCDF0(...);                     /* ++iterator */
int *func_002CCE10(...);                    /* *iterator */
int func_002CCE20(...);
int func_002CCE30(...);                     /* begin() */
int func_002CCE40(...);
void **Gui_GetScreenStack(...);
typedef struct { char p0[20]; unsigned short flags; } PS0_004193D0; /* GuiWidget view */
}
/*
 * If the widget is set up: find it in the widget list, notify the screen stack
 * (widget flag 0x8), tear the widget down and erase it from the list.
 */
extern "C" void GuiManager_RemoveWidget(GuiScreenList *self, PS0_004193D0 *widget) {
    char * found;
    char * node;
    int erased;
    int pos;
    int it;
    int begin;
    int end;
    void **sub;
    void **stack;

    if (widget->flags & GUI_WIDGET_SET_UP) {
        func_002CCE40(&it);
        func_002CCE30(&begin, &self->widgets);
        func_002CCE20(&it, &begin);
        func_002A88B0(&end, &self->widgets);
        if (func_002A8890(&it, &end) != 0) {
loop_3:
            if ((void *)(*func_002CCE10(&it)) != (void *)(widget)) {
                func_002CCDF0(&it);
                func_002A88B0(&end, &self->widgets);
                if (func_002A8890(&it, &end) == 0) {

                } else {
                    goto loop_3;
                }
            }
        }
        func_002CCDE0(&found, &it);
        if (F_(found, 0x8, int) != NULL) {
            if ((Gui_GetScreenStack() != NULL) && (widget->flags & 8)) {
                stack = Gui_GetScreenStack();
                ((VC004193D0 *)(stack))->v24(widget);
            }
            /* found->item->self (GuiWidget 0x44) */
            sub = (void **)(F_(F_(found, 0x8, int), 0x44, int));
            ((VC004193D0 *)(sub))->v2();
            node = found;
            func_0015AF40(&pos, &node);
            func_00138DA0(&erased, &self->widgets, &pos);
        }
    }
}
