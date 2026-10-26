#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
extern TraversalWidget* D_00572138;
extern TraversalWidget* D_00572140;
void std_list_deleter_voidPtr_end_void(ChildIterator* result, ChildList* list);
void List_Begin(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_begin(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
}

static inline unsigned char focusable(TraversalWidget* widget)
{
    return (widget->flags & 0x80) && (widget->flags & 4);
}

static inline unsigned char active_focusable(TraversalWidget* widget)
{
    return focusable(widget) && (widget->flags & 2);
}

static inline unsigned char selectable(TraversalWidget* widget)
{
    return widget->owner == widget || active_focusable(widget);
}

/* Search backwards after the boundary, restarting at the edge when requested. */
extern "C" TraversalWidget* GuiWidget_FocusPrev(TraversalWidget* self, TraversalWidget* boundary, int restart)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (restart)
        D_00572140 = 0;
    if (D_00572140 && selectable(self))
        return self;
    if (boundary == self)
        D_00572140 = self;
    TraversalWidget* found = 0;
    std_list_deleter_voidPtr_end_void(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_begin(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        node = node->previous;
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            found = child->find_backward(boundary, 0);
            if (found)
                break;
        }
        std_list_GuiWidgetPtr_begin(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    self->selected = found;
    if (restart && !self->selected)
        self->selected = self->last_descendant();
    return self->selected;
}

/* Search forwards after the boundary, restarting at the edge when requested. */
extern "C" TraversalWidget* GuiWidget_FocusNext(TraversalWidget* self, TraversalWidget* boundary, int restart)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (restart)
        D_00572138 = 0;
    if (D_00572138 && selectable(self))
        return self;
    if (boundary == self)
        D_00572138 = self;
    TraversalWidget* found = 0;
    List_Begin(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            found = child->find_forward(boundary, 0);
            if (found)
                break;
        }
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    self->selected = found;
    if (restart && !self->selected)
        self->selected = self->first_descendant();
    return self->selected;
}

/* Search the child list backwards, preserving the live end iterator. */
extern "C" TraversalWidget* GuiWidget_FocusLast(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    std_list_deleter_voidPtr_end_void(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_begin(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        node = node->previous;
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            TraversalWidget* found = child->last_descendant();
            if (found) {
                self->selected = found;
                return found;
            }
        }
        std_list_GuiWidgetPtr_begin(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return selectable(self) ? self : 0;
}

/* Search the child list forwards, preserving the live end iterator. */
extern "C" TraversalWidget* GuiWidget_FocusFirst(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    List_Begin(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            TraversalWidget* found = child->first_descendant();
            if (found) {
                self->selected = found;
                return found;
            }
        }
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return selectable(self) ? self : 0;
}
