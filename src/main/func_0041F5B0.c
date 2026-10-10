#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_00135C90(ChildList* list, int flags);
void ObjectList_EraseRange(ChildIterator* result, ChildList* list,
                          ChildIterator* first, ChildIterator* last);
void operator_delete(void* allocation);
}

static inline void destroy_list_base(ChildList* list)
{
    if (list)
        func_00135C90(list, 0);
}

static inline void erase_all(ChildList* list)
{
    if (list) {
        ChildIterator result;
        ChildIterator first;
        ChildIterator last;
        last.node = (ChildNode*)&list->sentinel;
        first.node = list->first;
        ObjectList_EraseRange(&result, list, &first, &last);
    }
}

/* Destroy the child-list base and optionally release its allocation. */
extern "C" ChildList* func_0041F5B0(ChildList* self, short deleteFlag)
{
    if (self) {
        destroy_list_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Erase the full list up to its embedded sentinel before optional deletion. */
extern "C" ChildList* func_0041F610(ChildList* self, short deleteFlag)
{
    if (self) {
        erase_all(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
