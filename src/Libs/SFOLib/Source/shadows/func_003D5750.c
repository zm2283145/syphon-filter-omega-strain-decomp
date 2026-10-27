#include "types.h"

typedef struct { int head; int value; } ListHead;
extern void std_list_deleter_int_erase_listdeleter_listdeleter(int* out, void* list, int* value, ListHead** head);

/* Calls std_list_deleter_int_erase_listdeleter_listdeleter on the list at +0x1175C with the head at +0x11760 and its value. */
void cShadowMan_Purge(char* self)
{
    ListHead* headp;
    int value;
    int result;
    ListHead* head = (ListHead*)(self + 0x11760);
    headp = head;
    value = head->value;
    std_list_deleter_int_erase_listdeleter_listdeleter(&result, self + 0x1175C, &value, &headp);
}
