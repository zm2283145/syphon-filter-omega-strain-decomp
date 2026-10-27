#include "types.h"

typedef struct { int unk0; int list4; int value8; int countC; } Container;
extern void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, Container* self, int* value, int** list);

/* Clears the count and calls std_list_deleter_voidPtr_erase_listdeleter_listdeleter with the stored value and list head. */
void cEnvMan_Reset(Container* self)
{
    int* list;
    int value;
    int result;
    self->countC = 0;
    list = &self->list4;
    value = self->value8;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&result, self, &value, &list);
}
