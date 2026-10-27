/*
 * SFOGame/Source/GuiMessageBox: 5 files, 002A7AC0-002A7DD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A7AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AB618[] = "GuiMessageBox";   /* "GuiMessageBox" */

/* Class name getter: "GuiMessageBox". */
char* GuiMessageBox_GetClassName(void) {
    return D_004AB618;
}
static inline void merge_flush_func_002A7AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A7AC0 */

/* merge_units: begin func_002A7AD0 */
#pragma push /* merge_units */
extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiMessageBox" yields null. */
int GuiMessageBox_IsClass(void) {
    return strcmp("GuiMessageBox") == 0;
}
static inline void merge_flush_func_002A7AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A7AD0 */

/* merge_units: begin func_002A7B00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
class M2A7B00 { public: VPAD16(a) VPAD8(b) virtual void Remove(void* o); };
struct O2A7B00 { char p0[0x10]; int sel; char p14[0x34]; int mode; int cur; int f50; };
extern "C" {
extern void* D_004FFC04;
int ValidateWidget_GuiWidgetP(int v);
void GuiWidget_SendMessage(O2A7B00* o, int a, int b, int c, int d);
int cGameFrontEnd_PopMessageBox(void* g, int sel);
M2A7B00* Gui_Canvas(void);
}
/* Input handler: on the confirm button event, refreshes the current item and closes when unchanged. */
extern "C" int GuiMessageBox_onInput(O2A7B00* o, char* ev)
{
    int v;
    v = F_(ev, 0x0, unsigned short) == 1;
    if (v != 0) {
        v = F_(ev, 0x2, unsigned short) == 0;
    }
    v = v ? F_(ev, 0x8, unsigned short) == 0x10 : v;
    if (v != 0) {
        v = F_(ev, 0x6, unsigned short) == 0;
    }
    if (v != 0) {
        if (o->mode != 0 && o->mode != 1) {
            int old;
            o->cur = ValidateWidget_GuiWidgetP(o->cur);
            old = o->sel;
            GuiWidget_SendMessage(o, o->cur, o->mode == 2 ? 0x1A : 0x1B, o->f50, 0);
            if (!cGameFrontEnd_PopMessageBox(D_004FFC04, old) && old == o->sel) {
                o->sel = -1;
                Gui_Canvas()->Remove(o);
            }
        }
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_002A7B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A7B00 */

/* merge_units: begin func_002A7C20 */
#pragma push /* merge_units */
#pragma cplusplus on
class M2A7C20 { public: VPAD16(a) VPAD8(b) virtual void Remove(void* o); };
struct E2A7C20 { int f0; int f4; void* item; void* btnA; void* btnB; };
struct O2A7C20 { char p0[0x10]; int sel; char p14[0x34]; int mode; int cur; int f50; int idx; E2A7C20 entries[1]; };
extern "C" {
#if 0 /* merge_units */
void GuiWidget_SendMessage(O2A7C20* o, int a, int b, int c, int d);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((O2A7B00 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

int std_basic_string_char_char_traits_char_c_str(void* p);
int GuiWidget_onMessage(O2A7C20* o, void* sender, unsigned short msg);
#if 0 /* merge_units */
M2A7C20* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((M2A7C20 *)Gui_Canvas()) /* merge_units */

}

extern "C" int GuiMessageBox_onMessage(O2A7C20* o, void* sender, unsigned short msg)
{
    if (msg == 2) {
        E2A7C20* e; int old; old = o->sel; e = &o->entries[o->idx];
        o->cur = ValidateWidget_GuiWidgetP(o->cur);
        if (o->mode == 6) {
            if (sender == e->btnA || sender == e->item) {
                int v = 0;
                if (e->item != 0) {
                    v = std_basic_string_char_char_traits_char_c_str((char*)e->item + 0x48);
                }
                GuiWidget_SendMessage(o, o->cur, 0x1A, o->f50, v);
            } else if (sender == e->btnB) {
                GuiWidget_SendMessage(o, o->cur, 0x1B, o->f50, 0);
            }
        } else {
            if (sender == e->btnA) {
                GuiWidget_SendMessage(o, o->cur, 0x1A, o->f50, 0);
            } else if (sender == e->btnB) {
                GuiWidget_SendMessage(o, o->cur, 0x1B, o->f50, 0);
            }
        }
        if (!cGameFrontEnd_PopMessageBox(D_004FFC04, old) && old == o->sel) {
            o->sel = -1;
            Gui_Canvas()->Remove(o);
        }
        return 1;
    }
    return GuiWidget_onMessage(o, sender, msg);
}
#undef GuiWidget_SendMessage /* merge_units */
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_002A7C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A7C20 */

/* merge_units: begin func_002A7DD0 */
#pragma push /* merge_units */
#include "loose02_types.h"

/* Sets the screen id of the referenced screen, if any. */
void GuiMessageBox_SetEditBufferSize(ScreenRefHolder* self, int screenId) {
    GuiScreen* screen = self->screen;

    if (screen != 0) {
        screen->screenId = screenId;
    }
}
static inline void merge_flush_func_002A7DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A7DD0 */
