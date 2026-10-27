#ifndef CHILD_LIST_ITER_H
#define CHILD_LIST_ITER_H

/*
 * Iteration over a GUI widget's child list (list object at widget +0x28)
 * through the out-of-line list iterator helpers: begin() is
 * std_list_deleter_voidPtr_begin_void + const-iterator conversion std_list_GuiWidgetPtr_generic_iterator_ctor, end() is
 * std_list_GuiWidgetPtr_end + cLListIterator_GuiWidgetPtr_ctor_listR and is re-evaluated every iteration.
 * Child widgets: flags (u16) at +0x14, IsA(type) at virtual slot 20,
 * renderer at +0x44 with Show()/Hide() at virtual slots 5/6.
 *
 *   ChildNode* n; ChildIter e; void* l;
 *   n = ChildList_Begin(CHILD_LIST(w)); l = CHILD_LIST(w);
 *   for (; ChildList_End(&e, l), n != e.p; n = n->next) { ... }
 *
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_pad.h"

class ChildRenderer {
public:
    VPAD4(a) VPAD1(b)
    virtual void Show();
    virtual void Hide();
};

class ChildWidget {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x12];
    int children[3];
    char pad34[0x10];
    ChildRenderer* renderer;
};

struct ChildNode {
    int prev;
    ChildNode* next;
    ChildWidget* obj;
};

struct ChildIter {
    ChildNode* p;
};

extern "C" {
void std_list_deleter_voidPtr_begin_void(ChildIter* result, void* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIter* result, ChildIter* it);
void std_list_GuiWidgetPtr_end(ChildIter* result, void* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIter* result, ChildIter* it);
}

#define CHILD_LIST(w) ((w)->children)

static inline ChildNode* ChildList_Begin(void* l)
{
    ChildIter r;
    ChildIter t;
    std_list_deleter_voidPtr_begin_void(&t, l);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&r, &t);
    return r.p;
}

static inline void ChildList_End(ChildIter* res, void* l)
{
    ChildIter t;
    std_list_GuiWidgetPtr_end(&t, l);
    cLListIterator_GuiWidgetPtr_ctor_listR(res, &t);
}

#endif /* CHILD_LIST_ITER_H */
