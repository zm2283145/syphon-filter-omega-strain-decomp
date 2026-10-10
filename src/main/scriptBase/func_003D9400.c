#include "types.h"
typedef struct { char pad[8]; char** types; } TypeTable003D9400;
extern TypeTable003D9400* D_00554F28;
extern void PtrVec_PushBack_1C1080(void* list, int* value);
/* Add an accepted interface to a script type. */
void ScriptType_AddAccepted(int type, int iface)
{
    int i = type - 100;
    PtrVec_PushBack_1C1080(D_00554F28->types[i] + 0x24, &iface);
}
