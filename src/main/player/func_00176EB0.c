#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;

extern void func_00177F60(int* out, Container* self, int* value, int** where);

/* Calls func_00177F60 with the container's +8 value and a pointer to its +4 field. */
void func_00176EB0(Container* self)
{
    int* where;
    int value;
    int result;
    where = &self->unk4;
    value = self->unk8;
    func_00177F60(&result, self, &value, &where);
}
