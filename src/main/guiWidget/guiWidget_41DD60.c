/*
 * main/guiWidget: 4 files, 0041DD60-0041E130
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041DD60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* List_InsertBefore(L4Iter* out, void* list, L4Iter* pos, int value);
extern int std_list_GuiWidgetPtr_push_back_GuiWidgetPR(L4ScalarCollection* coll, GuiWidget** value);

/* Adds child to the widget: sets its parent and appends it to the child collection. */
int GuiWidget_AddChild(GuiWidget* self, GuiWidget* child) {
    GuiWidget* loc[1];

    loc[0] = child;
    loc[0]->parent = self;
    return std_list_GuiWidgetPtr_push_back_GuiWidgetPR(&self->children, loc);
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* func_0041DD90(void* list, int value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return List_InsertBefore(&it[1], list, &it[0], value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041DD60 */

/* merge_units: begin func_0041DDC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void List_Begin(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
}

static inline unsigned char notify(TraversalWidget* receiver, TraversalWidget* sender,
                                   int message, int first, int second)
{
    if (receiver)
        return receiver->handler->on_message(sender, message, first, second);
    return 0;
}

/* Dispatch to siblings in list order, stopping at the first handler that accepts. */
extern "C" int GuiWidget_SendSiblingMessage(TraversalWidget* self, int message, int first, int second)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    TraversalWidget* parent = self->parent;
    if (!parent)
        return 0;
    List_Begin(&rawBegin, &parent->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildList* children = &parent->children;
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        if (node->widget != self && notify(node->widget, self, message, first, second))
            return 1;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}

/* Dispatch depth-first through the descendants, with each parent as sender. */
extern "C" int GuiWidget_BroadcastEvent(TraversalWidget* self, int message, int first, int second)
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
        if (notify(node->widget, self, message, first, second))
            return 1;
        if (GuiWidget_BroadcastEvent(node->widget, message, first, second))
            return 1;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}

/* Bubble a message through the parent chain until a handler accepts it. */
extern "C" int GuiWidget_SendEventUp(TraversalWidget* self, int message, int first, int second)
{
    TraversalWidget* parent = self->parent;
    while (parent) {
        if (notify(parent, self, message, first, second))
            return 1;
        parent = parent->parent;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041DDC0 */

/* merge_units: begin func_0041E0F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Handler: only the slots used here are named (vtable offset in comments). */
struct Handler {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C();
    virtual int Method3C(void* arg); /* +0x3C */
};

typedef struct Widget { char pad[0x44]; Handler* handler; /* +0x44 */ } Widget;

/* Passes arg to the widget's handler (virtual +0x3C); 0 without a widget. */
extern "C" int GuiWidget_SendEvent(void* arg, Widget* widget)
{
    if (widget)
        return widget->handler->Method3C(arg);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041E0F0 */

/* merge_units: begin func_0041E130 */
#pragma push /* merge_units */
#pragma explicit_zero_data on
#pragma cplusplus on

extern "C" {
GuiFocusManager* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(GuiFocusManager* manager, TraversalWidget* selected);
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
extern "C" void GuiWidget_Activate(TraversalWidget* self, int enabled)
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
extern "C" void GuiWidget_BubbleActivate(TraversalWidget* self)
{
    bubble_message(self, 2);
}

/* Notify ancestors with message 1, stopping when a handler accepts it. */
extern "C" void GuiWidget_BubbleType1(TraversalWidget* self)
{
    bubble_message(self, 1);
}

/* Notify ancestors with message 0, stopping when a handler accepts it. */
extern "C" void GuiWidget_BubbleType0(TraversalWidget* self)
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
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        node->widget->handler->update(elapsed);
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
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
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* child = node->widget;
        if (child->flags & 2)
            child->handler->draw();
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    if ((self->flags & 0x100) && Gui_GetScreenStack()->selected == self)
        GuiWidget_DrawFocusHighlight(self, &(*(Vec4*)D_004BF3C0));
}
#pragma pop /* merge_units */
/* merge_units: end func_0041E130 */
