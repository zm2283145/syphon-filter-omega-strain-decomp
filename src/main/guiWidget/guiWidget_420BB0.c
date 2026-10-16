/*
 * main/guiWidget: 4 files, 00420BB0-00420C90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00420BB0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiButtonWidget")) returned 0. */
int func_00420BB0(void) {
    return strcmp(((int*)"GuiButtonWidget")) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00420BB0 */

/* merge_units: begin func_00420BE0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GuiTextWidget_OnWake();                                  

void GuiButtonWidget_OnWake(int arg0) {
    int temp_a0;

    GuiTextWidget_OnWake();
    temp_a0 = F_(arg0, 0x78, int);
    if (temp_a0 != NULL) {
        F_(temp_a0, 0x58, signed char) = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00420BE0 */

/* merge_units: begin func_00420C20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Handler: only the slots used here are named (vtable offset in comments). */
struct Handler {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A();
    virtual void Method34(); /* +0x34 */
};

typedef struct Widget { char pad[0x44]; Handler* handler; /* +0x44 */ } Widget;

extern "C" void GuiWidget_SendEventUp(Widget* self, int a, int b, int c);
extern "C" int GuiWidget_OnEvent(Widget* self, Widget* sender, unsigned short code);

/* Event handler: on event 0x16 from itself runs GuiWidget_SendEventUp and the handler's virtual +0x34; else defers to GuiWidget_OnEvent. */
extern "C" int GuiButtonWidget_OnEvent(Widget* self, Widget* sender, unsigned short code)
{
    if (code == 0x16 && sender == self) {
        GuiWidget_SendEventUp(self, 0x10, 1, 0);
        self->handler->Method34();
        return 1;
    }
    return GuiWidget_OnEvent(self, sender, code);
}
#pragma pop /* merge_units */
/* merge_units: end func_00420C20 */

/* merge_units: begin func_00420C90 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned short type; unsigned short f2; short p4; unsigned short f6; unsigned short f8; } Ev420C90;
extern "C" void GuiWidget_SendEvent(void* w, void* src, int kind, int a, int b);
extern "C" int GuiButtonWidget_OnInput(void* w, Ev420C90* e)
{
    bool ok = e->type == 1 && e->f2 == 0 && e->f8 == 0x40 && e->f6 == 0;
    if (ok) {
        if (e->f6 == 0) GuiWidget_SendEvent(w, w, 0x16, 0, 0);
        else GuiWidget_SendEvent(w, w, 0x17, 0, 0);
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00420C90 */
