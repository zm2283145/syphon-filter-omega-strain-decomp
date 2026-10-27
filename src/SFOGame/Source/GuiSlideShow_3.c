/*
 * SFOGame/Source/GuiSlideShow: 2 files, 00327890-00327910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_327890 */
#pragma push /* merge_units */
typedef struct { char p0[0x10]; int active; char p14[8]; int arg; } E27890;
typedef struct { char pad[0x4C]; int count; E27890* items; char p54[4]; int cur; } T27890;
extern void GuiSlideShow_SetCurrentSlide(T27890* self, int idx, int arg);
extern void GuiSlideShow_NextSlide(T27890* self, int flag);
static inline E27890* At27890(T27890* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->items[i];
}
void GuiSlideShow_UpdateCurrentSlide(T27890* self)
{
    int i = self->cur;
    E27890* e = At27890(self, i);
    if (e && e->active)
        GuiSlideShow_SetCurrentSlide(self, i, e->arg);
    else
        GuiSlideShow_NextSlide(self, 1);
}
static inline void merge_flush_message_327890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_327890 */

/* merge_units: begin func_00327910 */
#pragma push /* merge_units */
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
extern "C" void GuiWidget_onRender(T27910* self);
extern "C" void GuiSlideShow_onRender(T27910* self)
{
    if (self->h) {
        self->h->obj->Slot10();
        XLib_ClearZBuffer(g_Video);
    }
    GuiWidget_onRender(self);
}
static inline void merge_flush_func_00327910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327910 */
