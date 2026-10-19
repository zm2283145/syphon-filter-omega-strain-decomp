/*
 * main/guiManager: 2 files, 00419FC0-0041A060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "string_int_pair_copy_ctor.h"

/* Copy constructor of a string/int pair. */
DEFINE_STRING_INT_PAIR_COPY_CTOR(func_00419FC0)
#pragma pop /* merge_units */
/* merge_units: end func_00419FC0 */

/* merge_units: begin func_0041A060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void GuiTextEditWidget_GetClassName();
extern "C" void GuiTextEditWidget_IsType();
extern "C" void GuiTextEditWidget_Draw();
extern "C" void GuiTextEditWidget_Update();
extern "C" void func_0041AA10();
extern "C" void GuiTextEditWidget_OnInput();
extern "C" void GuiTextEditWidget_Load();
extern "C" void GuiTextEditWidget_OnWake();
extern "C" void GuiTextWidget_OnSleep();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern void * const D_004E0A40[];
void* GuiTextWidget_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* GuiTextEditWidget_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0A40);
        GuiTextWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0A40[24] = { (void*)0x0, (void*)0x0, (void*)GuiTextEditWidget_dtor, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiTextEditWidget_OnWake, (void*)GuiTextWidget_OnSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiTextEditWidget_OnInput, (void*)GuiTextEditWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiTextEditWidget_Update, (void*)GuiWidget_OnEvent, (void*)GuiTextEditWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiTextEditWidget_GetClassName, (void*)GuiTextEditWidget_IsType, (void*)func_0041AA10 };
#pragma pop /* merge_units */
/* merge_units: end func_0041A060 */
