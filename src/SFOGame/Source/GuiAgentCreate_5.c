/*
 * SFOGame/Source/GuiAgentCreate: 1 file, 0028C0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028C0C0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

/* Set flags 4 and 0x80 on every other child of the given type. */
extern "C" {
extern char D_004A9870[];
void RecurseChildrenFocusable(ChildWidget* o);
}
static inline ChildWidget* cast28C0C0(ChildWidget* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void RecurseChildrenFocusable(ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (cast28C0C0(c)) {
                n->obj->flags |= 4;
                n->obj->flags |= 0x80;
            }
        }
    }
}
static inline void merge_flush_func_0028C0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028C0C0 */
