#include "types.h"

typedef struct { int unk0; int count; void** data; } PtrVector;
extern void* Script_ObjectToId(void* object);
extern void func_00174B60(PtrVector* vec, void** pos, int n, void** value);

/* Appends a duplicate handle of object to the group's pointer vector. */
void Group_AddObjectDup(PtrVector* group, void* object)
{
    void* dup = Script_ObjectToId(object);
    func_00174B60(group, group->data + group->count, 1, &dup);
}
