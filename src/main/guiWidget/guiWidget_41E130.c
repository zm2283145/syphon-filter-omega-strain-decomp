#pragma explicit_zero_data on
#pragma cplusplus on

#include "gui_traversal_types.h"
#include "types.h"

extern "C" {
GuiFocusManager* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(GuiFocusManager* manager, TraversalWidget* selected);
void List_Begin(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
void GuiWidget_CheckSleep(TraversalWidget* self);
void GuiWidget_DrawFocusHighlight(TraversalWidget* self, const Vec4* color);
unsigned int D_004BF3C0[1] = { 0x0 };
}

static inline unsigned char notify_parent(TraversalWidget* receiver, TraversalWidget* sender,
                                         int message)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, 0, 0);
    return 0;
}

static inline void bubble_message(TraversalWidget* self, int message)
{
    TraversalWidget* parent = self->parent;
    while (parent) {
        unsigned char handled = notify_parent(parent, self, message);
        if (handled)
            break;
        parent = parent->parent;
    }
}

/* Change the focus-enabled flag while maintaining the manager's selection. */
extern "C" void func_0041E130(TraversalWidget* self, int enabled)
{
    if ((unsigned char)enabled != ((self->flags & 4) != 0)) {
        if (enabled) {
            self->flags |= 4;
            if (!Gui_GetScreenStack()->selected) {
                GuiFocusManager* manager = Gui_GetScreenStack();
                GuiScreen_SetFocus(manager, self->first_descendant());
            }
        } else {
            if (Gui_GetScreenStack()->selected == self) {
                TraversalWidget* next = self->owner->find_forward(self, 1);
                if (next == self)
                    next = 0;
                GuiScreen_SetFocus(Gui_GetScreenStack(), next);
            }
            self->flags &= ~4;
        }
    }
}

/* Notify ancestors with message 2, stopping when a handler accepts it. */
extern "C" void func_0041E230(TraversalWidget* self)
{
    bubble_message(self, 2);
}

/* Notify ancestors with message 1, stopping when a handler accepts it. */
extern "C" void func_0041E2B0(TraversalWidget* self)
{
    bubble_message(self, 1);
}

/* Notify ancestors with message 0, stopping when a handler accepts it. */
extern "C" void func_0041E330(TraversalWidget* self)
{
    bubble_message(self, 0);
}

/* Update every child handler before checking pending completion on the parent. */
extern "C" void GuiWidget_Update(TraversalWidget* self, float elapsed)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    List_Begin(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        node->widget->handler->update(elapsed);
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    GuiWidget_CheckSleep(self);
}

/* Draw visible children and optionally render the current focus indicator. */
extern "C" void GuiWidget_Draw(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    List_Begin(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* child = node->widget;
        if (child->flags & 2)
            child->handler->draw();
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    if ((self->flags & 0x100) && Gui_GetScreenStack()->selected == self)
        GuiWidget_DrawFocusHighlight(self, &(*(Vec4*)D_004BF3C0));
}
