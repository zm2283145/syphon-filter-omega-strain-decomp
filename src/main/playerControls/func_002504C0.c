#include "types.h"
unsigned int D_004A7540[2] = { 0x0, 0x0 };
typedef struct { char pad[0x60]; float unk60; } Obj002504C0;
/* Store half of a global float into field 0x60 of the second argument. */
void cPlayerControls_InitializeCamera(int unused, Obj002504C0* obj)
{
    obj->unk60 = 0.5f * (*(float*)D_004A7540);
}
