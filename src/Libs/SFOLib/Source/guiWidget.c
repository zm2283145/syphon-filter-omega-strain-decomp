/*
 * Libs/SFOLib/Source/guiWidget: 3 files, 0041D400-0041DA60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041D400 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
extern TraversalWidget* D_00572138;
extern TraversalWidget* D_00572140;
void std_list_deleter_voidPtr_end_void(ChildIterator* result, ChildList* list);
void std_list_deleter_voidPtr_begin_void(ChildIterator* result, ChildList* list);
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
extern "C" TraversalWidget* GuiWidget_FindPrevFocus(TraversalWidget* self, TraversalWidget* boundary, int restart)
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
extern "C" TraversalWidget* GuiWidget_FindNextFocus(TraversalWidget* self, TraversalWidget* boundary, int restart)
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
    std_list_deleter_voidPtr_begin_void(&rawBegin, &self->children);
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
extern "C" TraversalWidget* GuiWidget_FindLastFocus(TraversalWidget* self)
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
extern "C" TraversalWidget* GuiWidget_FindFirstFocus(TraversalWidget* self)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    std_list_deleter_voidPtr_begin_void(&rawBegin, &self->children);
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
static inline void merge_flush_func_0041D400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041D400 */

/* merge_units: begin func_0041DA00 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
typedef struct S41DA { char p0[0x14]; unsigned short f14; char p16[0xE]; struct S41DA *f24; } S41DA;
static inline bool A41(S41DA *o) { bool r = 0; if ((o->f14 & 0x80) && (o->f14 & 4)) r = 1; return r; }
static inline bool B41(S41DA *o) { bool r = 0; if (A41(o) && (o->f14 & 2)) r = 1; return r; }
extern "C" bool GuiWidget_IsValidFocus(S41DA *o) {
    bool v = 1;
    if (o->f24 != o) {
        if (!B41(o)) v = 0;
    }
    return v;
}
static inline void merge_flush_func_0041DA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041DA00 */

/* merge_units: begin func_0041DA60 */
#pragma push /* merge_units */
typedef struct GuiWidgetValueSlot {
    char pad00[0x10];
    int value;
} GuiWidgetValueSlot;

extern GuiWidgetValueSlot* GuiWidget_FindChild_charP(void* self, const char* name);

/* Set a named widget's value when that widget exists. */
int GuiWidget_SetChildUserID(void* self, const char* name, int value)
{
    GuiWidgetValueSlot* widget = GuiWidget_FindChild_charP(self, name);
    if (widget) {
        widget->value = value;
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_0041DA60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041DA60 */
