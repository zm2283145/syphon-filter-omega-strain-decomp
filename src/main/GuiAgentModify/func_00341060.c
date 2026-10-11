#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

/* Set flags 4 and 0x80 on every other child of the given type. */
extern "C" {
extern char D_004A9870[];
void func_00341060(void* self, ChildWidget* o);
}
static inline ChildWidget* cast341060(ChildWidget* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void func_00341060(void* self, ChildWidget* o)
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
            if (cast341060(c)) {
                n->obj->flags |= 4;
                n->obj->flags |= 0x80;
            }
        }
    }
}