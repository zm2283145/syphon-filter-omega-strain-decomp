#pragma cplusplus on
#include "vslot_pad.h"
class C27910 {
public:
    VPAD8(p) VPAD2(q)
    virtual void Slot10();
};
struct H27910 { char pad[0x44]; C27910* obj; };
struct T27910 { char pad[0x5C]; H27910* h; };
extern "C" char g_Video[];
extern "C" void XLib_ClearZBuffer(char* p);
extern "C" void GuiWidget_Draw(T27910* self);
extern "C" void GuiSlideShow_Draw(T27910* self)
{
    if (self->h) {
        self->h->obj->Slot10();
        XLib_ClearZBuffer(g_Video);
    }
    GuiWidget_Draw(self);
}