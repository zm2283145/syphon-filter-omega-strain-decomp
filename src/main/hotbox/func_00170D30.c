#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;
typedef struct { char pad[0x28]; Container list; } Obj170;

extern Container D_004EE688;
extern void ObjectList_EraseRange(int* out, Container* self, int* value, int** where);

/* Calls ObjectList_EraseRange for the global container and for the object's container at +0x28. */
void func_00170D30(Obj170* self)
{
    int* where2;
    int value2;
    int result2;
    int* where;
    int value;
    int result;
    where = &D_004EE688.unk4;
    value = D_004EE688.unk8;
    ObjectList_EraseRange(&result, &D_004EE688, &value, &where);
    where2 = &self->list.unk4;
    value2 = self->list.unk8;
    ObjectList_EraseRange(&result2, &self->list, &value2, &where2);
}
