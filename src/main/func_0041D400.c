#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
extern TraversalWidget* D_00572138;
extern TraversalWidget* D_00572140;
void func_0013B160(ChildIterator* result, ChildList* list);
void func_0013B180(ChildIterator* result, ChildList* list);
void func_002A89A0(ChildIterator* result, ChildList* list);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
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
extern "C" TraversalWidget* func_0041D400(TraversalWidget* self, TraversalWidget* boundary, int restart)
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
    func_0013B160(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_002A89A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        node = node->previous;
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            found = child->find_backward(boundary, 0);
            if (found)
                break;
        }
        func_002A89A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    self->selected = found;
    if (restart && !self->selected)
        self->selected = self->last_descendant();
    return self->selected;
}

/* Search forwards after the boundary, restarting at the edge when requested. */
extern "C" TraversalWidget* func_0041D5C0(TraversalWidget* self, TraversalWidget* boundary, int restart)
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
    func_0013B180(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* child = node->widget;
        if ((child->flags & 4) && (child->flags & 2)) {
            found = child->find_forward(boundary, 0);
            if (found)
                break;
        }
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    self->selected = found;
    if (restart && !self->selected)
        self->selected = self->first_descendant();
    return self->selected;
}

/* Search the child list backwards, preserving the live end iterator. */
extern "C" TraversalWidget* func_0041D780(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    func_0013B160(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_002A89A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
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
        func_002A89A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return selectable(self) ? self : 0;
}

/* Search the child list forwards, preserving the live end iterator. */
extern "C" TraversalWidget* func_0041D8C0(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    func_0013B180(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
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
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return selectable(self) ? self : 0;
}
