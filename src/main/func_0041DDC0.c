#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_0013B180(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
}

static inline unsigned char notify(TraversalWidget* receiver, TraversalWidget* sender,
                                   int message, int first, int second)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, first, second);
    return 0;
}

/* Dispatch to siblings in list order, stopping at the first handler that accepts. */
extern "C" int func_0041DDC0(TraversalWidget* self, int message, int first, int second)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    TraversalWidget* parent = self->parent;
    if (!parent)
        return 0;
    func_0013B180(&rawBegin, &parent->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildList* children = &parent->children;
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        if (node->widget != self && notify(node->widget, self, message, first, second))
            return 1;
        node = node->next;
        func_0028C0A0(&rawEnd, children);
        func_0028C090(&end, &rawEnd);
    }
    return 0;
}

/* Dispatch depth-first through the descendants, with each parent as sender. */
extern "C" int func_0041DF00(TraversalWidget* self, int message, int first, int second)
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
        if (notify(node->widget, self, message, first, second))
            return 1;
        if (func_0041DF00(node->widget, message, first, second))
            return 1;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return 0;
}

/* Bubble a message through the parent chain until a handler accepts it. */
extern "C" int func_0041E040(TraversalWidget* self, int message, int first, int second)
{
    TraversalWidget* parent = self->parent;
    while (parent) {
        if (notify(parent, self, message, first, second))
            return 1;
        parent = parent->parent;
    }
    return 0;
}
