#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
extern "C" {
VSlots67* Gui_GetScreenStack(void);
extern char D_005381F0[];
void func_0037A9F0(void* p);
}
struct ObjBAD0 { char pad[0x28]; unsigned char a; char pad2[4]; unsigned char b; };
extern "C" void func_002CBAD0(ObjBAD0* o)
{
    if (o->a || o->b) {
        Gui_GetScreenStack()->slot21();
        func_0037A9F0(D_005381F0);
    }
}