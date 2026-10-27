#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void std_list_deleter_voidPtr_begin_void(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
int std_basic_string_char_char_traits_char_compare_charP(const void* string, const char* name);
const char* std_basic_string_char_char_traits_char_c_str(const void* string);
const char* strstr(const char* text, const char* pattern);
}

/* Search the widget and its descendants for the first matching numeric ID. */
extern "C" TraversalWidget* GuiWidget_FindChild_int(TraversalWidget* self, int id)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (id == self->id)
        return self;
    std_list_deleter_voidPtr_begin_void(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChild_int(node->widget, id);
        if (found)
            return found;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}

/* Search the widget and its descendants for the first matching full name. */
extern "C" TraversalWidget* GuiWidget_FindChild_charP(TraversalWidget* self, const char* name)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (!std_basic_string_char_char_traits_char_compare_charP(self->name, name))
        return self;
    std_list_deleter_voidPtr_begin_void(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChild_charP(node->widget, name);
        if (found)
            return found;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}

/* Search the widget and its descendants for the first name containing a pattern. */
extern "C" TraversalWidget* GuiWidget_FindChildPartial(TraversalWidget* self, const char* pattern)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (strstr(std_basic_string_char_char_traits_char_c_str(self->name), pattern))
        return self;
    std_list_deleter_voidPtr_begin_void(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChildPartial(node->widget, pattern);
        if (found)
            return found;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}
