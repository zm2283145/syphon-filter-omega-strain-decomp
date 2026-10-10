#include "types.h"

typedef struct { int unk0; int list4; int value8; int countC; } Container;
extern void ObjectList_EraseRange(int* out, Container* self, int* value, int** list);

/* Clears the count and calls ObjectList_EraseRange with the stored value and list head. */
void func_001784B0(Container* self)
{
    int* list;
    int value;
    int result;
    self->countC = 0;
    list = &self->list4;
    value = self->value8;
    ObjectList_EraseRange(&result, self, &value, &list);
}
