#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

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