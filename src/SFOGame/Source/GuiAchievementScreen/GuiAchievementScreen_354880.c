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

void* details_compressed_pair_imp_cAllocator_tAchievementInfo_int_1_first(void* self) {
    return self;
}

Rel* std_vector_imp_tAchievementInfo_ctor(Rel* r) {
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

/* Deleting destructor: payload at +0xB0 (two members), strings at +0x78/+0x6C, base GuiWidget_dtor. */
extern "C" {
extern "C" void GuiPersonnelMenu_GetClassName();
extern "C" void GuiPersonnelMenu_IsClass();
extern "C" void GuiPersonnelScreen_ItemGainFocus();
extern "C" void GuiPersonnelScreen_ItemAction();
extern "C" void GuiPersonnelMenu_PreviousScreen();
extern "C" void GuiPersonnelMenu_onInput();
extern "C" void GuiPersonnelMenu_PopulateList();
extern "C" void GuiPersonnelMenu_onSleep();
extern "C" void GuiPersonnelMenu_onWake();
extern "C" void GuiPersonnelMenu_onAdd();
extern "C" void GuiPersonnelScreen_onMessage();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern void * const D_004DF020[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void cFileMan_dtor(void* self, int flags);
void* String_Dtor(void* self, short deleteFlag);
void* GuiWidget_dtor(void* self, short deleteFlag);
}
struct O3548B0 { void* vtable; };
extern "C" O3548B0* GuiPersonnelMenu_dtor(O3548B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF020);
        char* p = (char*)self + 0xB0;
        if (p) {
            cFileMan_dtor((char*)self + 0x194, -1);
            cFileMan_dtor((char*)self + 0xF8, -1);
        }
        char* a = (char*)self + 0x78;
        if (a)
            String_Dtor(a, 0);
        char* b = (char*)self + 0x6C;
        if (b)
            String_Dtor(b, 0);
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF020[28] = { (void*)0x0, (void*)0x0, (void*)GuiPersonnelMenu_dtor, (void*)GuiPersonnelMenu_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiPersonnelMenu_onWake, (void*)GuiPersonnelMenu_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiPersonnelMenu_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiPersonnelScreen_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiPersonnelMenu_GetClassName, (void*)GuiPersonnelMenu_IsClass, (void*)GuiPersonnelMenu_PopulateList, (void*)GuiPersonnelScreen_ItemGainFocus, (void*)GuiPersonnelScreen_ItemAction, (void*)GuiPersonnelMenu_PreviousScreen, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_003548B0 */
