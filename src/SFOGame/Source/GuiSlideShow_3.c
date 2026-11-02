/*
 * SFOGame/Source/GuiSlideShow: 3 files, 00327890-00327960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_327890 */
#pragma push /* merge_units */
typedef struct { char p0[0x10]; int active; char p14[8]; int arg; } E27890;
typedef struct { char pad[0x4C]; int count; E27890* items; char p54[4]; int cur; } T27890;
extern void GuiSlideShow_SetCurrentSlide(T27890* self, int idx, int arg);
#if 0 /* merge_units */
extern void GuiSlideShow_NextSlide(T27890* self, int flag);
#endif /* merge_units */
int GuiSlideShow_NextSlide(void*, int); /* merge_units */
#define GuiSlideShow_NextSlide(a0, a1) ((void)GuiSlideShow_NextSlide((void *)(a0), (a1))) /* merge_units */

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
#undef GuiSlideShow_NextSlide /* merge_units */
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

/* merge_units: begin func_00327960 */
#pragma push /* merge_units */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma cplusplus on
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E27960;
typedef struct { unsigned short type; unsigned short mod; unsigned short p4; unsigned short x6; unsigned short key; } Ev27960;
typedef struct { char pad[0x4C]; int count; E27960* items; char p54[0x18]; char s6C[0xC]; char s78[0xC]; int x84; } T27960;
#if 0 /* merge_units */
extern "C" int GuiSlideShow_NextSlide(T27960* self, int flag);
#endif /* merge_units */
#define GuiSlideShow_NextSlide(a0, a1) (GuiSlideShow_NextSlide((void *)(a0), (a1))) /* merge_units */

extern "C" int Gui_Canvas(void);
extern "C" int Gui_Manager(void);
extern "C" void GuiWidget_SendMessage(T27960* self, int v, int f, int a, int b);
extern "C" int std_basic_string_char_char_traits_char_c_str(void* s);
extern "C" int GuiManager_OpenGui(int a, int b, int c);
extern "C" void GuiCanvas_Transition(int a, T27960* self, int b);

static inline int Total(T27960* self)
{
    int total = 0;
    int i;
    int j;
    E27960* d;
    int n;
    i = 0;
    if (0 < *(volatile int*)&self->count) {
        d = self->items;
        do {
            n = d[i].n;
            for (j = 0; j < n; j++) total++;
            i++;
        } while (i < *(volatile int*)&self->count);
    }
    return total;
}

static inline bool IsKey(Ev27960* e, unsigned short key)
{
    return e->type == 1 && e->mod == 0 && e->key == key && e->x6 == 0;
}

extern "C" int GuiSlideShow_onInput(T27960* self, Ev27960* e)
{
    if (IsKey(e, 0x2000)) {
        if (Total(self) > 1 && GuiSlideShow_NextSlide(self, 1))
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
        return 1;
    }
    if (IsKey(e, 0x8000)) {
        if (Total(self) > 1 && GuiSlideShow_NextSlide(self, 0))
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
        return 1;
    }
    if (IsKey(e, 0x10)) {
        int b = std_basic_string_char_char_traits_char_c_str(self->s78);
        int a = std_basic_string_char_char_traits_char_c_str(self->s6C);
        int r = GuiManager_OpenGui(Gui_Manager(), a, b);
        if (r) {
            GuiWidget_SendMessage(self, r, 0x3000, self->x84, 0);
            GuiCanvas_Transition(Gui_Canvas(), self, r);
        }
        return 1;
    }
    return 0;
}
#undef GuiSlideShow_NextSlide /* merge_units */
static inline void merge_flush_func_00327960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327960 */
