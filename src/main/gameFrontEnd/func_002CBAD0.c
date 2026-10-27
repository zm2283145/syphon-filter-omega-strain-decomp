#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
extern "C" {
VSlots67* Gui_Canvas(void);
extern char g_Video[];
void XLib_NextFrame(void* p);
}
struct ObjBAD0 { char pad[0x28]; unsigned char a; char pad2[4]; unsigned char b; };
extern "C" void cGameFrontEnd_Render(ObjBAD0* o)
{
    if (o->a || o->b) {
        Gui_Canvas()->slot21();
        XLib_NextFrame(g_Video);
    }
}