/*
 * SFOGame/Source/GuiEndGameObjectives: 1 file, 004621A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_4621A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
extern "C" {
extern "C" void GuiEndGameObjectives_IsClass();
extern "C" void GuiObjectives_onMessage();
extern "C" void GuiObjectives_onAdd();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiEndGameObjectives_onAdvanceTime();
extern "C" void GuiEndGameObjectives_GetClassName();
extern "C" void GuiEndGameObjectives_HandleInput();
extern "C" void GuiEndGameObjectives_onWake();
extern void * const D_004E17C0[];
extern char D_004DF5C0[];
void operator_delete(void* allocation);
void cFileMan_dtor(void* self, int flags);
void func_00461DC0(void* self, int flags);
void GuiWidget_dtor(void* self, int flags);
}
struct O4621A0 { void* vtable; };
extern "C" O4621A0* GuiEndGameObjectives_dtor_void_2(O4621A0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E17C0);
        {
            char* q = (char*)self + 0x90;
            if (q) {
                char* p = (char*)self + 0xB0;
                if (p) {
                    cFileMan_dtor((char*)self + 0x194, -1);
                    cFileMan_dtor((char*)self + 0xF8, -1);
                }
                {
                    char* a = (char*)self + 0x90;
                    if (a) {
                        if (a) {
                            if (a)
                                func_00461DC0(a, 0);
                        }
                    }
                }
            }
        }
        if (self) {
            self->vtable = D_004DF5C0;
            GuiWidget_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E17C0[24] = { (void*)0x0, (void*)0x0, (void*)GuiEndGameObjectives_dtor_void_2, (void*)GuiObjectives_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiEndGameObjectives_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiEndGameObjectives_HandleInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiEndGameObjectives_onAdvanceTime, (void*)GuiObjectives_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiEndGameObjectives_GetClassName, (void*)GuiEndGameObjectives_IsClass, (void*)0x0 };
static inline void merge_flush_GuiGameScreen_4621A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_4621A0 */
