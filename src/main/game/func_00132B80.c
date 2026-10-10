#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;

extern void ObjectList_EraseRange(int* out, Container* self, int* value, int** where);

/* Calls ObjectList_EraseRange with the container's +8 value and a pointer to its +4 field. */
void func_00132B80(Container* self)
{
    int* where;
    int value;
    int result;
    where = &self->unk4;
    value = self->unk8;
    ObjectList_EraseRange(&result, self, &value, &where);
}
