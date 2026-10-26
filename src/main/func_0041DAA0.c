#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void List_Begin(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
int String_AssignCStr_1C43A0(const void* string, const char* name);
const char* String_CStr(const void* string);
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
    List_Begin(&rawBegin, &self->children);
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
extern "C" TraversalWidget* GuiWidget_FindChildByName(TraversalWidget* self, const char* name)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (!String_AssignCStr_1C43A0(self->name, name))
        return self;
    List_Begin(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChildByName(node->widget, name);
        if (found)
            return found;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}

/* Search the widget and its descendants for the first name containing a pattern. */
extern "C" TraversalWidget* GuiWidget_FindChildBySubstring(TraversalWidget* self, const char* pattern)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (strstr(String_CStr(self->name), pattern))
        return self;
    List_Begin(&rawBegin, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
    ChildNode* node = begin.node;
    std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChildBySubstring(node->widget, pattern);
        if (found)
            return found;
        node = node->next;
        std_list_GuiWidgetPtr_end(&rawEnd, &self->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
    }
    return 0;
}
