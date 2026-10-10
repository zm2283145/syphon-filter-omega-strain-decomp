#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_0013B180(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
int String_AssignCStr_1C43A0(const void* string, const char* name);
const char* func_001692D0(const void* string);
const char* func_00129C80(const char* text, const char* pattern);
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
    func_0013B180(&rawBegin, &self->children);
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
extern "C" TraversalWidget* func_0041DB80(TraversalWidget* self, const char* name)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (!String_AssignCStr_1C43A0(self->name, name))
        return self;
    func_0013B180(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = func_0041DB80(node->widget, name);
        if (found)
            return found;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return 0;
}

/* Search the widget and its descendants for the first name containing a pattern. */
extern "C" TraversalWidget* func_0041DC70(TraversalWidget* self, const char* pattern)
{
    ChildIterator end;
    ChildIterator begin;
    ChildIterator rawBegin;
    ChildIterator rawEnd;
    if (func_00129C80(func_001692D0(self->name), pattern))
        return self;
    func_0013B180(&rawBegin, &self->children);
    func_0028C0B0(&begin, &rawBegin);
    ChildNode* node = begin.node;
    func_0028C0A0(&rawEnd, &self->children);
    func_0028C090(&end, &rawEnd);
    while (node != end.node) {
        TraversalWidget* found = func_0041DC70(node->widget, pattern);
        if (found)
            return found;
        node = node->next;
        func_0028C0A0(&rawEnd, &self->children);
        func_0028C090(&end, &rawEnd);
    }
    return 0;
}
