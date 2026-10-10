#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_0013B180(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
void func_0041ED20(TraversalWidget* self);
}

static inline unsigned char notify(TraversalWidget* receiver, TraversalWidget* sender,
                                  int message)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, 0, 0);
    return 0;
}

/* Propagate the requested state to children, then check for completion. */
extern "C" void func_0041EBF0(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (self->flags & 8) {
        self->flags |= 0x10;
        int requested = (notify(self, self, 15) != 0) ^ 1;
        if (requested)
            self->flags |= 8;
        else
            self->flags &= ~8;
        func_0013B180(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        while (node != end.node) {
            node->widget->handler->propagate_state();
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
        }
        func_0041ED20(self);
    }
}
