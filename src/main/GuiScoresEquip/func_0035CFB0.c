#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

/* Set or clear flag 2 on every other child. */
extern "C" void func_0035CFB0(ChildWidget* o, int on);
void func_0035CFB0(ChildWidget* o, int on)
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
            if (on) c->flags |= 2;
            else c->flags &= ~2;
        }
    }
}