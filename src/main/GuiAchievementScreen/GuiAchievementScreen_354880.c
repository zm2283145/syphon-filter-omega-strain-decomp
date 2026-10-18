/*
 * main/GuiAchievementScreen: 2 files, 00354880-003548B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00354880 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00354880(void* self) {
    return self;
}

Rel* func_00354890(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00354880 */

/* merge_units: begin func_003548B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: payload at +0xB0 (two members), strings at +0x78/+0x6C, base GuiWidget_Destroy. */
extern "C" {
extern "C" void GuiPersonnelMenu_GetClassName();
extern "C" void GuiPersonnelMenu_IsType();
extern "C" void func_00349ED0();
extern "C" void func_0034D2C0();
extern "C" void GuiPersonnelMenu_Back();
extern "C" void GuiPersonnelMenu_HandleInput();
extern "C" void GuiPersonnelMenu_Fill();
extern "C" void GuiPersonnelMenu_Sleep();
extern "C" void GuiPersonnelMenu_Wake();
extern "C" void GuiPersonnelMenu_Init();
extern "C" void GuiPersonnelScreen_HandleEvent();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DF020[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void FileMan_Release(void* self, int flags);
void* String_Dtor(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
struct O3548B0 { void* vtable; };
extern "C" O3548B0* func_003548B0(O3548B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF020);
        char* p = (char*)self + 0xB0;
        if (p) {
            FileMan_Release((char*)self + 0x194, -1);
            FileMan_Release((char*)self + 0xF8, -1);
        }
        char* a = (char*)self + 0x78;
        if (a)
            String_Dtor(a, 0);
        char* b = (char*)self + 0x6C;
        if (b)
            String_Dtor(b, 0);
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF020[28] = { (void*)0x0, (void*)0x0, (void*)func_003548B0, (void*)GuiPersonnelMenu_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiPersonnelMenu_Wake, (void*)GuiPersonnelMenu_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiPersonnelMenu_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiPersonnelScreen_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiPersonnelMenu_GetClassName, (void*)GuiPersonnelMenu_IsType, (void*)GuiPersonnelMenu_Fill, (void*)func_00349ED0, (void*)func_0034D2C0, (void*)GuiPersonnelMenu_Back, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_003548B0 */
