#include "types.h"
extern float D_004A7540;
typedef struct { char pad[0x60]; float unk60; } Obj002504C0;
/* Store half of a global float into field 0x60 of the second argument. */
void func_002504C0(int unused, Obj002504C0* obj)
{
    obj->unk60 = 0.5f * D_004A7540;
}
