#pragma cplusplus on
#pragma opt_lifetimes off
#pragma opt_propagation off

#include "gui_traversal_types.h"

extern "C" {
void List_Begin(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
}

static inline unsigned char notify(TraversalWidget* receiver, TraversalWidget* sender,
                                  int message)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, 0, 0);
    return 0;
}

/* Once every child accepts the completion message, clear pending and notify the parent. */
extern "C" void GuiWidget_CheckSleep(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if ((self->flags & 0x10) && !(self->flags & 8)) {
        List_Begin(&rawBegin, &self->children);
        func_0028C0B0(&begin, &rawBegin);
        ChildNode* node = begin.node;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
        ChildNode* e = end.node;
        if (node != e) do {
            if (!notify(node->widget, self, 15)) return;
            node = node->next;
            func_0028C0A0(&rawEnd, &self->children);
            func_0028C090(&end, &rawEnd);
            e = end.node;
        } while (node != e);
        self->flags &= ~0x10;
        notify(self->parent, self, 3);
    }
}
