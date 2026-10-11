#pragma cplusplus on

#include "types.h"

/* Deleting destructor of a list: erase [first, sentinel), then delete. */
typedef struct ListNode_383150 ListNode_383150;
typedef struct {
    int size;
    ListNode_383150* sentinelPrev;
    ListNode_383150* first;
} List_383150;

extern "C" {
void func_00383420(ListNode_383150** result, List_383150* list,
                   ListNode_383150** first, ListNode_383150** last);
void operator_delete(void* allocation);
}

extern "C" List_383150* func_00383150(List_383150* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                ListNode_383150* result;
                ListNode_383150* first;
                ListNode_383150* last;
                last = (ListNode_383150*)&self->sentinelPrev;
                first = self->first;
                func_00383420(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}