/*
 * Libs/SFOLib/Source/guiScrollBarWidget: 1 file, 0043C030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GenInfoObject_43C030 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x4C]; char m[4]; };
extern "C" {
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern "C" void GuiBitmapWidget_GetClassName();
extern "C" void GuiBitmapWidget_IsClass();
extern "C" void GuiBitmapWidget_onRender();
extern "C" void GuiBitmapWidget_onRemove();
extern "C" void GuiBitmapWidget_onSleep();
extern "C" void GuiBitmapWidget_onWake();
extern void * const D_004E0FC0[];
void String_Dtor(void* m, short f);
void GuiWidget_dtor(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_001379A0* GuiBitmapWidget_dtor(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E0FC0);
        if (self->m) String_Dtor(self->m, 0);
        GuiWidget_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E0FC0[24] = { (void*)0x0, (void*)0x0, (void*)GuiBitmapWidget_dtor, (void*)GuiWidget_onAdd, (void*)GuiBitmapWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiBitmapWidget_onWake, (void*)GuiBitmapWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiBitmapWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiBitmapWidget_GetClassName, (void*)GuiBitmapWidget_IsClass, (void*)0x0 };
static inline void merge_flush_GenInfoObject_43C030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GenInfoObject_43C030 */
