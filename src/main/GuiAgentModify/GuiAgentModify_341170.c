/*
 * main/GuiAgentModify: range (2 files, 00341170-00341240)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "child_list_iter.h"
#pragma pop

/* merge_units: begin func_00341170 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Clear flag 2 on every other child and hide its renderer. */
extern "C" void func_00341170(void* self, ChildWidget* o);
void func_00341170(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        if (n->obj != o) {
            n->obj->flags &= ~2;
            n->obj->renderer->Hide();
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341170 */

/* merge_units: begin func_00341240 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Set flag 2 on every other child, show its renderer, set flag 4, clear flag 0x80. */
extern "C" void func_00341240(void* self, ChildWidget* o);
void func_00341240(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        if (n->obj != o) {
            n->obj->flags |= 2;
            n->obj->renderer->Show();
            n->obj->flags |= 4;
            n->obj->flags &= ~0x80;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341240 */
