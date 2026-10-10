#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_0013B180(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
void* func_00414790(void);
void func_00418840(void* manager, TraversalWidget* widget);
}

/* Clear pending and requested state throughout the live child hierarchy. */
extern "C" void func_0041EE50(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    self->flags &= ~0x10;
    self->flags &= ~8;
    func_0013B180(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        func_0041EE50(node->widget);
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
}

/* Handle state completion and flagged removal requests; reject other messages. */
extern "C" int func_0041EF10(TraversalWidget* self, TraversalWidget* sender, int message)
{
    switch ((unsigned short)message) {
    case 15:
        self->flags &= ~8;
        return 1;
    case 25:
        if (self->flags & 0x20) {
            func_00418840(func_00414790(), self);
            return 1;
        }
        break;
    }
    return 0;
}

/* Request state on every child only when the parent was not already requested. */
extern "C" void func_0041EFA0(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (!(self->flags & 8)) {
        self->flags |= 8;
        func_0013B180(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        while (node != end.node) {
            node->widget->handler->request_state();
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
        }
    }
}
