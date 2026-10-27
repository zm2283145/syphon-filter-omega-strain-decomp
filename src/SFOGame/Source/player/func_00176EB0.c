#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;

extern void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(int* out, Container* self, int* value, int** where);

/* Calls std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter with the container's +8 value and a pointer to its +4 field. */
void cLList_cSafePtr_cGOBJ_Clear(Container* self)
{
    int* where;
    int value;
    int result;
    where = &self->unk4;
    value = self->unk8;
    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&result, self, &value, &where);
}
