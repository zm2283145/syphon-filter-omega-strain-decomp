/*
 * SFOGame/Source/GuiMissionList: 1 file, 002AAC60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AAC60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x5C]; char m60[0xAC]; char m10C[4]; } O2AAC60;
extern void GuiMissionList_GetClassName();
extern void GuiMissionList_IsClass();
extern void GuiMissionList_onElementRender();
extern void GuiMissionList_onRowRender();
extern void GuiMissionList_onSleep();
extern void GuiMissionList_Wake();
extern void func_002AC300();
extern void GuiMissionList_onAdvanceTime();
extern void GuiMissionList_onAdd();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onMessage();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void GuiArrayWidget_onElementLoseFocus();
extern void GuiArrayWidget_onColumnRender();
extern void GuiArrayWidget_onRender();
extern void GuiArrayWidget_onInput();
extern void GuiArrayWidget_SetSize();
extern void GuiArrayWidget_onLoseFocus();
extern void GuiArrayWidget_onGainFocus();
extern void * const D_004DDB80[];
extern char D_004E0D20[];
extern void std_vector_deleter_SelectElem_dtor_void_2(void* p, int f);
extern void cArray_int_dtor(void* p, int f);
extern void GuiWidget_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void C2AAC60(void* p) { if (p) std_vector_deleter_SelectElem_dtor_void_2(p, 0); }
static inline void B2AAC60(void* p) { if (p) C2AAC60(p); }
static inline void A2AAC60(void* p) { if (p) B2AAC60(p); }
static inline void Base2AAC60(O2AAC60* p)
{
    if (p) {
        p->vt = D_004E0D20;
        cArray_int_dtor(p->m60, -1);
        GuiWidget_dtor(p, 0);
    }
}
O2AAC60* GuiMissionList_dtor(O2AAC60* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DDB80);
        A2AAC60(self->m10C);
        Base2AAC60(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DDB80[30] = { (void*)0x0, (void*)0x0, (void*)GuiMissionList_dtor, (void*)GuiMissionList_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiMissionList_Wake, (void*)GuiMissionList_onSleep, (void*)GuiArrayWidget_onGainFocus, (void*)GuiArrayWidget_onLoseFocus, (void*)GuiArrayWidget_onInput, (void*)GuiArrayWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiMissionList_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMissionList_GetClassName, (void*)GuiMissionList_IsClass, (void*)GuiArrayWidget_SetSize, (void*)GuiArrayWidget_onColumnRender, (void*)GuiMissionList_onRowRender, (void*)GuiMissionList_onElementRender, (void*)func_002AC300, (void*)GuiArrayWidget_onElementLoseFocus, (void*)0x0 };
static inline void merge_flush_func_002AAC60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AAC60 */
