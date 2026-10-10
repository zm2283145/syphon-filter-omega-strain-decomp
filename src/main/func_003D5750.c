#include "types.h"

typedef struct { int head; int value; } ListHead;
extern void func_00383420(int* out, void* list, int* value, ListHead** head);

/* Calls func_00383420 on the list at +0x1175C with the head at +0x11760 and its value. */
void func_003D5750(char* self)
{
    ListHead* headp;
    int value;
    int result;
    ListHead* head = (ListHead*)(self + 0x11760);
    headp = head;
    value = head->value;
    func_00383420(&result, self + 0x1175C, &value, &headp);
}
