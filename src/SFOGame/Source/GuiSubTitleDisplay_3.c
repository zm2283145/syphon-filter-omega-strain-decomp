/*
 * SFOGame/Source/GuiSubTitleDisplay: 1 file, 00458280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00458280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                         
int std_vector_float_dtor(...);                         
int GuiWidget_dtor(...);                         
int func_004583B0(...);                         
int GuiSubTitleDisplay_DestroyTextLines(...);                            
int operator_delete(...);                          
extern char D_004C1EB0;
extern "C" void GuiSubTitleDisplay_IsClass();
extern "C" void GuiWidget_onInput();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern "C" void GuiSubTitleDisplay_GetClassName();
extern "C" void GuiSubTitleDisplay_onRender();
extern "C" void GuiSubTitleDisplay_onAdvanceTime();
extern "C" void GuiSubTitleDisplay_onSleep();
extern "C" void GuiSubTitleDisplay_onWake();
extern void * const D_004E1560[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * GuiSubTitleDisplay_dtor(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E1560));
        temp_s2 = F_(arg0, 0x50, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, temp_s2, &D_004C1EB0, 0x14A);
            }
        }
        GuiSubTitleDisplay_DestroyTextLines(arg0);
        temp_a0 = arg0 + 0x68;
        if (temp_a0 != NULL) {
            std_vector_float_dtor(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0x58;
        if (temp_a0_2 != NULL) {
            func_004583B0(temp_a0_2, -1);
        }
        GuiWidget_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1560[24] = { (void*)0x0, (void*)0x0, (void*)GuiSubTitleDisplay_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiSubTitleDisplay_onWake, (void*)GuiSubTitleDisplay_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiSubTitleDisplay_onRender, (void*)GuiWidget_onAction, (void*)GuiSubTitleDisplay_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiSubTitleDisplay_GetClassName, (void*)GuiSubTitleDisplay_IsClass, (void*)0x0 };
static inline void merge_flush_func_00458280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00458280 */
