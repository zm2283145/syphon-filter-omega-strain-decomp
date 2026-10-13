/*
 * main/guiMLTextWidget: 6 files, 0043E0E0-0043E330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043E0E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"
#include "guiMLTextWidget.h"

extern "C" {
extern char D_004C0110[]; /* "guiMLTextWidget.cc" */
void Mem_Free(int pool, void* allocation, char* file, int line);
void* String_Dtor(void* self, short flags);   /* String dtor */
void func_0041F090(void* self);                 /* GuiWidget vtable slot 4 */
}
/* vtable slot 4: base teardown, then destroy and free the text box. */
extern "C" void MLTextWidget_Teardown(MLTextWidget* o)
{
    GuiTextBox* box;
    func_0041F090(o);
    box = o->textBox;
    {
        AllocGuard guard;
        if (box) {
            char* text = box->text;
            if (text)
                String_Dtor(text, 0);
        }
        Mem_Free(0, box, D_004C0110, 0x67);
    }
    o->textBox = 0;

}
#pragma pop /* merge_units */
/* merge_units: end func_0043E0E0 */

/* merge_units: begin func_0043E1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guiMLTextWidget.h"
struct Q0043E1A0 { __int128 q; }; /* colour copied as one quadword */
extern "C" void func_003D0810(GuiTextBox* box, GuiColor* c); /* text box: set colour */
static inline void Set0043E1A0(GuiColor* d, const GuiColor& s) { d->r = s.r; d->g = s.g; d->b = s.b; d->a = s.a; }
extern "C" void MLTextWidget_SetColor(MLTextWidget* w, Q0043E1A0* in)
{
    Q0043E1A0 t = *in;
    Set0043E1A0(&w->color, *(GuiColor*)&t);
    if (w->textBox) func_003D0810(w->textBox, &w->color);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043E1A0 */

/* merge_units: begin func_0043E200 */
#pragma push /* merge_units */
#include "guiMLTextWidget.h"
extern int func_0036A2F0(int font);            /* font line height */
extern int Gui_GetScreenList(void);
extern int func_00418420(int, int);            /* look up font by name (0 = default) */
#pragma push
#pragma opt_common_subs off
void MLTextWidget_SetFont(MLTextWidget* w, const char* fontName)
{
    GuiTextBox* box;
    w->font = (void*)func_00418420(Gui_GetScreenList(), (int)fontName);
    box = w->textBox;
    if (box != 0) box->font = w->font;
    w->maxLines = (int)w->height / func_0036A2F0((int)w->font);
    w->visibleLines = w->maxLines;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0043E200 */

/* merge_units: begin func_0043E290 */
#pragma push /* merge_units */
#include "loose05_types.h"
#include "guiMLTextWidget.h"

/* scroll bar: set position and range */
extern void func_0043BC70(GuiWidget43BEF0* self, unsigned char mode, int value,
                         int lower, int upper);

/* Synchronize the optional scroll bar with the scroll position and line count. */
void MLTextWidget_UpdateScrollBar(MLTextWidget* self) {
    if (self->scrollBar != 0) {
        func_0043BC70(self->scrollBar, 0, self->scrollPos, 0,
                     self->lines.count - self->visibleLines);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043E290 */

/* merge_units: begin func_0043E2E0 */
#pragma push /* merge_units */
#include "guiMLTextWidget.h"
extern void func_0041EFA0(MLTextWidget* s, float x); /* GuiWidget vtable slot 7 */
#if 0 /* merge_units */
extern void func_0043BC70(void* t, int a, int pos, int b, int len);
#endif /* merge_units */
#define func_0043BC70(a0, a1, a2, a3, a4) (func_0043BC70((GuiWidget43BEF0 *)(a0), (unsigned char)(a1), (a2), (a3), (a4))) /* merge_units */

/* vtable slot 7: base behaviour (sets flag 0x8 and forwards to children), then refresh the scroll bar. */
void MLTextWidget_Vt07(MLTextWidget* s, float x) {
    func_0041EFA0(s, x);
    if (s->scrollBar)
        func_0043BC70(s->scrollBar, 0, s->scrollPos, 0, s->lines.count - s->visibleLines);
}
#undef func_0043BC70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E2E0 */

/* merge_units: begin func_0043E330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
struct W_43E330 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
#include "guiMLTextWidget.h"
extern "C" {extern char D_004C0100[]; /* default colour */
extern char D_004AAE00[]; /* scroll bar class type */
extern int D_004976B8; /* scroll bar child id */
void func_0041F150(MLTextWidget* o); /* GuiWidget vtable slot 3 */
void* Mem_Alloc(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void* Gui_GetScreenList(void);
#endif /* merge_units */
#define Gui_GetScreenList() ((void *)Gui_GetScreenList()) /* merge_units */

#if 0 /* merge_units */
void* func_00418420(void* mgr, int name);
#endif /* merge_units */
#define func_00418420(a0, a1) ((void *)func_00418420((int)(a0), (a1))) /* merge_units */

GuiTextBox* func_003D0940(void* p, int x, int y, int w, int h, void* font, char* color); /* text box ctor */
W_43E330* func_0041DC70(void* o, int id); /* find child by id */
#if 0 /* merge_units */
int func_0036A2F0(void* p);
#endif /* merge_units */
#define func_0036A2F0(a0) (func_0036A2F0((int)(a0))) /* merge_units */

void MLTextWidget_Setup(MLTextWidget* o);
}
static inline void* Alloc_43E330(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004C0110, line); }
static inline W_43E330* Cast_43E330(W_43E330* w, void* t) { return w && w->IsA(t) ? w : 0; }

/* vtable slot 3: base setup, default font, text box, line counts, scroll bar child. */
void MLTextWidget_Setup(MLTextWidget* o)
{
    GuiTextBox* box;
    func_0041F150(o);
    o->font = func_00418420(Gui_GetScreenList(), 0);
    box = (GuiTextBox*)Alloc_43E330(sizeof(GuiTextBox), 0x33);
    if (box) box = func_003D0940(box, 0, 0, (int)o->width, (int)o->height, o->font, D_004C0100);
    o->textBox = box;
    o->textBox->unk10 = 0;
    o->textBox->unk58 = 1;
    o->maxLines = (int)o->height / func_0036A2F0(o->font);
    o->visibleLines = o->maxLines;
    o->scrollBar = (struct GuiWidget43BEF0*)Cast_43E330(func_0041DC70(o, D_004976B8), D_004AAE00);
}
#undef Gui_GetScreenList /* merge_units */
#undef func_00418420 /* merge_units */
#undef func_0036A2F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E330 */
