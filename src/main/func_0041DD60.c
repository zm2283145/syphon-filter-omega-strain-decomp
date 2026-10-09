/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* List_InsertBefore(L4Iter* out, void* list, L4Iter* pos, int value);
extern int func_002CCE50(L4ScalarCollection* coll, GuiWidget** value);

/* Adds child to the widget: sets its parent and appends it to the child collection. */
int GuiWidget_AddChild(GuiWidget* self, GuiWidget* child) {
    GuiWidget* loc[1];

    loc[0] = child;
    loc[0]->parent = self;
    return func_002CCE50(&self->children, loc);
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* func_0041DD90(void* list, int value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return List_InsertBefore(&it[1], list, &it[0], value);
}
