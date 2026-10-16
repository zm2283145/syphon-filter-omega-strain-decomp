#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void List_Begin(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
int String_AssignCStr_1C43A0(const void* string, const char* name);
const char* String_CStr(const void* string);
const char* strstr(const char* text, const char* pattern);
}

/* Search the widget and its descendants for the first matching numeric ID. */
extern "C" TraversalWidget* func_0041DAA0(TraversalWidget* self, int id)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (id == self->id)
        return self;
    List_Begin(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = func_0041DAA0(node->widget, id);
        if (found)
            return found;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
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
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChildByName(node->widget, name);
        if (found)
            return found;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
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
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = GuiWidget_FindChildBySubstring(node->widget, pattern);
        if (found)
            return found;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return 0;
}
