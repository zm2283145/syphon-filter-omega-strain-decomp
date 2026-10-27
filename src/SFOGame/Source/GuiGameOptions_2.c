/*
 * SFOGame/Source/GuiGameOptions: 1 file, 002995D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002995D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M2995D0;
typedef struct { void* vt; char pad[0xDC]; M2995D0 mE0; char pad2[0x270 - 0xE0 - sizeof(M2995D0)]; M2995D0 m270; } O2995D0;
extern void GuiGameOptions_GetClassName();
extern void GuiGameOptions_IsClass();
extern void GuiGameOptions_onInput();
extern void GuiGameOptions_onMessage();
extern void GuiGameOptions_OnSaveDone();
extern void GuiGameOptions_onSleep();
extern void GuiGameOptions_onWake();
extern void GuiGameOptions_onAdd();
extern void GuiGameOptions_onAdvanceTime();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onRender();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void * const D_004DD580[];
extern char D_004E1220[];
extern void cFileMan_dtor(void* p, int f);
extern void GuiWidget_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void M2995D0_dtor(M2995D0* m)
{
    if (m) {
        cFileMan_dtor(m->mE4, -1);
        cFileMan_dtor(m->m48, -1);
    }
}
static inline void Base2995D0(O2995D0* p)
{
    if (p) {
        p->vt = D_004E1220;
        GuiWidget_dtor(p, 0);
    }
}
O2995D0* GuiGameOptions_dtor(O2995D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DD580);
        M2995D0_dtor(&self->m270);
        M2995D0_dtor(&self->mE0);
        Base2995D0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD580[24] = { (void*)0x0, (void*)0x0, (void*)GuiGameOptions_dtor, (void*)GuiGameOptions_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiGameOptions_onWake, (void*)GuiGameOptions_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiGameOptions_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiGameOptions_onAdvanceTime, (void*)GuiGameOptions_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiGameOptions_GetClassName, (void*)GuiGameOptions_IsClass, (void*)GuiGameOptions_OnSaveDone };
static inline void merge_flush_func_002995D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002995D0 */
