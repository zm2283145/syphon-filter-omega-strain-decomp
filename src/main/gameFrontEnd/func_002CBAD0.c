#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
extern "C" {
VSlots67* Gui_GetScreenStack(void);
extern char D_005381F0[];
void Video_BeginFrame(void* p);
}
struct ObjBAD0 { char pad[0x28]; unsigned char a; char pad2[4]; unsigned char b; };
extern "C" void func_002CBAD0(ObjBAD0* o)
{
    if (o->a || o->b) {
        Gui_GetScreenStack()->slot21();
        Video_BeginFrame(D_005381F0);
    }
}