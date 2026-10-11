#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

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