#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
extern "C" {
VSlots67* func_004147A0(void);
extern char D_005381F0[];
void func_0037A9F0(void* p);
}
struct ObjBAD0 { char pad[0x28]; unsigned char a; char pad2[4]; unsigned char b; };
extern "C" void func_002CBAD0(ObjBAD0* o)
{
    if (o->a || o->b) {
        func_004147A0()->slot21();
        func_0037A9F0(D_005381F0);
    }
}